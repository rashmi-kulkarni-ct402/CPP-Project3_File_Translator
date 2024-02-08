#pragma once
#include "Point3D.h"

namespace Shapes3D
{
    class Triangle
    {
    public:
        Triangle();
        Triangle(int inIndex1, int inIndex2, int inIndex3, int inNormalIndex);
        ~Triangle();

        int index1() const;
        int index2() const;
        int index3() const;
        int normalIndex() const;

        void setindex1(int inIndex1);
        void setindex2(int inIndex2);
        void setindex3(int inIndex3);

    private:
        int mIndex1;
        int mIndex2;
        int mIndex3;
        int mNormalIndex;
    };
}
