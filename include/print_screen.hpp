#ifndef RAY_TRACER_PRINT_SCREEN_HPP
#define RAY_TRACER_PRINT_SCREEN_HPP

#include <string>
class Camera;
class HittableObject;
class HitContainer;
class Vector3;

void print_screen(const Camera& camera_, HittableObject& world_objects_, std::string& file_name_);

Vector3 get_color (HittableObject& world_objects_, HitContainer* container_);

#endif // RAY_TRACER_PRINT_SCREEN_HPP