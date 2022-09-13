#ifndef RAY_TRACER_RAY_HPP
#define RAY_TRACER_RAY_HPP

#include <vector3.hpp>

class Ray {
    public:
        Ray();
        Ray(const Vector3& p_origin, const Vector3& p_direction);
        
        Vector3 ray_at_parameter(const float parameter) const;

        Vector3 origin;
        Vector3 direction;
};

class HitContainer {
    public:
        HitContainer() 
            : depth(50) {}

        Vector3 attenuation;
        Ray ray;
        int depth;
};

Vector3 get_unit_sphere();

Vector3 get_unit_circle();

#endif // RAY_TRACER_RAY_HPP