#include "../headers/Triangulation.h"
#include "../headers/Point3D.h"
#include "../headers/Triangle.h"
#include <vector>

Shapes3D::Triangulation::Triangulation()
{
}

Shapes3D::Triangulation::~Triangulation()
{
}

std::vector<Shapes3D::Point3D> &Shapes3D::Triangulation::uniquePoints()
{
    return mUniquePoints;
}

std::vector<Shapes3D::Triangle> &Shapes3D::Triangulation::triangles()
{
    return mTriangles;
}

std::vector<Shapes3D::Point3D> &Shapes3D::Triangulation::normals()
{
    return mNormals;
}