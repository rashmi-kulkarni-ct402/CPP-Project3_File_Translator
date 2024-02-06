#include "../headers/StlReader.h"
#include "../headers/Triangulation.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

Shapes3D::StlReader::StlReader() {}
Shapes3D::StlReader::~StlReader() {}

void Shapes3D::StlReader::read(const string &filePath, Triangulation &triangulationObj)
{
    ifstream file(filePath);

    if (!file.is_open())
    {
        std::cout << "Error while opening the file." << endl;
    }

    int count = 0;
    int index1;
    int index2;
    int index3;
    string line;
    string keyword;
    map<Point3D, int> pointIndexMap;

    while (getline(file, line))
    {
        istringstream iss(line);

        if (line.find("vertex") != string::npos)
        {
            double x1, y1, z1;
            iss >> keyword >> x1 >> y1 >> z1;

            Point3D point(x1, y1, z1);

            auto iterator = pointIndexMap.find(point);
            if (iterator == pointIndexMap.end())
            {
                pointIndexMap[point] = triangulationObj.uniquePoints().size();
                triangulationObj.uniquePoints().push_back(point);
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

                cout << index1 << " " << index2 << " " << index3 << endl;
                triangulationObj.triangles().push_back(Triangle(index1, index2, index3));
                count = 0;
            }
        }
    };
    std::cout << "Data reading from .stl file completed successfully" << endl;
    file.close();
}