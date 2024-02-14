#include "hitable_list.h"
#include "sphere.h"
#include "camera.h"
#include "material_metal.h"
#include "material_glass.h"

int main() {
    const int width = 800;
    const int height = 400;
    const int samples_per_pixel = 100;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    Hitable *list[2];
    list[0] = new Sphere(Vec3(0, 0, -1), 0.5, new MaterialMetal(Vec3(0.8, 0.8, 0.8), 0.3));
    list[1] = new Sphere(Vec3(0, -100.5, -1), 100, new MaterialGlass(1.5));
    Hitable *world = new HitableList(list, 2);

    Camera cam;

    for (int j = height - 1; j >= 0; --j) {
        for (int i = 0; i < width; ++i) {
            Vec3 color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + random_double()) / width;
                double v = (j + random_double()) / height;
                Ray r = cam.get_ray(u, v);
                color += ray_color(r, world, 0);
            }
            color.write_color(std::cout, samples_per_pixel);
        }
    }

    return 0;
}