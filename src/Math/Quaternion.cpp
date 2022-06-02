#include "Quaternion.hpp"

double Quaternion::absolute() const
{
    return sqrt(re*re + im.dot_product(im));
}

Quaternion Quaternion::conjugated() const
{
    return Quaternion(re, -1 * im);
}

Quaternion Quaternion::normalized() const
{
    return *this / this->absolute();
}

Quaternion Quaternion::inverse() const
{
    double a = this->absolute();
    return this->conjugated() / a*a;
}

double Quaternion::dot_product(const Quaternion arg) const
{
    return re*arg.re + im.x*arg.im.x + im.y*arg.im.y + im.z*arg.im.z;
}

Quaternion Quaternion::operator+(const Quaternion arg) const
{
    return Quaternion(re + arg.re, im + arg.im);
}

Quaternion &Quaternion::operator+=(const Quaternion arg)
{
    re += arg.re;
    im += arg.im;
    return *this;
}

Quaternion Quaternion::operator-(const Quaternion arg) const
{
    return Quaternion(re - arg.re, im - arg.im);
}

Quaternion &Quaternion::operator-=(const Quaternion arg)
{
    re -= arg.re;
    im -= arg.im;
    return *this;
}

Quaternion Quaternion::operator*(const Quaternion arg) const
{
    double a = re*arg.re - im.x*arg.im.x - im.y*arg.im.y - im.z*arg.im.z;
    Vector3 b = Vector3();
    b.x = re*arg.im.x + arg.re*im.x + im.y*arg.im.z - arg.im.y*im.z;
    b.y = re*arg.im.y + arg.re*im.y + im.z*arg.im.x - arg.im.z*im.x;
    b.z = re*arg.im.z + arg.re*im.z + im.x*arg.im.y - arg.im.x*im.y;
    return Quaternion(a, b);
}

Quaternion &Quaternion::operator*=(const Quaternion arg)
{
    re = re*arg.re - im.x*arg.im.x - im.y*arg.im.y - im.z*arg.im.z;
    im.x = re*arg.im.x + arg.re*im.x + im.y*arg.im.z - arg.im.y*im.z;
    im.y = re*arg.im.y + arg.re*im.y + im.z*arg.im.x - arg.im.z*im.x;
    im.z = re*arg.im.z + arg.re*im.z + im.x*arg.im.y - arg.im.x*im.y;
    return *this;
}

Quaternion Quaternion::operator*(const double arg) const
{
    return Quaternion(re * arg, im * arg);
}

Quaternion &Quaternion::operator*=(const double arg)
{
    re *= arg;
    im *= arg;
    return *this;
}

Quaternion Quaternion::operator/(const double arg) const
{
    return Quaternion(re / arg, im / arg);
}

Quaternion &Quaternion::operator/=(const double arg)
{
    re /= arg;
    im /= arg;
    return *this;
}

Quaternion operator*(const double arg1, const Quaternion arg2)
{
    return arg2 * arg1;
}
