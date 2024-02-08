#include "../headers/Triangle.h"

Shapes3D::Triangle::Triangle() {}
Shapes3D::Triangle::Triangle(int inIndex1, int inIndex2, int inIndex3, int inNormalIndex) : mIndex1(inIndex1), mIndex2(inIndex2), mIndex3(inIndex3), mNormalIndex(inNormalIndex) {}
Shapes3D::Triangle::~Triangle() {}

int Shapes3D::Triangle::index1() const
{
    return mIndex1;
}

int Shapes3D::Triangle::index2() const
{
    return mIndex2;
}

int Shapes3D::Triangle::index3() const
{
    return mIndex3;
}

int Shapes3D::Triangle::normalIndex() const
{
    return mNormalIndex;
}

void Shapes3D::Triangle::setindex1(int inIndex1)
{
    mIndex1 = inIndex1;
}

void Shapes3D::Triangle::setindex2(int inIndex2)
{
    mIndex2 = inIndex2;
}

void Shapes3D::Triangle::setindex3(int inIndex3)
{
    mIndex3 = inIndex3;
}
