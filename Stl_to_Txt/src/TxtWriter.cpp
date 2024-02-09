#include "../headers/TxtWriter.h"
#include <iostream>
#include <fstream>

Shapes3D::TxtWriter::TxtWriter() {}
Shapes3D::TxtWriter::~TxtWriter() {}

void Shapes3D::TxtWriter::write(std::string &filePath, Triangulation &triangulationObj)
{
    std::ofstream outFile(filePath);

    // checks for file opening error
    if (!outFile.is_open())
    {
        std::cout << "Error while opening .txt file." << std::endl;
        return;
    }

    // getting values of uniquePoints, triangles and assigning to new vectors -> points, triangles.
    std::vector<Point3D> points = triangulationObj.uniquePoints();
    std::vector<Triangle> triangles = triangulationObj.triangles();

    // iterating each triangle from traingles vector to write points
    for (const Triangle &triangle : triangles)
    {
        outFile << points[triangle.index1()].x() << " " << points[triangle.index1()].y() << " " << points[triangle.index1()].z() << std::endl;
        outFile << points[triangle.index2()].x() << " " << points[triangle.index2()].y() << " " << points[triangle.index2()].z() << std::endl;
        outFile << points[triangle.index3()].x() << " " << points[triangle.index3()].y() << " " << points[triangle.index3()].z() << std::endl;
    }
    std::cout << "Data writting from .stl to .txt file successful!" << std::endl;
    // closing the file
    outFile.close();
}
