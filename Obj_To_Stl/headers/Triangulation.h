#pragma once
#include "Point3D.h"
#include "Triangle.h"
#include <vector>

namespace Shapes3D
{
    class Triangulation
    {
    public:
        Triangulation();
        ~Triangulation();

        std::vector<Point3D> &uniquePoints();
        std::vector<Triangle> &triangles();
        std::vector<Point3D> &uniqueNormals();

    private:
        std::vector<Point3D> mUniquePoints;
        std::vector<Triangle> mTriangles;
        std::vector<Point3D> mUniqueNormals;
    };
}