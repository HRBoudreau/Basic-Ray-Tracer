#include <vector3.hpp>
#include <local_axes.hpp>
#include <camera.hpp>


Camera::Camera() {
    field_of_view = 90.0;
    aspect_ratio = 2.0;
    width_in_pixels = 400;
    height_in_pixels = 200;
    camera_origin = Vector3(0,0,0);
    image_plane_distance = 1;
    local_axes = LocalAxes();
}