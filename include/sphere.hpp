#ifndef RAY_TRACER_SPHERE_HPP
#define RAY_TRACER_SPHERE_HPP

#include <hittable_object.hpp>

class Material;
#include <vector3.hpp>

class Sphere : public HittableObject {
    public:
        Sphere(const Vector3& center_, float radius_, Material* material_);

        bool hit(HitContainer* container_) override;

        Vector3 center;
        float radius;
};

#endif // RAY_TRACER_SPHERE_HPP