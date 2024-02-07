#include "../headers/StlWriter.h"
#include <iostream>
#include <fstream>
#include <map>

Shapes3D::StlWriter::StlWriter() {}
Shapes3D::StlWriter::~StlWriter() {}

void Shapes3D::StlWriter::write(std::string &filePath, Triangulation &triangulationStl)
{
    std::ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        std::cout << "Error while opening .stl file." << std::endl;
        return;
    }

    std::vector<Point3D> &points = triangulationStl.uniquePoints();
    std::vector<Triangle> &triangles = triangulationStl.triangles();
    std::vector<Point3D> &normals = triangulationStl.uniqueNormals();

    outFile << "solid" << std::endl;
    for (const Triangle &triangle : triangles)
    {
        outFile << "facet normal " << normals[triangle.normalIndex()].x() << " " << normals[triangle.normalIndex()].y() << " " << normals[triangle.normalIndex()].z() << std::endl;
        outFile << "  outer loop" << std::endl;
        outFile << "    vertex " << points[triangle.index1()].x() << " " << points[triangle.index1()].y() << " " << points[triangle.index1()].z() << std::endl;
        outFile << "    vertex " << points[triangle.index2()].x() << " " << points[triangle.index2()].y() << " " << points[triangle.index2()].z() << std::endl;
        outFile << "    vertex " << points[triangle.index3()].x() << " " << points[triangle.index3()].y() << " " << points[triangle.index3()].z() << std::endl;
        outFile << "  endloop" << std::endl;
        outFile << "endfacet" << std::endl;
    }
    outFile << "endsolid";
    outFile.close();
    std::cout << "Data writing from .obj to .stl file successful!" << std::endl;
}
