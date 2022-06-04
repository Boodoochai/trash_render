#include "CompositeDistanceEstimator.hpp"

double CompositeDistanceEstimator::get_distance(const Vector3 point) const
{
    double min_dist = 99999999999999999999999.d;
    double dist = 0;

    for (auto &d_e : children) {
        dist = d_e->get_distance(point);
        if (dist < min_dist) {
            min_dist = dist;
        }
    }

    return dist;
}
