// Este arquivo define a classe abstrata Hitable, que representa objetos que podem ser atingidos por raios.

#ifndef HITABLE_H
#define HITABLE_H

#include "ray.h"

/**
 * @brief Estrutura para representar um registro de colisão.
 */
struct HitRecord {
    Vec3 p; ///< Ponto de colisão.
    Vec3 normal; ///< Vetor normal no ponto de colisão.
    double t; ///< Parâmetro do raio para o ponto de colisão.
};

/**
 * @brief Classe abstrata para objetos que podem ser atingidos por raios.
 */
class Hitable {
public:
    /**
     * @brief Verifica se há interseção entre o raio e o objeto.
     * 
     * @param r Raio a ser verificado.
     * @param t_min Parâmetro mínimo do raio.
     * @param t_max Parâmetro máximo do raio.
     * @param rec Registro de colisão, caso haja interseção.
     * @return Verdadeiro se houver interseção, falso caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};

#endif // HITABLE_H