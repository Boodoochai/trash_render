#include "TorusDistanceEstimator.hpp"

#include "Torus.hpp"

double TorusDistanceEstimator::get_distance(const Vector3 point) const
{
    Vector3 ao = torus->get_absolute_position() - point;
    Vector3 ah = ao.dot_product(torus->get_rotation()) * torus->get_rotation();
    Vector3 ho = ao - ah;
    Vector3 ho1 = ho * (1 - torus->get_major_radius() / ho.length());
    Vector3 ao1 = ah + ho1;
    Vector3 ax = ao1 * (1 - torus->get_minor_radius() / ao1.length());
    return ax.length();
}
