#ifndef HOPMON_XFILE_PARSER_H
#define HOPMON_XFILE_PARSER_H

#include "GfxDevice.h"
#include <string>
#include <vector>

struct LoadedMesh {
    std::string name;
    std::vector<Vertex> vertices;
    std::vector<uint16_t> indices;
    uint32_t meshBufferId = 0;
};

class XFileParser {
public:
    static bool Load(const std::string& filepath, LoadedMesh& outMesh);
};

#endif // HOPMON_XFILE_PARSER_H
