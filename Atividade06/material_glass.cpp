#include "material_glass.h"

/**
 * @brief Construtor da classe MaterialGlass.
 * 
 * @param ri Índice de refração do material de vidro.
 */
MaterialGlass::MaterialGlass(double ri) : refraction_idx_(ri) {}

/**
 * @brief Calcula a dispersão do raio ao interagir com o material de vidro.
 * 
 * @param r_in Raio de entrada.
 * @param rec Registro de colisão.
 * @param attenuation Atenuação do raio.
 * @param scattered Raio disperso.
 * @return true Se houver interação, false caso contrário.
 */
bool MaterialGlass::scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    attenuation = Vec3(1.0, 1.0, 1.0);
    double refraction_ratio = rec.front_face ? (1.0 / refraction_idx_) : refraction_idx_;

    Vec3 unit_direction = unit_vector(r_in.direction());
    double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    bool cannot_refract = refraction_ratio * sin_theta > 1.0;
    Vec3 direction;

    if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double()) {
        direction = reflect(unit_direction, rec.normal);
    } else {
        direction = refract(unit_direction, rec.normal, refraction_ratio);
    }

    scattered = Ray(rec.p, direction);
    return true;
}