#include "hitable_list.h"
#include "sphere.h"
#include "camera.h"
#include "material_metal.h"
#include "material_glass.h"
#include "util.h"
#include "ray.h"
#include "vec3.h"

/**
 * @brief Função principal que renderiza a cena com objetos metálico e de vidro.
 */
int main() {
    // Configurações da imagem
    const int width = 800; /**< Largura da imagem */
    const int height = 400; /**< Altura da imagem */
    const int samples_per_pixel = 100; /**< Número de amostras por pixel */

    // Cabeçalho PPM
    std::cout << "P3\n" << width << " " << height << "\n255\n";

    // Lista de objetos da cena
    Hitable *list[2];
    list[0] = new Sphere(Vec3(0, 0, -1), 0.5, new MaterialMetal(Vec3(0.8, 0.8, 0.8), 0.3)); /**< Esfera metálica */
    list[1] = new Sphere(Vec3(0, -100.5, -1), 100, new MaterialGlass(1.5)); /**< Esfera de vidro */
    Hitable *world = new HitableList(list, 2); /**< Mundo da cena */

    // Câmera
    Camera cam;

    // Loop para renderizar cada pixel da imagem
    for (int j = height - 1; j >= 0; --j) {
        for (int i = 0; i < width; ++i) {
            Vec3 color(0, 0, 0);
            // Amostragem por pixel
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + random_double()) / width;
                double v = (j + random_double()) / height;
                Ray r = cam.get_ray(u, v);
                color += ray_color(r.origin(), r.direction(), world);
            }
            write_color(std::cout, color);
        }
    }

    return 0;
}