#include "../headers/ObjWriter.h"
#include <iostream>
#include <fstream>

namespace Shapes3D
{
    ObjWriter::ObjWriter() {}

    ObjWriter::~ObjWriter() {}

    void ObjWriter::write(std::string &FilePath, Triangulation &triangulationObj)
    {
        std::ofstream outFile(FilePath);

        if (!outFile.is_open())
        {
            std::cout << "Error while opening the file." << std::endl;
            return;
        }

        // Write vertices
        for (const auto &point : triangulationObj.uniquePoints())
        {
            outFile << "v " << point.x() << " " << point.y() << " " << point.z() << std::endl;
        }

        outFile << std::endl;

        for (const auto &normal : triangulationObj.uniqueNormals())
        {
            outFile << "vn " << normal.x() << " " << normal.y() << " " << normal.z() << std::endl;
        }

        outFile << std::endl;

        // Write faces
        for (const auto &triangle : triangulationObj.triangles())
        {

            outFile << "f " << triangle.index1() + 1 << "//" << triangle.normalIndex() + 1 << " "
                    << triangle.index2() + 1 << "//" << triangle.normalIndex() + 1 << " "
                    << triangle.index3() + 1 << "//" << triangle.normalIndex() + 1 << std::endl;
        }

        std::cout << "Data writing from .stl to .obj outFile completed successfully" << std::endl;
        outFile.close();
    }
}
