#include "../headers/ObjToStlWriter.h"
#include <iostream>
#include <fstream>

Shapes3D::ObjToStlWriter::ObjToStlWriter() {}
Shapes3D::ObjToStlWriter::~ObjToStlWriter() {}

void Shapes3D::ObjToStlWriter::write(std::string &filePath, Triangulation &triangulationStl)
{
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        std::cout << "Error while opening .stl file." << std::endl;
        return;
    }

    vector<Point3D> &points = triangulationStl.uniquePoints();
    vector<Triangle> &triangles = triangulationStl.triangles();

    outFile << "solid" << std::endl;
    for (const Triangle &triangle : triangles)
    {
        outFile << "facet normal" << std::endl;
        outFile << "outer loop" << std::endl;
        outFile << "vertex"
                << " " << points[triangle.index1() - 1].x() << " " << points[triangle.index1() - 1].y() << " " << points[triangle.index1() - 1].z() << std::endl;
        outFile << "vertex"
                << " " << points[triangle.index2() - 1].x() << " " << points[triangle.index2() - 1].y() << " " << points[triangle.index2() - 1].z() << std::endl;
        outFile << "vertex"
                << " " << points[triangle.index3() - 1].x() << " " << points[triangle.index3() - 1].y() << " " << points[triangle.index3() - 1].z() << std::endl;
        outFile << "std::endloop" << std::endl;
        outFile << "endfacet" << std::endl;
    }
    outFile << "endsolid";
    outFile.close();
    std::cout << "Data writting from .obj to .stl file successful!" << std::endl;
}