#include "../headers/StlWriter.h"
#include <iostream>
#include <fstream>
#include <map>

Shapes3D::StlWriter::StlWriter() {}
Shapes3D::StlWriter::~StlWriter() {}

void Shapes3D::StlWriter::write(std::string &filePath, Triangulation &triangulationObj)
{
    std::ofstream outFile(filePath);

    // checks for file opening error
    if (!outFile.is_open())
    {
        std::cout << "Error while opening .stl file." << std::endl;
        return;
    }

    // getting values of uniquePoints, triangles, uniqueNormals and assigning to new vectors -> points, triangles and normals
    std::vector<Point3D> points = triangulationObj.uniquePoints();
    std::vector<Triangle> triangles = triangulationObj.triangles();
    std::vector<Point3D> normals = triangulationObj.uniqueNormals();

    outFile << "solid" << std::endl;
    // iterating each triangle from traingles vector to write normal and points
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
    // closing the file
    outFile.close();
    std::cout << "Data writing from .obj to .stl file successful!" << std::endl;
}
