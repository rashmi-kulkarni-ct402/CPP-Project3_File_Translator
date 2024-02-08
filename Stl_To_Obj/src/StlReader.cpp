#include "../headers/StlReader.h"
#include "../headers/Triangulation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

Shapes3D::StlReader::StlReader() {}
Shapes3D::StlReader::~StlReader() {}

void Shapes3D::StlReader::read(const std::string &filePath, Triangulation &triangulationObj)
{
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        std::cout << "Error while opening the file." << std::endl;
    }

    int count = 0;
    int index1;
    int index2;
    int index3;
    int normalIndex = 0;
    std::string line;
    std::map<Point3D, int> pointIndexMap;
    std::map<Point3D, int> normalIndexMap;

    while (getline(file, line))
    {
        if (line.find("facet normal") != std::string::npos)
        {
            double x, y, z;
            std::istringstream facetNormalStream(line);
            std::string keywordFacet1, keywordFacet2;
            facetNormalStream >> keywordFacet1 >> keywordFacet2 >> x >> y >> z;

            Point3D facet(x, y, z);

            auto iterator = normalIndexMap.find(facet);
            if (iterator == normalIndexMap.end())
            {
                normalIndexMap[facet] = triangulationObj.uniqueNormals().size();
                triangulationObj.uniqueNormals().push_back(facet);
            }
            normalIndex = normalIndexMap[facet];
        }

        if (line.find("vertex") != std::string::npos)
        {
            double x, y, z;
            std::istringstream vertexStream(line);
            std::string keywordVertex;
            vertexStream >> keywordVertex >> x >> y >> z;

            Point3D point(x, y, z);

            auto iterator = pointIndexMap.find(point);
            if (iterator == pointIndexMap.end())
            {
                triangulationObj.uniquePoints().push_back(point);
                pointIndexMap[point] = triangulationObj.uniquePoints().size();
            }

            if (count == 0)
            {
                index1 = pointIndexMap[point];
                count++;
            }
            else if (count == 1)
            {
                index2 = pointIndexMap[point];
                count++;
            }
            else if (count == 2)
            {
                index3 = pointIndexMap[point];
                count++;
            }
            if (count == 3)
            {
                Triangle triangle(index1, index2, index3);
                triangle.setNormalIndex(normalIndex);
                triangulationObj.triangles().push_back(triangle);
                count = 0;
            }
        }
    };
    std::cout << "Data reading from .stl file completed successfully" << std::endl;
    file.close();
}
