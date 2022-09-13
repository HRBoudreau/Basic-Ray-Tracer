#ifndef RAY_TRACER_MATERIAL_HPP
#define RAY_TRACER_MATERIAL_HPP

#include <vector3.hpp>
class HitContainer;

class Material {
    public:
        Material(const Vector3& attenuation_);

        virtual void apply_material (const Vector3& intersect_, const Vector3& normal_, HitContainer* container_);

        Vector3 attenuation;
};

class Albedo : public Material {
    public :
        Albedo(const Vector3& attenuation_);

        void apply_material (const Vector3& intersect_, const Vector3& normal_, HitContainer* container_) override;
        
};

#endif // RAY_TRACER_MATERIAL_HPP