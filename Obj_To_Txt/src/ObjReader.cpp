#include "../headers/ObjReader.h"
#include "../headers/Triangulation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Shapes3D::ObjReader::ObjReader() {}
Shapes3D::ObjReader::~ObjReader() {}

void Shapes3D::ObjReader::read(const std::string &filePath, Triangulation &triangulationObj)
{
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        std::cout << "Error while opening .obj file." << std::endl;
        return;
    }

    std::string line;
    std::vector<Point3D> points;
    std::vector<Triangle> triangles;

    while (getline(file, line))
    {
        std::istringstream vertexStream(line);
        std::string keyword;
        vertexStream >> keyword;

        if (keyword == "v")
        {
            double x, y, z;
            vertexStream >> x >> y >> z;
            Point3D point(x, y, z);
            points.push_back(point);
        }

        else if (keyword == "f")
        {
             std::string index1, index2, index3;
            vertexStream >> index1 >> index2 >> index3;

            std::vector<std::string> tokensV, tokensT, tokensN;

            std::stringstream vertexTokenStreamV(index1), vertexTokenStreamT(index2), vertexTokenStreamN(index3);
            std::string token;
            while (getline(vertexTokenStreamV, token, '/'))
            {
                tokensV.push_back(token);
            }
            while (getline(vertexTokenStreamT, token, '/'))
            {
                tokensT.push_back(token);
            }
            while (getline(vertexTokenStreamN, token, '/'))
            {
                tokensN.push_back(token);
            };

            int vertex1 = stoi(tokensV[0]) - 1;
            int vertex2 = stoi(tokensT[0]) - 1;
            int vertex3 = stoi(tokensN[0]) - 1;

            Triangle triangle(vertex1, vertex2, vertex3);
            triangles.push_back(triangle);
        }
    }

    std::cout << "Data reading from .obj file completed successfully" << std::endl;

    triangulationObj.uniquePoints() = points;
    triangulationObj.triangles() = triangles;

    file.close();
}
