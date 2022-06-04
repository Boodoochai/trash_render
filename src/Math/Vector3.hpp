#ifndef VECTOR3_HEADER
#define VECTOR3_HEADER

#include <math.h>

class Vector3
{
public:
    double x;
    double y;
    double z;
    
    explicit Vector3() : x(0), y(0), z(0) {}
    explicit Vector3(const double arg1, const double arg2, const double arg3)
        : x(arg1), y(arg2), z(arg3) {}

    Vector3 operator+(const Vector3 arg) const;

    Vector3 operator-(const Vector3 arg) const;
       
    Vector3 &operator+=(const Vector3 arg);

    Vector3 &operator-=(const Vector3 arg);

    Vector3 operator/(const double arg) const;

    Vector3 operator*(const double arg) const;
    
    Vector3 &operator/=(const double arg);
    
    Vector3 &operator*=(const double arg);
    
    double length() const;

    Vector3 normalized() const;

    double dot_product(const Vector3 arg) const;

    Vector3 cross_product(const Vector3 arg) const;
};

Vector3 operator*(double arg1, Vector3 arg2);

#endif
