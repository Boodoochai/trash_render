#include "Vector2.hpp"

Vector2 Vector2::operator+(const Vector2 arg) const 
{
    return Vector2(x + arg.x, y + arg.y);
}

Vector2 Vector2::operator-(const Vector2 arg) const 
{
    return Vector2(x - arg.x, y - arg.y);
}

Vector2 &Vector2::operator+=(const Vector2 arg) 
{   
    x += arg.x;
    y += arg.y;
    return *this;
}

Vector2 &Vector2::operator-=(const Vector2 arg) 
{
    x -= arg.x;
    y -= arg.y;
    return *this;
}

Vector2 Vector2::operator/(const double arg) const 
{
    return Vector2(x / arg, y / arg);
}

Vector2 Vector2::operator*(const double arg) const 
{
    return Vector2(x * arg, y * arg);
}

Vector2 &Vector2::operator/=(const double arg) 
{
    x /= arg;
    y /= arg;
    return *this;
}

Vector2 &Vector2::operator*=(const double arg) 
{
    x *= arg;
    y *= arg;
    return *this;
}

double Vector2::length() 
{
    return sqrt(x*x + y*y);
}

Vector2 Vector2::normalized() 
{
    return *this / this->length();
}
