#ifndef SPHERE_H
#define SPHERE_H

#include "hitable.h"
#include "material.h"

/**
 * @brief Classe para representar uma esfera.
 */
class Sphere : public Hitable {
public:
    Sphere() {} ///< Construtor padrão.
    
    /**
     * @brief Construtor da classe Sphere.
     * 
     * @param cen Centro da esfera.
     * @param r Raio da esfera.
     * @param mat Material da esfera.
     */
    Sphere(Vec3 cen, double r, Material *mat) : center(cen), radius(r), material(mat) {}

    /**
     * @brief Verifica se há interseção entre um raio e a esfera.
     * 
     * @param r Raio a ser verificado.
     * @param t_min Parâmetro mínimo do raio.
     * @param t_max Parâmetro máximo do raio.
     * @param rec Registro de colisão, se houver interseção.
     * @return true Se houve interseção, false caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

private:
    Vec3 center; ///< Centro da esfera.
    double radius; ///< Raio da esfera.
    Material *material; ///< Material da esfera.
};

#endif // SPHERE_H