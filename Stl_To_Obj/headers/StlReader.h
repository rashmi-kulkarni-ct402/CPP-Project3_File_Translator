#pragma once
#include "Triangulation.h"
#include <string>
#include <vector>

namespace Shapes3D
{
    class StlReader
    {
    public:
        StlReader();
        ~StlReader();

        void read(const std::string &filePath, Triangulation &triangulationObj);
    };
}