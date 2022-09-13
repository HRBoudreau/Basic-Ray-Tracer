#include <hittable_object.hpp>
#include <ray.hpp>
#include <material.hpp>
#include <vector3.hpp>

HittableObject::HittableObject() {}

HittableObject::HittableObject(Material *material_)
            : material(material_) {}

ObjectList::ObjectList (const int& number_of_objects_) 
            : number_of_objects(number_of_objects_)
            {
                many_objects = new HittableObject*[number_of_objects];
        }

ObjectList::~ObjectList () {
            delete many_objects;
        }

bool ObjectList::hit(HitContainer* container_) {
            bool has_hit = false;
            for(int object_index = 0; object_index < number_of_objects; object_index++) {
                has_hit = many_objects[object_index]->hit(container_);
                if(has_hit) {
                    return true;
                }
            }
            return false;
        }

void reflect(const Vector3& intersect_, const Vector3& normal_, HitContainer* container_) {
    Vector3 out_direction = container_->ray.direction - 2*(normal_ * dot_product(container_->ray.direction, normal_));
    container_->ray = Ray(intersect_, out_direction);
}