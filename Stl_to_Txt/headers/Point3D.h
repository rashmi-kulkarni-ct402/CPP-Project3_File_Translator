#pragma once

namespace Shapes3D
{
    class Point3D
    {
    public:
        Point3D();
        Point3D(double inX, double inY, double inZ);
        ~Point3D();

        double x() const;
        double y() const;
        double z() const;
        bool operator<(const Point3D &other) const;
        // Point3D cross(const Point3D &v2) const;
        // Point3D normalize() const;

    private:
        double mX;
        double mY;
        double mZ;
    };
}
