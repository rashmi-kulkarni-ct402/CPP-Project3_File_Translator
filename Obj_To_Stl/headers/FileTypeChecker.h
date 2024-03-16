#pragma once
#include <string>

namespace Shapes3D
{
    class FileTypeChecker
    {
    public:
        FileTypeChecker();
        ~FileTypeChecker();

        bool isObjFile(const std::string &filename);
    };
}
