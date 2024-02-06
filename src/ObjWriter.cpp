#include "../headers/ObjWriter.h"
#include <iostream>
#include <fstream>

Shapes3D::ObjWriter::ObjWriter() {}
Shapes3D::ObjWriter::~ObjWriter() {}

void Shapes3D::ObjWriter::write(std::string &filePath, Triangulation &triangulationObj)
{
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        std::cout << "Error while opening .txt file." << std::endl;
        return;
    }

    vector<Point3D> &points = triangulationObj.uniquePoints();
    vector<Triangle> &triangles = triangulationObj.triangles();

    for (const Triangle &triangle : triangles)
    {
        outFile << points[triangle.index1() - 1].x() << " " << points[triangle.index1() - 1].y() << " " << points[triangle.index1() - 1].z() << std::endl;
        outFile << points[triangle.index2() - 1].x() << " " << points[triangle.index2() - 1].y() << " " << points[triangle.index2() - 1].z() << std::endl;
        outFile << points[triangle.index3() - 1].x() << " " << points[triangle.index3() - 1].y() << " " << points[triangle.index3() - 1].z() << std::endl;
    }
    outFile.close();
    std::cout << "Data writting from .obj to .txt file successful!" << std::endl;
}