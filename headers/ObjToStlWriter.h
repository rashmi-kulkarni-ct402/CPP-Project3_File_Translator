#pragma once
#include "../headers/Triangulation.h"
#include <string>

namespace Shapes3D
{
    class ObjToStlWriter
    {
    public:
        ObjToStlWriter();
        ~ObjToStlWriter();

        void write(std::string &filePath, Triangulation &triangulationObj);
    };
}
