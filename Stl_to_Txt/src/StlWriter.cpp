#include "../headers/StlWriter.h"
#include <iostream>
#include <fstream>

Shapes3D::StlWriter::StlWriter() {}
Shapes3D::StlWriter::~StlWriter() {}

void Shapes3D::StlWriter::write(std::string &filePath, Triangulation &triangulationObj)
{
    std::ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        std::cout << "Error while opening .txt file." << std::endl;
        return;
    }

    std::vector<Point3D> &points = triangulationObj.uniquePoints();
    std::vector<Triangle> &triangles = triangulationObj.triangles();

    for (const Triangle &triangle : triangles)
    {
        outFile << points[triangle.index1()].x() << " " << points[triangle.index1()].y() << " " << points[triangle.index1()].z() << std::endl;
        outFile << points[triangle.index2()].x() << " " << points[triangle.index2()].y() << " " << points[triangle.index2()].z() << std::endl;
        outFile << points[triangle.index3()].x() << " " << points[triangle.index3()].y() << " " << points[triangle.index3()].z() << std::endl;
    }
    std::cout << "Data writting from .stl to .txt file successful!" << std::endl;
    outFile.close();
}
