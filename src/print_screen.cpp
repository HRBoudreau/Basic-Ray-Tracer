#include <print_screen.hpp>
#include <camera.hpp>
#include <config.hpp>
#include <hittable_object.hpp>
#include <vector3.hpp>
#include <string>
#include <ray.hpp>
#include <fstream>
#include <cmath>

void print_screen(const Camera& camera_, HittableObject& world_objects_, std::string& file_name_) {
    HitContainer container;
    HitContainer* container_p = &container;

    float image_plane_width =                                                                               //image plane width                 _____width______
        2*camera_.image_plane_distance*tan(camera_.field_of_view*M_PI/360);                                 //                                  |              |
    float image_plane_height = image_plane_width/camera_.aspect_ratio;                                      //image plane height                |              | height
    Vector3 image_plane_bottom_left_corner =                                                                //image plane bottom left corner--->|______________|
        Vector3(-(image_plane_width*0.5),-(image_plane_height*0.5), -camera_.image_plane_distance)
        + camera_.camera_origin;

    std::ofstream file;
    file.open(file_name_.c_str());
    file << "P3\n" << camera_.width_in_pixels << " " << camera_.height_in_pixels << "\n255\n";

    for(int y_offset = camera_.height_in_pixels-1; y_offset >= 0; y_offset--) {                //loop to find color of each pixel
        for(int x_offset = 0; x_offset < camera_.width_in_pixels; x_offset++) {

            Ray passed_ray = Ray(camera_.camera_origin, image_plane_bottom_left_corner
                + ((x_offset/camera_.width_in_pixels) * (image_plane_width) * (camera_.local_axes.local_x_axis))
                + ((y_offset/camera_.height_in_pixels) * (image_plane_height) * (camera_.local_axes.local_y_axis)) 
                -camera_.camera_origin);
            Vector3 samples_added_together(0,0,0);
            Vector3 color_of_pixel;

            for (int samples = 0; samples < 40; samples++) {
                Ray adjusted_ray = passed_ray;
                Vector3 unit_circle = get_unit_circle();
                adjusted_ray.direction = adjusted_ray.direction + unit_circle*(1.0/200.0);
                container_p->ray = adjusted_ray;
                container_p->depth = 40;
                color_of_pixel = get_color(world_objects_, container_p);
                //std::cout << color_of_pixel.x_val() << " " << color_of_pixel.y_val() << " " << color_of_pixel.z_val() << "\n";
                samples_added_together = samples_added_together + color_of_pixel;
            }
                color_of_pixel = samples_added_together*(1.0/40.0);
            
            file << 200.99*color_of_pixel.x_val() << " " << 255.99*color_of_pixel.y_val() << " " << 255.99*color_of_pixel.z_val() << "\n";
            
        }
    }
}



Vector3 get_color (HittableObject& world_objects_, HitContainer* container_) {
    if(world_objects_.hit(container_)) {
        container_->depth--;
        Vector3 attenuation = container_->attenuation;
        return get_color(world_objects_, container_)*attenuation;;
    } else {
        Vector3 unit_direction = get_unit_vector(container_->ray.direction);
        unit_direction.element[0]= std::abs(unit_direction.element[0]);
        unit_direction.element[1]= std::abs(unit_direction.element[1]);
        unit_direction.element[2]= std::abs(unit_direction.element[2]);
        
        return Vector3((1+unit_direction.y_val()*unit_direction.y_val()-unit_direction.y_val()*2)*0.7,(1+unit_direction.y_val()*unit_direction.y_val()-unit_direction.y_val()*2)*0.5,.8+(unit_direction.y_val()*0.2));
    }
}