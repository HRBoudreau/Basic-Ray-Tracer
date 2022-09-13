#include <material.hpp>
#include <hittable_object.hpp>
#include <ray.hpp>
#include <vector3.hpp>
#include <config.hpp>
#include <cmath>
#include <iostream>

Material::Material(const Vector3& attenuation_)
    : attenuation(attenuation_) {}

void Material::apply_material (const Vector3& intersect_, const Vector3& normal_, HitContainer* container_) {
    std::cout << "NOT FUCKING RIGHT\n";
}

Albedo::Albedo(const Vector3& attenuation_)
    : Material(attenuation_) {}

void Albedo::apply_material (const Vector3& intersect_, const Vector3& normal_, HitContainer* container_) {
    float raw_number = fmod(rand(), .99999);
    float weighted_number = asin(2*raw_number-1);
    Vector3 normal_cross_vector = Vector3(normal_.x_val()-.1,normal_.y_val()-.1,normal_.z_val()-.1);
    Vector3 tangent = cross_product(normal_, normal_cross_vector);
    tangent.make_unit();
    Vector3 out_vec = cos(weighted_number)*normal_+sin(weighted_number)*tangent;
    float random_number = fmod(rand(), .99999);
    random_number = random_number * 2*M_PI;
    out_vec = rotate(normal_, random_number, out_vec) * container_->ray.direction.length();
    container_->ray = Ray(intersect_, out_vec);
    container_->attenuation = attenuation;
}
