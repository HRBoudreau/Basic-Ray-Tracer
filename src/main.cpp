
#include <ray.hpp>
#include <camera.hpp>
#include <iostream>
#include <hittable_object.hpp>
#include <sphere.hpp>
#include <material.hpp>
#include <print_screen.hpp>

int main() {
    Camera camera;
    camera.field_of_view = 90.0;
    camera.width_in_pixels = 400;
    camera.height_in_pixels = 200;

    Albedo Al_1(Vector3(.52,.82,.15));
    Albedo Al_2(Vector3(.8,.2,.7));
    Albedo Al_3(Vector3(1,.3,.3));
    Albedo *Pal_1 = &Al_1;
    Albedo *Pal_2 = &Al_2;
    Albedo *Pal_3 = &Al_3;
    ObjectList world_objects(3);
    
    Sphere sphere_1(Vector3(-1,.5,-4), 0.5, Pal_1);
    Sphere sphere_2(Vector3(1,.5,-2), 0.3, Pal_2);
    Sphere sphere_3(Vector3(0,-101,-2), 100, Pal_3);
    world_objects.many_objects[0] = &sphere_1;
    world_objects.many_objects[1] = &sphere_2;
    world_objects.many_objects[2] = &sphere_3;

    std::string print_file = std::string("../test.ppm");
    print_screen(camera, world_objects, print_file);
}