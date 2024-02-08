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
    std::vector<Point3D> normals;

    // reads obj file line by line
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
            triangulationObj.uniquePoints().push_back(point);
        }
        else if (keyword == "vn")
        {
            double x, y, z;
            vertexStream >> x >> y >> z;
            Point3D normal(x, y, z);
            triangulationObj.uniqueNormals().push_back(normal);
        }
        else if (keyword == "f")
        {
            std::string index1, index2, index3;
            vertexStream >> index1 >> index2 >> index3;

            std::vector<std::string> tokens1, tokens2, tokens3;

            std::stringstream vertexTokenStreamV(index1), vertexTokenStreamT(index2), vertexTokenStreamN(index3);
            std::string token;
            while (getline(vertexTokenStreamV, token, '/'))
            {
                tokens1.push_back(token);
            }
            while (getline(vertexTokenStreamT, token, '/'))
            {
                tokens2.push_back(token);
            }
            while (getline(vertexTokenStreamN, token, '/'))
            {
                tokens3.push_back(token);
            };

            int vertex1 = stoi(tokens1[0]) - 1;
            int vertex2 = stoi(tokens2[0]) - 1;
            int vertex3 = stoi(tokens3[0]) - 1;
            Triangle triangle(vertex1, vertex2, vertex3);
            triangulationObj.triangles().push_back(triangle);
        }
    }
    std::cout << "Data reading from .obj file completed successfully" << std::endl;
    file.close();
}
