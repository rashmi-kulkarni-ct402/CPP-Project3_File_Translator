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

    // check for file opening error
    if (!file.is_open())
    {
        std::cout << "Error while opening .obj file." << std::endl;
        return;
    }

    std::string line;
    // reads obj line by line
    while (getline(file, line))
    {
        std::istringstream vertexStream(line);
        std::string keyword;
        vertexStream >> keyword;

        // checks if keyword is "v" (vertex)
        if (keyword == "v")
        {
            double x;
            double y;
            double z;
            vertexStream >> x >> y >> z;
            Point3D point(x, y, z);
            // adds point to the triangulation object
            triangulationObj.addUniquePointToTriangulation(point);
        }
        // checks if keyword is "f" (face)
        else if (keyword == "f")
        {
            std::string index1;
            std::string index2;
            std::string index3;
            vertexStream >> index1 >> index2 >> index3;

            std::vector<std::string> tokensV, tokensT, tokensN;

            std::stringstream vertexTokenStreamV(index1), vertexTokenStreamT(index2), vertexTokenStreamN(index3);
            std::string token;
            // tokenize vertex index
            while (getline(vertexTokenStreamV, token, '/'))
            {
                tokensV.push_back(token);
            }
            // tokenize texture index
            while (getline(vertexTokenStreamT, token, '/'))
            {
                tokensT.push_back(token);
            }
            // tokenize normal index
            while (getline(vertexTokenStreamN, token, '/'))
            {
                tokensN.push_back(token);
            };

            // get vertex indices
            int vertex1 = stoi(tokensV[0]) - 1;
            int vertex2 = stoi(tokensT[0]) - 1;
            int vertex3 = stoi(tokensN[0]) - 1;

            Triangle triangle(vertex1, vertex2, vertex3);
            // adds triangle to the triangulation object
            triangulationObj.addTriangleToTriangulation(triangle);
        }
    }

    std::cout << "Data reading from .obj file completed successfully" << std::endl;
    // closing the file
    file.close();
}
