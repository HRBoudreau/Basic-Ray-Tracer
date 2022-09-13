#ifndef RAY_TRACER_LOCAL_AXES_HPP
#define RAY_TRACER_LOCAL_AXES_HPP

#include <vector3.hpp>

class LocalAxes {
    public:
        LocalAxes();
        LocalAxes(const Vector3& local_x_axis_, const Vector3& local_y_axis_, const Vector3& local_z_axis_);

        Vector3 local_x_axis;
        Vector3 local_y_axis;
        Vector3 local_z_axis;
};

#endif // RAY_TRACER_LOCAL_AXES_HPP
