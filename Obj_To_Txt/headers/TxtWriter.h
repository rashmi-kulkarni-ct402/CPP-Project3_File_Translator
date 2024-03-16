#pragma once
#include "Triangulation.h"
#include <string>

namespace Shapes3D
{
    class TxtWriter
    {
    public:
        TxtWriter();
        ~TxtWriter();

        void write(std::string &filePath, Triangulation &triangulationObj);
    };
}
