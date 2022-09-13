#ifndef RAY_TRACER_HITTABLE_OBJECT_HPP
#define RAY_TRACER_HITTABLE_OBJECT_HPP

class HitContainer;
#include <material.hpp>
class Vector3;

class HittableObject {
    public:
        HittableObject();
        HittableObject(Material *material_);

        virtual bool hit(HitContainer* container_) {return false;}

        Material *material;
};

class ObjectList : public HittableObject {
    public:
        ObjectList (const int& number_of_objects_);
        ~ObjectList ();

        bool hit(HitContainer* container_) override;

        HittableObject** many_objects;
        int number_of_objects;
};

void reflect(const Vector3& intersect_, const Vector3& normal_, HitContainer* container_);


#endif // RAY_TRACER_HITTABLE_OBJECT_HPP