#ifndef HOPMON_GFX_DEVICE_H
#define HOPMON_GFX_DEVICE_H

#include <cstdint>
#include <vector>
#include <string>

struct Vec3 {
    float x = 0.0f, y = 0.0f, z = 0.0f;
    Vec3() = default;
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
};

struct Vec4 {
    float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f;
    Vec4() = default;
    Vec4(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
};

struct Mat4 {
    float m[16];
    Mat4();
    static Mat4 Identity();
    static Mat4 Translation(float tx, float ty, float tz);
    static Mat4 RotationY(float radians);
    static Mat4 RotationX(float radians);
    static Mat4 RotationZ(float radians);
    static Mat4 Scaling(float sx, float sy, float sz);
    static Mat4 Perspective(float fovRadians, float aspect, float zNear, float zFar);
    static Mat4 Ortho(float left, float right, float bottom, float top, float zNear, float zFar);
    static Mat4 LookAt(const Vec3& eye, const Vec3& target, const Vec3& up);
    static Mat4 Multiply(const Mat4& a, const Mat4& b);
};

struct Vertex {
    float x, y, z;
    float nx, ny, nz;
    float u, v;
    uint32_t color; // 0xAARRGGBB
};

class GfxDevice {
public:
    static GfxDevice& Instance();

    bool Init(int width, int height);
    void Resize(int width, int height);

    void BeginScene(float r = 0.02f, float g = 0.03f, float b = 0.08f);
    void EndScene();

    void SetTransformWorld(const Mat4& m);
    void SetTransformView(const Mat4& m);
    void SetTransformProjection(const Mat4& m);

    void SetLightDirection(const Vec3& dir);
    void SetLightDiffuse(const Vec4& color);
    void SetAmbientLight(const Vec4& color);
    void SetMaterialDiffuse(const Vec4& color);

    void SetTexture(uint32_t textureId);
    void SetAlphaTest(bool enable, float ref = 0.5f);
    void SetZBuffer(bool testEnable, bool writeEnable);
    void SetAlphaBlend(bool enable);

    uint32_t CreateMeshBuffer(const std::vector<Vertex>& vertices, const std::vector<uint16_t>& indices);
    void UpdateMeshBuffer(uint32_t meshId, const std::vector<Vertex>& vertices);
    void DrawMesh(uint32_t meshId);
    void DeleteMeshBuffer(uint32_t meshId);

    // 2D HUD rendering
    void Begin2D();
    void End2D();
    void DrawRect2D(float x, float y, float w, float h, const Vec4& color);
    void DrawSprite2D(uint32_t textureId, float x, float y, float w, float h, float u0 = 0.0f, float v0 = 0.0f, float u1 = 1.0f, float v1 = 1.0f, const Vec4& color = {1,1,1,1});

    uint32_t LoadTexture(const std::string& filepath);
    uint32_t CreateTexture(int width, int height, const uint8_t* rgbaPixels);

    int GetWidth() const { return width_; }
    int GetHeight() const { return height_; }

private:
    GfxDevice();
    ~GfxDevice();

    int width_ = 640;
    int height_ = 480;

    Mat4 world_;
    Mat4 view_;
    Mat4 proj_;
    Mat4 ortho_;

    Vec3 lightDir_ = {0.3f, -0.8f, 0.5f};
    Vec4 lightDiffuse_ = {1.0f, 0.95f, 0.9f, 1.0f};
    Vec4 ambientLight_ = {0.35f, 0.35f, 0.45f, 1.0f};
    Vec4 materialDiffuse_ = {1.0f, 1.0f, 1.0f, 1.0f};

    uint32_t currentTexture_ = 0;
    bool alphaTest_ = false;
    float alphaRef_ = 0.5f;

    uint32_t shaderProgram_ = 0;
    uint32_t whiteTexture_ = 0;

    uint32_t quadVao_ = 0;
    uint32_t quadVbo_ = 0;

    struct MeshEntry {
        uint32_t vao = 0;
        uint32_t vbo = 0;
        uint32_t ibo = 0;
        uint32_t indexCount = 0;
    };
    std::vector<MeshEntry> meshes_;
};

#endif // HOPMON_GFX_DEVICE_H
