#include "sphere.h"
#include "camera.h"
#include <SDL/SDL.h>

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
 * @param camera Camera utilizada para renderização.
 */
void Sphere::render(SDL_Renderer* renderer, const Camera& camera) const {
    // Calcula o raio da esfera na tela
    int radius_screen = static_cast<int>(radius * camera.getScale());

    // Calcula a posição do centro da esfera na tela
    int center_x = static_cast<int>(center.x() * camera.getScale() + camera.getOffsetX());
    int center_y = static_cast<int>(center.y() * camera.getScale() + camera.getOffsetY());

    // Desenha os pontos ao longo da circunferência da esfera
    for (int y = -radius_screen; y <= radius_screen; ++y) {
        for (int x = -radius_screen; x <= radius_screen; ++x) {
            if (x * x + y * y <= radius_screen * radius_screen) {
                SDL_RenderDrawPoint(renderer, center_x + x, center_y + y);
            }
        }
    }
}
