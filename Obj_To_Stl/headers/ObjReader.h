#pragma once
#include "Triangulation.h"
#include <string>
#include <vector>

namespace Shapes3D
{
    class ObjReader
    {
    public:
        ObjReader();
        ~ObjReader();
        void read(const std::string &filePath, Triangulation &triangulationObj);
    };
}