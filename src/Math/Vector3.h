#ifndef VECTOR3_HEADER
#define VECTOR3_HEADER

#include <math.h>

class Vector3
{
public:
    double x;
    double y;
    double z;
    
    explicit Vector3(const double a_x, const double a_y, const double a_z);

    Vector3 operator+(const Vector3 arg) const;

    Vector3 operator-(const Vector3 arg) const;
       
    Vector3 &operator+=(const Vector3 arg);

    Vector3 &operator-=(const Vector3 arg);

    Vector3 operator/(const double arg) const;

    Vector3 operator*(const double arg) const;
    
    Vector3 &operator/=(const double arg);
    
    Vector3 &operator*=(const double arg);

    double length();

    Vector3 normalized();
  
    double dot_product(const Vector3 arg) const;
};

Vector3 operator*(double arg1, Vector3 arg2);

#endif
