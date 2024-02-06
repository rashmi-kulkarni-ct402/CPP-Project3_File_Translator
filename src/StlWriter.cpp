#include "../headers/StlWriter.h"
#include <iostream>
#include <fstream>

Shapes3D::StlWriter::StlWriter() {}
Shapes3D::StlWriter::~StlWriter() {}

void Shapes3D::StlWriter::write(string &filePath, Triangulation &triangulationObj)
{
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening .txt file." << endl;
        return;
    }

    vector<Point3D> &points = triangulationObj.uniquePoints();
    vector<Triangle> &triangles = triangulationObj.triangles();

    for (const Triangle &triangle : triangles)
    {
        outFile << points[triangle.index1()].x() << " " << points[triangle.index1()].y() << " " << points[triangle.index1()].z() << endl;
        outFile << points[triangle.index2()].x() << " " << points[triangle.index2()].y() << " " << points[triangle.index2()].z() << endl;
        outFile << points[triangle.index3()].x() << " " << points[triangle.index3()].y() << " " << points[triangle.index3()].z() << endl;
    }
    cout << "Data writting from .stl to .txt file successful!" << endl;
    outFile.close();
}
