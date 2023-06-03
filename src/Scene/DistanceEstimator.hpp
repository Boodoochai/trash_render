#ifndef DISTANCE_ESTIMATOR_HEADER
#define DISTANCE_ESTIMATOR_HEADER

#include "Vector3.hpp"

class DistanceEstimator {
public:
  virtual double get_distance(const Vector3 point) const = 0;
};

#endif
