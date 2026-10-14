#include "XFileParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

bool XFileParser::Load(const std::string& filepath, LoadedMesh& outMesh) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open .x file: " << filepath << std::endl;
        return false;
    }

    std::string token;
    bool inMesh = false;
    int vertexCount = 0;
    std::vector<Vec3> positions;
    std::vector<uint16_t> faceIndices;
    std::vector<Vec3> normals;
    std::vector<std::pair<float, float>> uvs;
    std::vector<int> faceMatIndices;
    std::vector<Vec4> materials;

    while (file >> token) {
        if (token == "Mesh") {
            file >> outMesh.name;
            if (outMesh.name == "{") outMesh.name = "unnamed";
            else {
                std::string openBrace;
                file >> openBrace;
            }
            inMesh = true;

            // Read vertex count
            std::string countStr;
            file >> countStr;
            vertexCount = std::stoi(countStr);
            positions.reserve(vertexCount);

            // Read vertices
            for (int i = 0; i < vertexCount; ++i) {
                std::string line;
                file >> line;
                float x = 0, y = 0, z = 0;
                sscanf(line.c_str(), "%f;%f;%f", &x, &y, &z);
                positions.push_back({x, y, z});
            }

            // Read face count
            file >> countStr;
            int faceCount = std::stoi(countStr);
            for (int i = 0; i < faceCount; ++i) {
                std::string line;
                file >> line;
                int n = 0, i0 = 0, i1 = 0, i2 = 0;
                sscanf(line.c_str(), "%d;%d,%d,%d", &n, &i0, &i1, &i2);
                faceIndices.push_back((uint16_t)i0);
                faceIndices.push_back((uint16_t)i1);
                faceIndices.push_back((uint16_t)i2);
            }
        }
        else if (token == "MeshNormals") {
            std::string openBrace, countStr;
            file >> openBrace >> countStr;
            int normalCount = std::stoi(countStr);
            normals.reserve(normalCount);
            for (int i = 0; i < normalCount; ++i) {
                std::string line;
                file >> line;
                float nx = 0, ny = 0, nz = 0;
                sscanf(line.c_str(), "%f;%f;%f", &nx, &ny, &nz);
                normals.push_back({nx, ny, nz});
            }
        }
        else if (token == "MeshTextureCoords") {
            std::string openBrace, countStr;
            file >> openBrace >> countStr;
            int uvCount = std::stoi(countStr);
            uvs.reserve(uvCount);
            for (int i = 0; i < uvCount; ++i) {
                std::string line;
                file >> line;
                float u = 0, v = 0;
                sscanf(line.c_str(), "%f;%f", &u, &v);
                uvs.push_back({u, v});
            }
        }
        else if (token == "MeshMaterialList") {
            std::string openBrace, nMatStr, nFaceStr;
            file >> openBrace >> nMatStr >> nFaceStr;
            int nMats = std::stoi(nMatStr);
            int nFaces = std::stoi(nFaceStr);

            faceMatIndices.reserve(nFaces);
            for (int i = 0; i < nFaces; ++i) {
                std::string idxStr;
                file >> idxStr;
                int matIdx = 0;
                sscanf(idxStr.c_str(), "%d", &matIdx);
                faceMatIndices.push_back(matIdx);
            }

            // Read materials
            for (int m = 0; m < nMats; ++m) {
                std::string mToken, mName, mBrace, colorStr;
                file >> mToken >> mName >> mBrace >> colorStr;
                float r = 1, g = 1, b = 1, a = 1;
                sscanf(colorStr.c_str(), "%f;%f;%f;%f", &r, &g, &b, &a);
                materials.push_back({r, g, b, a});

                // Consume rest of Material definition until closing brace
                std::string sub;
                while (file >> sub) {
                    if (sub.find('}') != std::string::npos) break;
                }
            }
        }
    }

    if (positions.empty() || faceIndices.empty()) {
        return false;
    }

    // Assemble vertices with material colors
    outMesh.vertices.clear();
    outMesh.indices.clear();

    if (!faceMatIndices.empty() && !materials.empty()) {
        // Build per-triangle vertices with exact material colors
        size_t triCount = faceIndices.size() / 3;
        outMesh.vertices.reserve(triCount * 3);
        outMesh.indices.reserve(triCount * 3);

        for (size_t f = 0; f < triCount; ++f) {
            int matIdx = (f < faceMatIndices.size()) ? faceMatIndices[f] : 0;
            if (matIdx < 0 || matIdx >= (int)materials.size()) matIdx = 0;
            const Vec4& matCol = materials[matIdx];

            uint8_t cr = (uint8_t)(std::clamp(matCol.r, 0.0f, 1.0f) * 255.0f);
            uint8_t cg = (uint8_t)(std::clamp(matCol.g, 0.0f, 1.0f) * 255.0f);
            uint8_t cb = (uint8_t)(std::clamp(matCol.b, 0.0f, 1.0f) * 255.0f);
            uint8_t ca = (uint8_t)(std::clamp(matCol.a, 0.0f, 1.0f) * 255.0f);
            uint32_t col = (ca << 24) | (cb << 16) | (cg << 8) | cr;

            for (int k = 0; k < 3; ++k) {
                uint16_t origIdx = faceIndices[f * 3 + k];
                Vertex v;
                v.x = positions[origIdx].x;
                v.y = positions[origIdx].y;
                v.z = positions[origIdx].z;

                if (origIdx < normals.size()) {
                    v.nx = normals[origIdx].x;
                    v.ny = normals[origIdx].y;
                    v.nz = normals[origIdx].z;
                } else {
                    v.nx = 0.0f; v.ny = 1.0f; v.nz = 0.0f;
                }

                if (origIdx < uvs.size()) {
                    v.u = uvs[origIdx].first;
                    v.v = uvs[origIdx].second;
                } else {
                    v.u = 0.0f; v.v = 0.0f;
                }

                v.color = col;

                uint16_t newIdx = (uint16_t)outMesh.vertices.size();
                outMesh.vertices.push_back(v);
                outMesh.indices.push_back(newIdx);
            }
        }
    } else {
        outMesh.vertices.resize(positions.size());
        for (size_t i = 0; i < positions.size(); ++i) {
            outMesh.vertices[i].x = positions[i].x;
            outMesh.vertices[i].y = positions[i].y;
            outMesh.vertices[i].z = positions[i].z;
            if (i < normals.size()) {
                outMesh.vertices[i].nx = normals[i].x;
                outMesh.vertices[i].ny = normals[i].y;
                outMesh.vertices[i].nz = normals[i].z;
            } else {
                outMesh.vertices[i].ny = 1.0f;
            }
            if (i < uvs.size()) {
                outMesh.vertices[i].u = uvs[i].first;
                outMesh.vertices[i].v = uvs[i].second;
            }
            outMesh.vertices[i].color = 0xFFFFFFFF;
        }
        outMesh.indices = faceIndices;
    }

    outMesh.meshBufferId = GfxDevice::Instance().CreateMeshBuffer(outMesh.vertices, outMesh.indices);
    return true;
}
