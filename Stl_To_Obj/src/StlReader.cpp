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

    // checks for file opening error
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

    // reads obj file line by line
    while (getline(file, line))
    {

        if (line.find("facet normal") != std::string::npos)
        {
            double x;
            double y;
            double z;
            std::istringstream facetNormalStream(line);
            std::string keywordFacet1;
            std::string keywordFacet2;
            facetNormalStream >> keywordFacet1 >> keywordFacet2 >> x >> y >> z;

            Point3D facetNormal(x, y, z);

            // searchs for facetNormal in the map
            auto iterator = normalIndexMap.find(facetNormal);
            if (iterator == normalIndexMap.end())
            {
                // if not found in map, adds facetNormal to map
                normalIndexMap[facetNormal] = triangulationObj.uniqueNormals().size();
                // adds normal to triangulation object
                triangulationObj.addUniqueNormalToTriangulation(facetNormal);
            }
            normalIndex = normalIndexMap[facetNormal];
        }

        if (line.find("vertex") != std::string::npos)
        {
            double x;
            double y;
            double z;
            std::istringstream vertexStream(line);
            std::string keywordVertex;
            vertexStream >> keywordVertex >> x >> y >> z;

            Point3D point(x, y, z);

            // searchs for point in the map
            auto iterator = pointIndexMap.find(point);
            if (iterator == pointIndexMap.end())
            {
                // if not found in map, adds point to map
                pointIndexMap[point] = triangulationObj.uniquePoints().size();
                // adds point to triangulation object
                triangulationObj.addUniquePointToTriangulation(point);
            }

            // get vertex indices
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
                // add triangle to triangulation object
                triangulationObj.addTriangleToTriangulation(triangle);
                count = 0;
            }
        }
    };
    std::cout << "Data reading from .stl file completed successfully" << std::endl;
    // closing the file
    file.close();
}
