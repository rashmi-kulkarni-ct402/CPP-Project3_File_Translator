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

    // checks for file opening error
    if (!file.is_open())
    {
        std::cout << "Error while opening .obj file." << std::endl;
        return;
    }

    std::string line;
    int normalIndex = 0;

    // reads obj file line by line
    while (getline(file, line))
    {
        std::istringstream vertexStream(line);
        std::string keyword;
        vertexStream >> keyword;

        // Checks if keyword is "v" (vertex)
        if (keyword == "v")
        {
            double x, y, z;
            vertexStream >> x >> y >> z;
            Point3D point(x, y, z);
            // add point to triangulation object
            triangulationObj.addUniquePointToTriangulation(point);
        }
        // Checks if keyword is "vn" (vertex normal)
        else if (keyword == "vn")
        {
            double x, y, z;
            vertexStream >> x >> y >> z;
            Point3D normal(x, y, z);
            // add normal to triangulation object
            triangulationObj.addUniqueNormalToTriangulation(normal);
        }
        // Checks if keyword is "f" (face)
        else if (keyword == "f")
        {
            std::string index1, index2, index3;
            vertexStream >> index1 >> index2 >> index3;

            std::vector<std::string> tokens1, tokens2, tokens3;

            std::stringstream vertexTokenStreamV(index1), vertexTokenStreamT(index2), vertexTokenStreamN(index3);
            std::string token;
            // tokenize vertex index
            while (getline(vertexTokenStreamV, token, '/'))
            {
                tokens1.push_back(token);
            }
            // tokenize texture index
            while (getline(vertexTokenStreamT, token, '/'))
            {
                tokens2.push_back(token);
            }
            // tokenize normal index
            while (getline(vertexTokenStreamN, token, '/'))
            {
                tokens3.push_back(token);
            };

            // get vertex indices
            int vertex1 = stoi(tokens1[0]) - 1;
            int vertex2 = stoi(tokens2[0]) - 1;
            int vertex3 = stoi(tokens3[0]) - 1;

            //  iterate through characters of the first index
            for (int i = index1.size(); i > 0; i--)
            {
                if (index1[i] == '/')
                {
                    normalIndex = std::stoi(index1.substr(i + 1, index1.size() - i - 1));
                    break;
                }
            }

            Triangle triangle(vertex1, vertex2, vertex3);
            triangle.setNormalIndex(normalIndex - 1);
            // add normal to triangulation object
            triangulationObj.addTriangleToTriangulation(triangle);
        }
    }
    std::cout << "Data reading from .obj file completed successfully" << std::endl;
    // closing the file
    file.close();
}
