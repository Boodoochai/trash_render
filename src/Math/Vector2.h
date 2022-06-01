#ifndef VECTOR2_HEADER
#define VECTOR2_HEADER

#include <math.h>

class Vector2
{
public:
    double x;
    double y;
    
    explicit Vector2(const double a_x, const double a_y);

    Vector2 operator+(const Vector2 arg) const;

    Vector2 operator-(const Vector2 arg) const;
       
    Vector2 &operator+=(const Vector2 arg);

    Vector2 &operator-=(const Vector2 arg);

    Vector2 operator/(const double arg) const;

    Vector2 operator*(const double arg) const;
    
    Vector2 &operator/=(const double arg);
    
    Vector2 &operator*=(const double arg);

    double length();

    Vector2 normalized();
    
};

#endif
