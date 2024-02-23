#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"
#include "hitable.h"

/**
 * @class Material
 * @brief Classe abstrata que define a interface para materiais.
 * 
 * Esta classe serve como base para todos os materiais no sistema de ray tracing, 
 * definindo a função scatter que é responsável por determinar como os raios interagem 
 * com a superfície do material.
 */
class Material {
public:
    /**
     * @brief Método virtual puro para calcular o espalhamento de um raio ao atingir o material.
     * 
     * @param r_in O raio incidente.
     * @param rec Um registro contendo detalhes do ponto de interseção.
     * @param attenuation A atenuação da cor do raio após atingir o material.
     * @param scattered O raio espalhado resultante.
     * @return bool Indica se o raio foi espalhado.
     */
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif // MATERIAL_H