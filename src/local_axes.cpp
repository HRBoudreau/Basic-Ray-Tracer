#include <vector3.hpp>
#include <local_axes.hpp>

LocalAxes::LocalAxes() {
    local_x_axis = Vector3(1,0,0);
    local_y_axis = Vector3(0,1,0);
    local_z_axis = Vector3(0,0,1);
}
LocalAxes::LocalAxes(const Vector3& local_x_axis_, const Vector3& local_y_axis_, const Vector3& local_z_axis_) {
    local_x_axis = local_x_axis_;
    local_y_axis = local_y_axis_;
    local_z_axis = local_z_axis_;
}