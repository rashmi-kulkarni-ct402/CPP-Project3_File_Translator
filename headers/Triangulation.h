#pragma once
#include "Point3D.h"
#include "Triangle.h"
#include <vector>

using namespace std;

namespace Shapes3D
{
    class Triangulation
    {
    public:
        Triangulation();
        ~Triangulation();

        vector<Point3D> &uniquePoints();
        vector<Triangle> &triangles();

    private:
        vector<Point3D> mUniquePoints;
        vector<Triangle> mTriangles;
    };
}