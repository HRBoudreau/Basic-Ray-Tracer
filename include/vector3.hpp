#ifndef RAY_TRACER_VECTOR3_HPP
#define RAY_TRACER_VECTOR3_HPP

#include <iostream>

class Vector3 {
    public:
        Vector3 () 
            : element{0, 0, 0} {}
        Vector3 (float x_val, float y_val, float z_val)
            : element{x_val, y_val, z_val} {}

        float x_val() const { return element[0]; }
        float y_val() const { return element[1]; }
        float z_val() const { return element[2]; }

        void print_vector () const;

        float length () const;

        void make_unit();

        void print_values();
        
        float element[3];
};

Vector3 operator+(const Vector3& vec_1, const Vector3& vec_2);

Vector3 operator-(const Vector3& vec_1, const Vector3& vec_2);

Vector3 operator*(const Vector3& vec_1, const Vector3& vec_2);

Vector3 operator*(float constant, const Vector3& vec_1);

Vector3 operator*(const Vector3& vec_1, float constant);

Vector3 get_unit_vector(const Vector3& vec);

float dot_product(const Vector3& vec_1, const Vector3 vec_2);

Vector3 cross_product(const Vector3& vec_1, const Vector3 vec_2);

Vector3 rotate(const Vector3& rotation_axis, const float& degrees, const Vector3& in_vec);

#endif // RAY_TRACER_VECTOR3_HPP