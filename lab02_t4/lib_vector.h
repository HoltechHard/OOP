#pragma once

class Vector{

    private:
        double x,y;

    public:
        Vector();
        Vector(double x, double y);
        Vector &operator=(const Vector &v);
        void print();
};
