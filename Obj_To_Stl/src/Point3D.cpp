#include "../headers/Point3D.h"
#include <cmath>

Shapes3D::Point3D::Point3D() : mX(), mY(), mZ() {}
Shapes3D::Point3D::Point3D(double inX, double inY, double inZ) : mX(inX), mY(inY), mZ(inZ) {}
Shapes3D::Point3D::~Point3D() {}

double Shapes3D::Point3D::x() const
{
    return mX;
}

double Shapes3D::Point3D::y() const
{
    return mY;
}

double Shapes3D::Point3D::z() const
{
    return mZ;
}

bool Shapes3D::Point3D::operator<(const Point3D &other) const
{
    if (mX < other.mX)
        return true;
    if (mX > other.mX)
        return false;

    if (mY < other.mY)
        return true;
    if (mY > other.mY)
        return false;

    return mZ < other.mZ;
}

// Shapes3D::Point3D Shapes3D::Point3D::cross(const Point3D &v2) const
// {
//     double x = mY * v2.z() - mZ * v2.y();
//     double y = mZ * v2.x() - mX * v2.z();
//     double z = mX * v2.y() - mY * v2.x();
//     return Point3D(x, y, z);
// }

// Shapes3D::Point3D Shapes3D::Point3D::normalize() const
// {
//     double length = sqrt(mX * mX + mY * mY + mZ * mZ);
//     double x = mX / length;
//     double y = mY / length;
//     double z = mZ / length;
//     return Point3D(x, y, z);
// }
