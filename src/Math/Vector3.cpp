#include "Vector3.hpp"

Vector3 Vector3::operator+(const Vector3 arg) const 
{
    return Vector3(x + arg.x, y + arg.y, z + arg.z);
}

Vector3 Vector3::operator-(const Vector3 arg) const 
{
    return Vector3(x - arg.x, y - arg.y, z - arg.z);
}

Vector3 &Vector3::operator+=(const Vector3 arg) 
{   
    x += arg.x;
    y += arg.y;
    z += arg.z;
    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 arg) 
{
    x -= arg.x;
    y -= arg.y;
    z -= arg.z;
    return *this;
}

Vector3 Vector3::operator/(const double arg) const 
{
    return Vector3(x / arg, y / arg, z / arg);
}

Vector3 Vector3::operator*(const double arg) const 
{
    return Vector3(x * arg, y * arg, z * arg);
}

Vector3 &Vector3::operator/=(const double arg) 
{
    x /= arg;
    y /= arg;
    z /= arg;
    return *this;
}

Vector3 &Vector3::operator*=(const double arg) 
{
    x *= arg;
    y *= arg;
    z *= arg;
    return *this;
}

double Vector3::dot_product(const Vector3 arg) const
{
    return arg.x * x + arg.y * y + arg.z * z;
}

double Vector3::length() const
{
    return sqrt(x*x + y*y + z*z);
}

Vector3 Vector3::normalized() const
{
    return *this / this->length();
}

Vector3 operator*(double arg1, Vector3 arg2)
{
    return arg2 * arg1;
}
