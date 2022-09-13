#include <vector3.hpp>
#include <ray.hpp>
#include <cmath>

Ray::Ray() 
    : origin(Vector3(0, 0, 0)), direction(Vector3(1,0,0)) {}

Ray::Ray(const Vector3& p_origin, const Vector3& p_direction)
    : origin(p_origin), direction(p_direction) {}

Vector3 Ray::ray_at_parameter(const float parameter) const{
    Vector3 vec_of_ray_at_parameter = origin + parameter*(direction - origin);
    return vec_of_ray_at_parameter;
}

Vector3 get_unit_circle() {
    int cycles = 0;
    while(cycles < 50) {
        float x = 2*fmod((float)rand(), .99999)-1;
        float z = 2*fmod((float)rand(), .99999)-1;
        if(x*z < 1) {
            return Vector3(x, z, 0);
        } else {
            cycles++;
        }
    }
    return Vector3(0,0,0);
}

Vector3 get_unit_sphere() {
    int cycles = 0;
    while(cycles < 50) {
        float x = 2*fmod(rand(), .99999)-1;
        float y = 2*fmod(rand(), .99999)-1;
        float z = 2*fmod(rand(), .99999)-1;
        if(x*y*z < 1) {
            return Vector3(x, y, z);
        } else {
            cycles++;
        }
    }
    return Vector3(0,0,0);
}