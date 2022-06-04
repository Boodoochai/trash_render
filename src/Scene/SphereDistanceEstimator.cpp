#include "SphereDistanceEstimator.hpp"

#include "Sphere.hpp"

double SphereDistanceEstimator::get_distance(const Vector3 point) const
{
    Vector3 vec = point - sphere->get_absolute_position();
    return vec.length() - sphere->get_radius();
}
