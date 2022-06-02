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
    explicit Vector3(const double a_x, const double a_y, const double a_z)
        : x(a_x), y(a_y), z(a_z) {}

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
};

Vector3 operator*(double arg1, Vector3 arg2);

#endif
