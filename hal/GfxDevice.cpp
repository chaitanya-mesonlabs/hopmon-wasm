#include "GfxDevice.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <cstring>

#if defined(__EMSCRIPTEN__)
#include <GLES3/gl3.h>
#include <emscripten.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#endif

Mat4::Mat4() {
    for (int i = 0; i < 16; ++i) m[i] = (i % 5 == 0) ? 1.0f : 0.0f;
}

Mat4 Mat4::Identity() { return Mat4(); }

Mat4 Mat4::Translation(float tx, float ty, float tz) {
    Mat4 res = Identity();
    res.m[12] = tx; res.m[13] = ty; res.m[14] = tz;
    return res;
}

Mat4 Mat4::Scaling(float sx, float sy, float sz) {
    Mat4 res = Identity();
    res.m[0] = sx; res.m[5] = sy; res.m[10] = sz;
    return res;
}

Mat4 Mat4::RotationY(float rad) {
    Mat4 res = Identity();
    float c = cosf(rad), s = sinf(rad);
    res.m[0] = c; res.m[2] = -s; res.m[8] = s; res.m[10] = c;
    return res;
}

Mat4 Mat4::RotationX(float rad) {
    Mat4 res = Identity();
    float c = cosf(rad), s = sinf(rad);
    res.m[5] = c; res.m[6] = s; res.m[9] = -s; res.m[10] = c;
    return res;
}

Mat4 Mat4::RotationZ(float rad) {
    Mat4 res = Identity();
    float c = cosf(rad), s = sinf(rad);
    res.m[0] = c; res.m[1] = s; res.m[4] = -s; res.m[5] = c;
    return res;
}

Mat4 Mat4::Multiply(const Mat4& a, const Mat4& b) {
    Mat4 res;
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            float sum = 0.0f;
            for (int k = 0; k < 4; ++k) sum += a.m[row * 4 + k] * b.m[k * 4 + col];
            res.m[row * 4 + col] = sum;
        }
    }
    return res;
}

Mat4 Mat4::Perspective(float fovRad, float aspect, float zNear, float zFar) {
    Mat4 res;
    std::memset(res.m, 0, sizeof(res.m));
    float tanHalfFov = tanf(fovRad * 0.5f);
    res.m[0] = 1.0f / (aspect * tanHalfFov);
    res.m[5] = 1.0f / tanHalfFov;
    res.m[10] = -(zFar + zNear) / (zFar - zNear);
    res.m[11] = -1.0f;
    res.m[14] = -(2.0f * zFar * zNear) / (zFar - zNear);
    return res;
}

Mat4 Mat4::Ortho(float left, float right, float bottom, float top, float zNear, float zFar) {
    Mat4 res;
    std::memset(res.m, 0, sizeof(res.m));
    res.m[0] = 2.0f / (right - left);
    res.m[5] = 2.0f / (top - bottom);
    res.m[10] = -2.0f / (zFar - zNear);
    res.m[12] = -(right + left) / (right - left);
    res.m[13] = -(top + bottom) / (top - bottom);
    res.m[14] = -(zFar + zNear) / (zFar - zNear);
    res.m[15] = 1.0f;
    return res;
}

Mat4 Mat4::LookAt(const Vec3& eye, const Vec3& target, const Vec3& up) {
    Vec3 f = { target.x - eye.x, target.y - eye.y, target.z - eye.z };
    float fLen = sqrtf(f.x*f.x + f.y*f.y + f.z*f.z);
    if (fLen > 0.0001f) { f.x /= fLen; f.y /= fLen; f.z /= fLen; }

    Vec3 s = { f.y * up.z - f.z * up.y, f.z * up.x - f.x * up.z, f.x * up.y - f.y * up.x };
    float sLen = sqrtf(s.x*s.x + s.y*s.y + s.z*s.z);
    if (sLen > 0.0001f) { s.x /= sLen; s.y /= sLen; s.z /= sLen; }

    Vec3 u = { s.y * f.z - s.z * f.y, s.z * f.x - s.x * f.z, s.x * f.y - s.y * f.x };

    Mat4 res = Identity();
    res.m[0] = s.x;  res.m[4] = s.y;  res.m[8]  = s.z;
    res.m[1] = u.x;  res.m[5] = u.y;  res.m[9]  = u.z;
    res.m[2] = -f.x; res.m[6] = -f.y; res.m[10] = -f.z;
    res.m[12] = -(s.x * eye.x + s.y * eye.y + s.z * eye.z);
    res.m[13] = -(u.x * eye.x + u.y * eye.y + u.z * eye.z);
    res.m[14] =  (f.x * eye.x + f.y * eye.y + f.z * eye.z);
    return res;
}

static const char* kVertShader =
    "#version 300 es\n"
    "layout(location = 0) in vec3 aPos;\n"
    "layout(location = 1) in vec3 aNorm;\n"
    "layout(location = 2) in vec2 aUV;\n"
    "layout(location = 3) in vec4 aCol;\n"
    "uniform mat4 uWorld;\n"
    "uniform mat4 uView;\n"
    "uniform mat4 uProj;\n"
    "uniform vec3 uLightDir;\n"
    "uniform vec4 uLightDiff;\n"
    "uniform vec4 uAmbient;\n"
    "uniform vec4 uMatDiff;\n"
    "uniform bool uIs2D;\n"
    "out vec2 vUV;\n"
    "out vec4 vColor;\n"
    "void main() {\n"
    "    if (uIs2D) {\n"
    "        gl_Position = uProj * uWorld * vec4(aPos, 1.0);\n"
    "        vColor = uMatDiff * (aCol / 255.0);\n"
    "    } else {\n"
    "        gl_Position = uProj * uView * uWorld * vec4(aPos, 1.0);\n"
    "        mat3 normalMat = transpose(inverse(mat3(uWorld)));\n"
    "        vec3 N = normalize(normalMat * aNorm);\n"
    "        vec3 L = normalize(-uLightDir);\n"
    "        float diff = max(dot(N, L), 0.0);\n"
    "        vColor = (uAmbient + uLightDiff * diff) * uMatDiff * (aCol / 255.0);\n"
    "    }\n"
    "    vUV = aUV;\n"
    "}\n";

static const char* kFragShader =
    "#version 300 es\n"
    "precision mediump float;\n"
    "in vec2 vUV;\n"
    "in vec4 vColor;\n"
    "uniform sampler2D uTex;\n"
    "uniform bool uUseTex;\n"
    "uniform bool uAlphaTest;\n"
    "uniform float uAlphaRef;\n"
    "out vec4 FragColor;\n"
    "void main() {\n"
    "    vec4 tex = uUseTex ? texture(uTex, vUV) : vec4(1.0);\n"
    "    vec4 c = tex * vColor;\n"
    "    if (uAlphaTest && c.a < uAlphaRef) discard;\n"
    "    FragColor = c;\n"
    "}\n";

GfxDevice& GfxDevice::Instance() {
    static GfxDevice dev;
    return dev;
}

GfxDevice::GfxDevice() {}
GfxDevice::~GfxDevice() {}

static GLuint CompileShader(GLenum type, const char* src) {
    GLuint s = glCreateShader(type);
    glShaderSource(s, 1, &src, nullptr);
    glCompileShader(s);
    GLint ok;
    glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char log[512];
        glGetShaderInfoLog(s, sizeof(log), nullptr, log);
        std::cerr << "Shader compile error: " << log << std::endl;
    }
    return s;
}

bool GfxDevice::Init(int width, int height) {
    width_ = width;
    height_ = height;

    GLuint vs = CompileShader(GL_VERTEX_SHADER, kVertShader);
    GLuint fs = CompileShader(GL_FRAGMENT_SHADER, kFragShader);
    shaderProgram_ = glCreateProgram();
    glAttachShader(shaderProgram_, vs);
    glAttachShader(shaderProgram_, fs);
    glLinkProgram(shaderProgram_);
    glDeleteShader(vs);
    glDeleteShader(fs);

    uint32_t whitePixel = 0xFFFFFFFF;
    glGenTextures(1, &whiteTexture_);
    glBindTexture(GL_TEXTURE_2D, whiteTexture_);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &whitePixel);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Quad for 2D sprites
    glGenVertexArrays(1, &quadVao_);
    glGenBuffers(1, &quadVbo_);
    glBindVertexArray(quadVao_);
    glBindBuffer(GL_ARRAY_BUFFER, quadVbo_);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, x));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, nx));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, u));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glBindVertexArray(0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Resize(width, height);
    return true;
}

void GfxDevice::Resize(int width, int height) {
    width_ = width;
    height_ = height;
    glViewport(0, 0, width, height);
    proj_ = Mat4::Perspective(45.0f * (3.14159265f / 180.0f), (float)width / (float)height, 1.0f, 2000.0f);
    ortho_ = Mat4::Ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);
}

void GfxDevice::BeginScene(float r, float g, float b) {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shaderProgram_);
    glEnable(GL_DEPTH_TEST);
    GLint locIs2D = glGetUniformLocation(shaderProgram_, "uIs2D");
    glUniform1i(locIs2D, 0);
}

void GfxDevice::EndScene() {}

void GfxDevice::SetTransformWorld(const Mat4& m) { world_ = m; }
void GfxDevice::SetTransformView(const Mat4& m) { view_ = m; }
void GfxDevice::SetTransformProjection(const Mat4& m) { proj_ = m; }

void GfxDevice::SetLightDirection(const Vec3& dir) { lightDir_ = dir; }
void GfxDevice::SetLightDiffuse(const Vec4& color) { lightDiffuse_ = color; }
void GfxDevice::SetAmbientLight(const Vec4& color) { ambientLight_ = color; }
void GfxDevice::SetMaterialDiffuse(const Vec4& color) { materialDiffuse_ = color; }

void GfxDevice::SetTexture(uint32_t texId) { currentTexture_ = texId; }
void GfxDevice::SetAlphaTest(bool enable, float ref) { alphaTest_ = enable; alphaRef_ = ref; }

void GfxDevice::SetZBuffer(bool testEnable, bool writeEnable) {
    if (testEnable) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);
    glDepthMask(writeEnable ? GL_TRUE : GL_FALSE);
}

void GfxDevice::SetAlphaBlend(bool enable) {
    if (enable) glEnable(GL_BLEND); else glDisable(GL_BLEND);
}

uint32_t GfxDevice::CreateMeshBuffer(const std::vector<Vertex>& vertices, const std::vector<uint16_t>& indices) {
    MeshEntry me;
    glGenVertexArrays(1, &me.vao);
    glGenBuffers(1, &me.vbo);
    glGenBuffers(1, &me.ibo);

    glBindVertexArray(me.vao);
    glBindBuffer(GL_ARRAY_BUFFER, me.vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, me.ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint16_t), indices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, x));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, nx));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, u));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

    glBindVertexArray(0);
    me.indexCount = (uint32_t)indices.size();
    meshes_.push_back(me);
    return (uint32_t)meshes_.size();
}

void GfxDevice::DrawMesh(uint32_t meshId) {
    if (meshId == 0 || meshId > meshes_.size()) return;
    const MeshEntry& me = meshes_[meshId - 1];

    glUseProgram(shaderProgram_);

    GLint locWorld = glGetUniformLocation(shaderProgram_, "uWorld");
    GLint locView = glGetUniformLocation(shaderProgram_, "uView");
    GLint locProj = glGetUniformLocation(shaderProgram_, "uProj");
    GLint locLDir = glGetUniformLocation(shaderProgram_, "uLightDir");
    GLint locLDiff = glGetUniformLocation(shaderProgram_, "uLightDiff");
    GLint locAmb = glGetUniformLocation(shaderProgram_, "uAmbient");
    GLint locMDiff = glGetUniformLocation(shaderProgram_, "uMatDiff");
    GLint locUseTex = glGetUniformLocation(shaderProgram_, "uUseTex");
    GLint locATest = glGetUniformLocation(shaderProgram_, "uAlphaTest");
    GLint locARef = glGetUniformLocation(shaderProgram_, "uAlphaRef");
    GLint locIs2D = glGetUniformLocation(shaderProgram_, "uIs2D");

    glUniformMatrix4fv(locWorld, 1, GL_FALSE, world_.m);
    glUniformMatrix4fv(locView, 1, GL_FALSE, view_.m);
    glUniformMatrix4fv(locProj, 1, GL_FALSE, proj_.m);

    glUniform3f(locLDir, lightDir_.x, lightDir_.y, lightDir_.z);
    glUniform4f(locLDiff, lightDiffuse_.r, lightDiffuse_.g, lightDiffuse_.b, lightDiffuse_.a);
    glUniform4f(locAmb, ambientLight_.r, ambientLight_.g, ambientLight_.b, ambientLight_.a);
    glUniform4f(locMDiff, materialDiffuse_.r, materialDiffuse_.g, materialDiffuse_.b, materialDiffuse_.a);

    glUniform1i(locATest, alphaTest_ ? 1 : 0);
    glUniform1f(locARef, alphaRef_);
    glUniform1i(locIs2D, 0);

    glActiveTexture(GL_TEXTURE0);
    if (currentTexture_ > 0) {
        glBindTexture(GL_TEXTURE_2D, currentTexture_);
        glUniform1i(locUseTex, 1);
    } else {
        glBindTexture(GL_TEXTURE_2D, whiteTexture_);
        glUniform1i(locUseTex, 0);
    }

    glBindVertexArray(me.vao);
    glDrawElements(GL_TRIANGLES, me.indexCount, GL_UNSIGNED_SHORT, nullptr);
    glBindVertexArray(0);
}

void GfxDevice::DeleteMeshBuffer(uint32_t meshId) {
    if (meshId == 0 || meshId > meshes_.size()) return;
    MeshEntry& me = meshes_[meshId - 1];
    glDeleteBuffers(1, &me.vbo);
    glDeleteBuffers(1, &me.ibo);
    glDeleteVertexArrays(1, &me.vao);
    me = MeshEntry();
}

#if defined(__EMSCRIPTEN__)
EM_JS(int, JS_LoadWebTexture, (const char* pathStr), {
    var path = UTF8ToString(pathStr);
    var g = (typeof GLctx !== 'undefined') ? GLctx : (Module.ctx || window.gl);
    if (!g) return 0;
    var tex = g.createTexture();
    g.bindTexture(g.TEXTURE_2D, tex);
    g.texImage2D(g.TEXTURE_2D, 0, g.RGBA, 1, 1, 0, g.RGBA, g.UNSIGNED_BYTE, new Uint8Array([220, 220, 220, 255]));

    var img = new Image();
    img.crossOrigin = "anonymous";
    img.onload = function() {
        var glContext = (typeof GLctx !== 'undefined') ? GLctx : (Module.ctx || window.gl);
        if (!glContext) return;
        glContext.pixelStorei(glContext.UNPACK_FLIP_Y_WEBGL, true);
        glContext.bindTexture(glContext.TEXTURE_2D, tex);
        glContext.texImage2D(glContext.TEXTURE_2D, 0, glContext.RGBA, glContext.RGBA, glContext.UNSIGNED_BYTE, img);
        glContext.texParameteri(glContext.TEXTURE_2D, glContext.TEXTURE_MIN_FILTER, glContext.NEAREST);
        glContext.texParameteri(glContext.TEXTURE_2D, glContext.TEXTURE_MAG_FILTER, glContext.NEAREST);
        glContext.texParameteri(glContext.TEXTURE_2D, glContext.TEXTURE_WRAP_S, glContext.REPEAT);
        glContext.texParameteri(glContext.TEXTURE_2D, glContext.TEXTURE_WRAP_T, glContext.REPEAT);
    };
    img.src = path;

    var id = (typeof GL !== 'undefined' && GL.getNewId) ? GL.getNewId(GL.textures) : 1;
    if (typeof GL !== 'undefined' && GL.textures) GL.textures[id] = tex;
    return id;
});
#endif

uint32_t GfxDevice::LoadTexture(const std::string& path) {
#if defined(__EMSCRIPTEN__)
    return (uint32_t)JS_LoadWebTexture(path.c_str());
#else
    return 0;
#endif
}

void GfxDevice::Begin2D() {
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    glUseProgram(shaderProgram_);
    GLint locIs2D = glGetUniformLocation(shaderProgram_, "uIs2D");
    glUniform1i(locIs2D, 1);
    GLint locProj = glGetUniformLocation(shaderProgram_, "uProj");
    glUniformMatrix4fv(locProj, 1, GL_FALSE, ortho_.m);
    GLint locWorld = glGetUniformLocation(shaderProgram_, "uWorld");
    Mat4 id = Mat4::Identity();
    glUniformMatrix4fv(locWorld, 1, GL_FALSE, id.m);
}

void GfxDevice::End2D() {
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
}

void GfxDevice::DrawRect2D(float x, float y, float w, float h, const Vec4& color) {
    Vertex v[6] = {
        { x,     y,     0,  0,0,1,  0,0,  0xFFFFFFFF },
        { x + w, y,     0,  0,0,1,  1,0,  0xFFFFFFFF },
        { x + w, y + h, 0,  0,0,1,  1,1,  0xFFFFFFFF },
        { x,     y,     0,  0,0,1,  0,0,  0xFFFFFFFF },
        { x + w, y + h, 0,  0,0,1,  1,1,  0xFFFFFFFF },
        { x,     y + h, 0,  0,0,1,  0,1,  0xFFFFFFFF }
    };

    GLint locMDiff = glGetUniformLocation(shaderProgram_, "uMatDiff");
    glUniform4f(locMDiff, color.r, color.g, color.b, color.a);
    GLint locUseTex = glGetUniformLocation(shaderProgram_, "uUseTex");
    glUniform1i(locUseTex, 0);

    glBindVertexArray(quadVao_);
    glBindBuffer(GL_ARRAY_BUFFER, quadVbo_);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v), v);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void GfxDevice::DrawSprite2D(uint32_t texId, float x, float y, float w, float h, float u0, float v0, float u1, float v1, const Vec4& color) {
    Vertex v[6] = {
        { x,     y,     0,  0,0,1,  u0,v0,  0xFFFFFFFF },
        { x + w, y,     0,  0,0,1,  u1,v0,  0xFFFFFFFF },
        { x + w, y + h, 0,  0,0,1,  u1,v1,  0xFFFFFFFF },
        { x,     y,     0,  0,0,1,  u0,v0,  0xFFFFFFFF },
        { x + w, y + h, 0,  0,0,1,  u1,v1,  0xFFFFFFFF },
        { x,     y + h, 0,  0,0,1,  u0,v1,  0xFFFFFFFF }
    };

    GLint locMDiff = glGetUniformLocation(shaderProgram_, "uMatDiff");
    glUniform4f(locMDiff, color.r, color.g, color.b, color.a);
    GLint locUseTex = glGetUniformLocation(shaderProgram_, "uUseTex");
    glUniform1i(locUseTex, 1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texId);

    glBindVertexArray(quadVao_);
    glBindBuffer(GL_ARRAY_BUFFER, quadVbo_);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(v), v);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
