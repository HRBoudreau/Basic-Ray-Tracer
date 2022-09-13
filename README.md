![Damn](https://user-images.githubusercontent.com/76916678/190011554-571edafa-1a03-40c0-8d93-1bf7745d3b79.jpg)
# Basic Ray Tracer
This basic ray tracer is based on [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley.

## Usage
 Everything you need is in src/main.cpp. 
 
 Class Albedo defines the albedo of an object. It takes a Vector3 which define how much Red Green and Blue it absorbs. The Albedo is then passed as a pointer into the Sphere Class.
 The Sphere class takes a location, in the form of a Vector3, a radius, and a pointer to an Albedo.
 To display a sphere add it to an ObjectList and pass that into print_screen.
 
 ## Example
  Albedo Al_1(Vector3(.52,.82.15));
  Sphere sphere(Vector3(-1,.5,-4),0.5,&Al_1);
  ObjectList world_objects(1);
  world_objects.many_objects[0] = &sphere;
  print_screen(camera,world-objects,path_to_file);
