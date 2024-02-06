#include "../headers/StlToObjWriter.h"
#include <iostream>
#include <fstream>

Shapes3D::StlToObjWriter::StlToObjWriter() {}
Shapes3D::StlToObjWriter::~StlToObjWriter() {}

void Shapes3D::StlToObjWriter::write(std::string &filePath, Triangulation &triangulationObj)
{
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening .obj file." << endl;
        return;
    }

    vector<Point3D> &points = triangulationObj.uniquePoints();
    vector<Triangle> &triangles = triangulationObj.triangles();

    for (size_t i = 0; i < points.size(); i++)
    {
        outFile << "v"
                << " " << points[i].x() << " " << points[i].y() << " " << points[i].z() << endl;
    }

    outFile << " " << endl;

    for (const Triangle &triangle : triangles)
    {
        outFile << "f"
                << " " << triangle.index1() + 1 << "//"
                << " " << triangle.index2() + 1 << "//"
                << " " << triangle.index3() + 1 << "//" << endl;
    }

    cout << "Data writting from .stl to .obj file successful!" << endl;
    outFile.close();
}