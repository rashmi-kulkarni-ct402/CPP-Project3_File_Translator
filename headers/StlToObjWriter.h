#pragma once
#include "../headers/Triangulation.h"
#include <string>

namespace Shapes3D
{
    class StlToObjWriter
    {
    public:
        StlToObjWriter();
        ~StlToObjWriter();

        void write(std::string &filePath, Triangulation &triangulationObj);
    };
}
