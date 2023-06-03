#ifndef TORUS_DISTANCE_ESTIMATOR
#define TORUS_DISTANCE_ESTIMATOR

#include "DistanceEstimator.hpp"
#include "Vector3.hpp"

class Torus;

class TorusDistanceEstimator : public DistanceEstimator {
private:
  const Torus *torus;

public:
  TorusDistanceEstimator(const Torus *torus) : torus(torus) {}

  double get_distance(const Vector3 point) const override;
};

#endif
