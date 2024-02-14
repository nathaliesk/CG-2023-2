#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"
#include "hitable.h"

/**
 * @brief Classe abstrata para definir um material de um objeto.
 */
class Material {
public:
    /**
     * @brief Função para calcular o espalhamento de um raio em um material.
     * 
     * @param r_in Raio incidente.
     * @param rec Registro de colisão.
     * @param attenuation Atenuação do raio.
     * @param scattered Raio espalhado.
     * @return true Se ocorreu espalhamento, false caso contrário.
     */
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif // MATERIAL_H