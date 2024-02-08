#pragma once
#include "../headers/Triangulation.h"
#include <string>

namespace Shapes3D
{
    class ObjWriter
    {
    public:
        ObjWriter();
        ~ObjWriter();

        void write(std::string &filePath, Triangulation &triangulationObj);
    };
}
