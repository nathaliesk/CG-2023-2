// sphere.cpp
// define a classe Sphere, que representa uma esfera e verifica interseções com raios.

#include "sphere.h"

/**
 * @brief Verifica se há interseção entre o raio e a esfera.
 * 
 * @param r Raio a ser verificado.
 * @param t_min Parâmetro mínimo do raio.
 * @param t_max Parâmetro máximo do raio.
 * @param rec Registro de colisão, caso haja interseção.
 * @return Verdadeiro se houver interseção, falso caso contrário.
 */
bool Sphere::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    Vec3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = dot(oc, r.direction());
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - a * c;

    if (discriminant > 0) {
        double temp = (-b - sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }
    return false;
}

/**
 * @brief Renderiza a esfera na tela.
 * 
 * @param renderer Renderizador SDL.
 * @param width Largura da janela de visualização.
 * @param height Altura da janela de visualização.
 */
void Sphere::render(SDL_Renderer* renderer, int width, int height) const {
    // Coordenadas da esfera na janela
    int x = int((center.x() + 1) * width / 2);
    int y = int((1 - center.y()) * height / 2);
    int scaled_radius = int(radius * width / 2);

    // Desenhar a esfera na tela
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(renderer, x, y);

    // Renderizar uma circunferência aproximada para representar a esfera
    for (int dx = -scaled_radius; dx <= scaled_radius; ++dx) {
        for (int dy = -scaled_radius; dy <= scaled_radius; ++dy) {
            if (dx * dx + dy * dy <= scaled_radius * scaled_radius) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}