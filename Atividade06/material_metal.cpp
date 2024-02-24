#include "material_metal.h"

/**
 * @brief Construtor da classe MaterialMetal.
 * 
 * @param albedo Cor do material.
 * @param fuzziness Grau de desfoque do material.
 */
MaterialMetal::MaterialMetal(const Vec3& albedo, double fuzziness) : albedo_(albedo), fuzziness_(fuzziness < 1 ? fuzziness : 1) {}

/**
 * @brief Calcula a dispersão do raio ao interagir com o material metálico.
 * 
 * @param r_in Raio de entrada.
 * @param rec Registro de colisão.
 * @param attenuation Atenuação do raio.
 * @param scattered Raio disperso.
 * @return true Se houver interação, false caso contrário.
 */
bool MaterialMetal::scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + fuzziness_ * random_in_unit_sphere());
    attenuation = albedo_;
    return (dot(scattered.direction(), rec.normal) > 0);
}