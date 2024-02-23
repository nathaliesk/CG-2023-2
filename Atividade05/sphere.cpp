#include "sphere.h"
#include <cmath> // Necessário para cálculos matemáticos como sqrt

/**
 * @brief Verifica se há interseção entre o raio e a esfera.
 * 
 * Calcula a interseção do raio com a esfera usando a fórmula quadrática. Se houver interseção,
 * atualiza o registro de colisão com informações sobre a interseção mais próxima.
 * 
 * @param r Raio a ser verificado.
 * @param t_min Parâmetro mínimo do raio.
 * @param t_max Parâmetro máximo do raio.
 * @param rec Registro de colisão, caso haja interseção.
 * @return Verdadeiro se houver interseção, falso caso contrário.
 */
bool Sphere::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    Vec3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius*radius;
    double discriminant = half_b*half_b - a*c;

    if (discriminant > 0) {
        double sqrtD = sqrt(discriminant);
        // Encontra a raiz mais próxima que está dentro do intervalo aceitável
        double root = (-half_b - sqrtD) / a;
        if (root < t_min || t_max < root) {
            root = (-half_b + sqrtD) / a;
            if (root < t_min || t_max < root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        rec.normal = (rec.p - center) / radius;
        rec.mat_ptr = material.get(); // Assume-se que material é um std::shared_ptr<Material>
        return true;
    }
    return false;
}