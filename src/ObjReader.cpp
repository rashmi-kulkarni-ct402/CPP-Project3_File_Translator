#include "../headers/ObjReader.h"
#include "../headers/Triangulation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Shapes3D::ObjReader::ObjReader() {}
Shapes3D::ObjReader::~ObjReader() {}

void Shapes3D::ObjReader::read(const string &filePath, Triangulation &triangulationObj)
{
    ifstream file(filePath);

    if (!file.is_open())
    {
        std::cout << "Error while opening .obj file." << std::endl;
        return;
    }

    string line;
    vector<Point3D> points;
    vector<Triangle> triangles;
    int vertexindex = 0;

    while (getline(file, line))
    {
        istringstream iss(line);
        string keyword;
        iss >> keyword;

        if (keyword == "v")
        {
            double x1, y1, z1;
            iss >> x1 >> y1 >> z1;
            Point3D point(x1, y1, z1);
            points.push_back(point);
        }
        else if (keyword == "f")
        {
            string a, b, c;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> a >> b >> c;
            int vextex1, vertex2, vertex3;
            vextex1 = a[0];
            vextex1 -= 48;
            vertex2 = b[0];
            vertex2 -= 48;
            vertex3 = c[0];
            vertex3 -= 48;

            Triangle triangle(vextex1, vertex2, vertex3);
            triangles.push_back(triangle);
        }
    }
    vertexindex = 0;

    std::cout << "Data reading from .obj file completed successfully" << std::endl;

    triangulationObj.uniquePoints() = points;
    triangulationObj.triangles() = triangles;

    file.close();
}
