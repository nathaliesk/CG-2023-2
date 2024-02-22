#ifndef SPHERE_H
#define SPHERE_H

#include "hitable.h"
#include "material.h"
#include "camera.h"
#include <SDL/SDL.h>
#include <memory> // para utilizar std::shared_ptr

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
    Sphere(Vec3 cen, double r, std::shared_ptr<Material> mat) : center(cen), radius(r), material(mat) {}

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

    /**
     * @brief Renderiza a esfera na tela.
     * 
     * @param renderer Renderizador SDL.
     * @param camera Camera utilizada para renderização.
     */
    virtual void render(SDL_Renderer* renderer, const Camera& camera) const;

private:
    Vec3 center; ///< Centro da esfera.
    double radius; ///< Raio da esfera.
    std::shared_ptr<Material> material; ///< Material da esfera.
};

#endif // SPHERE_H