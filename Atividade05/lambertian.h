#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.h"

/**
 * @brief Classe para representar um material difuso com reflexão lambertiana.
 */
class Lambertian : public Material {
public:
    /**
     * @brief Construtor da classe Lambertian.
     * 
     * @param albedo Coeficiente de reflexão do material.
     */
    Lambertian(const Vec3& albedo) : albedo_(albedo) {}

    /**
     * @brief Função para calcular o espalhamento de um raio em um material difuso.
     * 
     * @param r_in Raio incidente.
     * @param rec Registro de colisão.
     * @param attenuation Atenuação do raio.
     * @param scattered Raio espalhado.
     * @return true Se ocorreu espalhamento, false caso contrário.
     */
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;

private:
    Vec3 albedo_; ///< Coeficiente de reflexão.
};

#endif // LAMBERTIAN_H