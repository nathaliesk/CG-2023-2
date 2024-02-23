#ifndef SPHERE_H
#define SPHERE_H

#include "hitable.h"
#include <memory>

/**
 * @class Sphere
 * @brief Classe que representa uma esfera no contexto de ray tracing.
 * 
 * Esta classe herda de Hitable e define uma esfera com um centro, raio e material específicos.
 * É capaz de determinar se um raio atinge a esfera e de calcular os detalhes da interseção.
 */
class Sphere : public Hitable {
public:
    Sphere() : center(Vec3()), radius(0) {}

    /**
     * @brief Constrói uma esfera com um centro, raio e material específicos.
     * 
     * @param cen O centro da esfera.
     * @param r O raio da esfera.
     * @param mat O material da esfera.
     */
    Sphere(const Vec3& cen, double r, std::shared_ptr<Material> mat)
        : center(cen), radius(r), material(mat) {}

    /**
     * @brief Determina se um raio intersecciona com a esfera.
     * 
     * Calcula se um raio atinge a esfera entre distâncias t_min e t_max e, em caso afirmativo,
     * preenche um registro de interseção com detalhes sobre a interseção.
     * 
     * @param r O raio para teste de interseção.
     * @param t_min O limite inferior do intervalo de teste.
     * @param t_max O limite superior do intervalo de teste.
     * @param rec Estrutura para armazenar os detalhes da interseção.
     * @return true se o raio intersecciona com a esfera, false caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

private:
    Vec3 center; ///< Centro da esfera.
    double radius; ///< Raio da esfera.
    std::shared_ptr<Material> material; ///< Material da esfera.
};

#endif // SPHERE_H