#include <sphere.hpp>
#include <ray.hpp>
#include <hittable_object.hpp>
#include <iostream>
#include <cmath>
#include <vector3.hpp>
#include <material.hpp>

Sphere::Sphere(const Vector3& center_, float radius_, Material *material_)
    : center(center_), radius(radius_), HittableObject(material_) {}

bool Sphere::hit(HitContainer* container_) {
    if(container_->depth == 0) {
        return false;
    }

    float a = dot_product(container_->ray.direction, container_->ray.direction);
    float b = dot_product(2*container_->ray.direction, container_->ray.origin-center);
    float c = dot_product(container_->ray.origin-center, container_->ray.origin-center) - (radius*radius);
    float discriminant = b*b - 4*a*c;
    if (discriminant > 0) {

        float solution_to_quadratic = (-b - sqrt(discriminant))/(2*a);
        float solution_to_quadratic_2 = (-b + sqrt(discriminant))/(2*a);
        float choice_solution;
        
        if (solution_to_quadratic > 0) {
            choice_solution = solution_to_quadratic;
        } else if (solution_to_quadratic_2 > 0) {
            choice_solution = solution_to_quadratic_2;
        } else {
            return false;
        }

        container_->attenuation = material->attenuation;
        Vector3 intersect = container_->ray.origin + choice_solution*container_->ray.direction;
        Vector3 normal = intersect - center;
        normal.make_unit();
        material->apply_material(intersect, normal, container_);
        return true;

    } return false;
}