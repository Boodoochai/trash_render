#ifndef SPHERE_DISTANCE_ESTIMATOR
#define SPHERE_DISTANCE_ESTIMATOR

#include "DistanceEstimator.hpp"
#include "Vector3.hpp"

class Sphere;

class SphereDistanceEstimator : public DistanceEstimator
{
private:
    const Sphere *sphere;
public:
    SphereDistanceEstimator(const Sphere *obj) : sphere(obj) {}   

    double get_distance(const Vector3 point) const; 
};

#endif
