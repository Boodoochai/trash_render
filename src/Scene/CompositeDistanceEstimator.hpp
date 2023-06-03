#ifndef COMPOSITE_DISTANCE_ESTIMATOR
#define COMPOSITE_DISTANCE_ESTIMATOR

#include <list>

#include "DistanceEstimator.hpp"
#include "Object.hpp"
#include "Vector3.hpp"

class CompositeDistanceEstimator : public DistanceEstimator {
private:
  std::list<const DistanceEstimator *> children;

public:
  CompositeDistanceEstimator(const std::list<Object *> objects) {
    for (auto &obj : objects) {
      children.push_back(obj->get_distance_estimator());
    }
  }

  double get_distance(const Vector3 point) const override;
};

#endif
