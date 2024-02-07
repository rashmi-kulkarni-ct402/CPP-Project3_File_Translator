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
            std::string v, t, n; // v - vertex, t - texture, n -normal
            vertexStream >> v >> t >> n;

            int vertex1 = stoi(v) - 1;
            int vertex2 = stoi(t) - 1;
            int vertex3 = stoi(n) - 1;
            int normalIndex;

            for (int i = v.size(); i > 0; i--)
            {
                if (v[i] == '/')
                {
                    normalIndex = stoi(v.substr(i + 1, v.size() - i - 1)) - 1;
                    break;
                }
            }

            // std::vector<std::string> tokensV, tokensT, tokensN;
            // std::stringstream vertexTokenStreamV(v), vertexTokenStreamT(t), vertexTokenStreamN(n);
            // std::string token;

            // while (getline(vertexTokenStreamV, token, '/'))
            // {
            //     tokensV.push_back(token);
            // }
            // while (getline(vertexTokenStreamT, token, '/'))
            // {
            //     tokensT.push_back(token);
            // }
            // while (getline(vertexTokenStreamN, token, '/'))
            // {
            //     tokensN.push_back(token);
            // };

            // int vertex1 = stoi(tokensV[0]) - 1;
            // int vertex2 = stoi(tokensT[0]) - 1;
            // int vertex3 = stoi(tokensN[0]) - 1;

            Triangle triangle(vertex1, vertex2, vertex3, normalIndex);
            triangulationObj.triangles().push_back(triangle);
        }
    }
    std::cout << "Data reading from .obj file completed successfully" << std::endl;
    file.close();
}