#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.h"
#include "vec3.h"

/**
 * @class Lambertian
 * @brief Representa um material difuso com reflexão lambertiana.
 * 
 * Este material simula superfícies ideais sem brilho que espalham a luz igualmente em todas as direções.
 */
class Lambertian : public Material {
public:
    /**
     * @brief Constrói um material Lambertian com um dado albedo.
     * 
     * @param albedo O coeficiente de reflexão do material, que afeta a cor percebida do material.
     */
    Lambertian(const Vec3& albedo);

    /**
     * @brief Calcula o espalhamento de um raio que atinge o material.
     * 
     * @param r_in O raio incidente.
     * @param rec Um registro contendo detalhes da interseção do raio com o objeto.
     * @param attenuation A atenuação da luz devido à interseção.
     * @param scattered O raio espalhado resultante.
     * @return bool Verdadeiro se o raio foi espalhado, falso caso contrário.
     */
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;

private:
    Vec3 albedo_; ///< O albedo do material.
};

#endif // LAMBERTIAN_H