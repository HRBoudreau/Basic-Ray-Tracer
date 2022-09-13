#ifndef RAY_TRACER_CAMERA_HPP
#define RAY_TRACER_CAMERA_HPP

#include <local_axes.hpp>
#include <vector3.hpp>

class Camera {
    public:
        Camera();

        float field_of_view;
        float aspect_ratio;
        float image_plane_distance;
        float width_in_pixels;
        float height_in_pixels;
        Vector3 camera_origin;
        LocalAxes local_axes;
};

#endif // RAY_TRACER_CAMERA_HPP