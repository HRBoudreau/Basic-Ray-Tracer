#include <vector3.hpp>
#include <cmath>
#include <iostream>
#include <config.hpp>

float Vector3::length() const {
    return sqrt((x_val()*x_val()) + (y_val()*y_val()) + (z_val()*z_val()));
}

void Vector3::print_vector () const {
    std::cout << x_val() << " " << y_val() << " " << z_val() << "\n";
}

void Vector3::make_unit() {
    float length = this->length();
    element[0] = x_val()/length;
    element[1] = y_val()/length;
    element[2] = z_val()/length;
}

void Vector3::print_values() {
    std::cout << x_val() << " " << y_val() << " " << z_val() << "\n";
}

Vector3 operator+(const Vector3& vec_1, const Vector3& vec_2) {
    Vector3 vec_out;
    vec_out.element[0] = vec_1.x_val() + vec_2.x_val();
    vec_out.element[1] = vec_1.y_val() + vec_2.y_val();
    vec_out.element[2] = vec_1.z_val() + vec_2.z_val();
    return vec_out;
}

Vector3 operator-(const Vector3& vec_1, const Vector3& vec_2) {
    Vector3 vec_out;
    vec_out.element[0] = vec_1.x_val() - vec_2.x_val();
    vec_out.element[1] = vec_1.y_val() - vec_2.y_val();
    vec_out.element[2] = vec_1.z_val() - vec_2.z_val();
    return vec_out;
}

Vector3 operator*(const Vector3& vec_1, const Vector3& vec_2){
    Vector3 vec_out;
    vec_out.element[0] = vec_1.x_val() * vec_2.x_val();
    vec_out.element[1] = vec_1.y_val() * vec_2.y_val();
    vec_out.element[2] = vec_1.z_val() * vec_2.z_val();
    return vec_out;
}

Vector3 operator*(float constant, const Vector3& vec_1) {
    Vector3 vec_out;
    vec_out.element[0] = constant * vec_1.x_val();
    vec_out.element[1] = constant * vec_1.y_val();
    vec_out.element[2] = constant * vec_1.z_val();
    return vec_out;
}

Vector3 operator*(const Vector3& vec_1, float constant) {
    Vector3 vec_out;
    vec_out.element[0] = constant * vec_1.x_val();
    vec_out.element[1] = constant * vec_1.y_val();
    vec_out.element[2] = constant * vec_1.z_val();
    return vec_out;
}

Vector3 get_unit_vector(const Vector3& vec) {
    Vector3 unit_vector;
    unit_vector.element[0] = vec.x_val()/vec.length();
    unit_vector.element[1] = vec.y_val()/vec.length();
    unit_vector.element[2] = vec.z_val()/vec.length();
    return unit_vector;
}

float dot_product(const Vector3& vec_1, const Vector3 vec_2) {
    float out = vec_1.x_val() *vec_2.x_val() + vec_1.y_val() *vec_2.y_val() + vec_1.z_val() *vec_2.z_val();
    return out;
}

Vector3 cross_product(const Vector3& vec_1, const Vector3 vec_2) {
    Vector3 out_vec;
    out_vec.element[0] = vec_1.y_val()*vec_2.z_val() - vec_1.z_val()*vec_2.y_val();
    out_vec.element[1] = vec_1.z_val()*vec_2.x_val() - vec_1.x_val()*vec_2.z_val();
    out_vec.element[2] = vec_1.x_val()*vec_2.y_val() - vec_1.y_val()*vec_2.x_val();
    return out_vec;
}

Vector3 rotate(const Vector3& rotation_axis, const float& degrees, const Vector3& in_vec) {
    float radians = degrees*M_PI/360;
    Vector3 axis = rotation_axis;
    axis.make_unit();
    
    Vector3 axis_sin = sin(radians)*axis;
    Vector3 axis_sin_conjugate = -1*axis_sin;

    float first_quat_rotation_real = -1*dot_product(axis_sin, in_vec);
    Vector3 first_quat_rotation_imaginary = cos(radians)*in_vec + cross_product(axis_sin, in_vec);

    Vector3 second_quat_rotation_imaginary = first_quat_rotation_imaginary*cos(radians)
                                            + first_quat_rotation_real*axis_sin_conjugate
                                            + cross_product(first_quat_rotation_imaginary, axis_sin_conjugate);
    return second_quat_rotation_imaginary;
}