#include "CompositeDistanceEstimator.hpp"

double CompositeDistanceEstimator::get_distance(const Vector3 point) const {
  double min_dist = 99999999999999999999999.0;
  double dist = 0;

  for (auto &distance_estimator : children) {
    dist = distance_estimator->get_distance(point);
    if (dist < min_dist) {
      min_dist = dist;
    }
  }

  return dist;
}
