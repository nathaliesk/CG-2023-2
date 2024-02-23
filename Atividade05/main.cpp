/**
 * @file main.cpp
 * @brief Sistema de renderização de objetos 3D com materiais difusos, implementando ray tracing.
 * 
 * Este programa demonstra a renderização de uma cena simples contendo esferas com materiais difusos,
 * utilizando o conceito de ray tracing. Suporta a visualização de dois pontos de vista diferentes,
 * permitindo ao usuário alternar entre eles durante a execução.
 */

#include "sphere.h"
#include "lambertian.h"
#include "camera.h"
#include "vec3.h"
#include "hitable_list.h"
#include <iostream>
#include <cfloat> // Para acesso a DBL_MAX
#include <cstdlib> // Para acesso a rand()
#include <SDL/SDL.h> // Para eventos de teclado e inicialização da SDL

/**
 * @brief Calcula a cor de um raio que atinge um objeto na cena.
 * 
 * @param r O raio a ser verificado.
 * @param world O mundo que contém a lista de objetos hitables.
 * @return Vec3 A cor resultante após o raio atingir um objeto ou o fundo.
 */
Vec3 color(const Ray& r, Hitable *world) {
    HitRecord rec;
    if (world->hit(r, 0.001, DBL_MAX, rec)) {
        Vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * color(Ray(rec.p, target - rec.p), world);
    } else {
        Vec3 unit_direction = unit_vector(r.direction());
        double t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
    }
}

int main() {
    int nx = 200; ///< Largura da imagem.
    int ny = 100; ///< Altura da imagem.
    int ns = 100; ///< Número de amostras por pixel.

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    Hitable *list[3]; ///< Lista de objetos na cena.
    // Inicialização dos objetos na cena.
    list[0] = new Sphere(Vec3(0, 0, -1), 0.5, std::make_shared<Lambertian>(Vec3(0.8, 0.3, 0.3)));
    list[1] = new Sphere(Vec3(0, -100.5, -1), 100, std::make_shared<Lambertian>(Vec3(0.8, 0.8, 0.0)));
    list[2] = new Sphere(Vec3(1, 0, -1), 0.5, std::make_shared<Lambertian>(Vec3(0.3, 0.8, 0.3)));
    Hitable *world = new HitableList(list, 3);

    Camera cam1(Vec3(3, 3, 2), Vec3(0, 0, -1), Vec3(0, 1, 0), 20, double(nx) / double(ny));
    Camera cam2(Vec3(-2, 2, 1), Vec3(0, 0, -1), Vec3(0, 1, 0), 20, double(nx) / double(ny));
    Camera* currentCam = &cam1;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("Ray Tracing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, nx, ny, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false; ///< Controla o loop principal.
    SDL_Event event; ///< Eventos SDL.
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_1:
                        currentCam = &cam1;
                        break;
                    case SDLK_2:
                        currentCam = &cam2;
                        break;
                }
            }
        }

        // Renderização da cena.
        for (int j = ny - 1; j >= 0; j--) {
            for (int i = 0; i < nx; i++) {
                Vec3 col(0,0, 0);
                for (int s = 0; s < ns; s++) {
                    double u = double(i + rand()) / double(nx);
                    double v = double(j + rand()) / double(ny);
                    Ray r = currentCam->get_ray(u, v);
                    col += color(r, world);
                }
                col /= double(ns);
                col = Vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
                int ir = int(255.99 * col[0]);
                int ig = int(255.99 * col[1]);
                int ib = int(255.99 * col[2]);
                SDL_SetRenderDrawColor(renderer, ir, ig, ib, 255);
                SDL_RenderDrawPoint(renderer, i, ny - j - 1);
            }
        }
        SDL_RenderPresent(renderer);
    }

    // Liberação de recursos e finalização do SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}







// main.cpp
// Sistema de renderização de objetos 3D com materiais difusos

// #include "sphere.h"
// #include "lambertian.h"
// #include "camera.h"
// #include "vec3.h"
// #include <iostream>
// #include <cfloat> // Para acesso a DBL_MAX
// #include <cstdlib> // Para acesso a rand()
// #include <SDL/SDL.h> // Para eventos de teclado

// /**
//  * @brief Calcula a cor de um raio que atinge um objeto.
//  * 
//  * @param r Raio a ser verificado.
//  * @param world Lista de objetos na cena.
//  * @return Vec3 Cor resultante do raio.
//  */
// Vec3 color(const Ray& r, Hitable *world) {
//     HitRecord rec;
//     if (world->hit(r, 0.001, DBL_MAX, rec)) { // Correção: alteração de 0.0 para 0.001 para evitar problemas de precisão
//         // Usando um material difuso
//         Vec3 target = rec.p + rec.normal + random_in_unit_sphere();
//         return 0.5 * color(Ray(rec.p, target - rec.p), world);
//     } else {
//         Vec3 unit_direction = unit_vector(r.direction());
//         double t = 0.5 * (unit_direction.y() + 1.0);
//         return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
//     }
// }

// int main() {
//     int nx = 200;
//     int ny = 100;
//     int ns = 100;

//     std::cout << "P3\n" << nx << " " << ny << "\n255\n";

//     Hitable *list[3];
//     list[0] = new Sphere(Vec3(0, 0, -1), 0.5, std::make_shared<Lambertian>(Vec3(0.8, 0.3, 0.3)));
//     list[1] = new Sphere(Vec3(0, -100.5, -1), 100, std::make_shared<Lambertian>(Vec3(0.8, 0.8, 0.0)));
//     list[2] = new Sphere(Vec3(1, 0, -1), 0.5, std::make_shared<Lambertian>(Vec3(0.3, 0.8, 0.3)));
//     Hitable *world = new HitableList(list, 3);

//     Camera cam(Vec3(3, 3, 2), Vec3(0, 0, -1), Vec3(0, 1, 0), 20, double(nx) / double(ny));

//     for (int j = ny - 1; j >= 0; j--) {
//         for (int i = 0; i < nx; i++) {
//             Vec3 col(0, 0, 0);
//             for (int s = 0; s < ns; s++) {
//                 double u = double(i + rand()) / double(nx); // Correção: substituição de drand48 por rand()
//                 double v = double(j + rand()) / double(ny); // Correção: substituição de drand48 por rand()
//                 Ray r = cam.get_ray(u, v);
//                 col += color(r, world);
//             }
//             col /= double(ns);
//             col = Vec3(sqrt(col.x()), sqrt(col.y()), sqrt(col.z())); // Correção: uso de x(), y(), z() em vez de []
//             int ir = int(255.99 * col.x());
//             int ig = int(255.99 * col.y());
//             int ib = int(255.99 * col.z());
//             std::cout << ir << " " << ig << " " << ib << "\n";
//         }
//     }

//     return 0;
// }
