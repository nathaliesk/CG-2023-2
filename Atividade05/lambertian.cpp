// lambertian.cpp
#include "lambertian.h"

/**
 * @brief Construtor da classe Lambertian.
 * 
 * @param albedo Coeficiente de reflexão do material.
 */
Lambertian::Lambertian(const Vec3& albedo) : albedo_(albedo) {}

/**
 * @brief Função para calcular o espalhamento de um raio em um material difuso.
 * 
 * @param r_in Raio incidente.
 * @param rec Registro de colisão.
 * @param attenuation Atenuação do raio.
 * @param scattered Raio espalhado.
 * @return true Se ocorreu espalhamento, false caso contrário.
 */
bool Lambertian::scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 target = rec.p + rec.normal + random_in_unit_sphere();
    scattered = Ray(rec.p, target - rec.p);
    attenuation = albedo_;
    return true;
}