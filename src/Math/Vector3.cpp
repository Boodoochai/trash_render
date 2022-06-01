#include "Vector3.h"

Vector3::Vector3(const double a_x, const double a_y, const double a_z)
    : x(a_x), y(a_y), z(a_z)
{

}

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

double Vector3::length() 
{
    return sqrt(x*x + y*y + z*z);
}

Vector3 Vector3::normalized() 
{
    return *this / this->length();
}

double Vector3::dot_product(const Vector3 arg) const
{
    return arg.x * x + arg.y * y + arg.z * z;
}

Vector3 operator*(double arg1, Vector3 arg2)
{
    return arg2 * arg1;
}
