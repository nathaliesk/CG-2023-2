// define a classe Sphere, que representa uma esfera e verifica interseções com raios.

#ifndef SPHERE_H
#define SPHERE_H

#include "hitable.h"

/**
 * @brief Classe para representar uma esfera.
 */
class Sphere : public Hitable {
public:
    Sphere() {} ///< Construtor padrão.
    Sphere(Vec3 cen, double r) : center(cen), radius(r) {} ///< Construtor.

    /**
     * @brief Verifica se há interseção entre o raio e a esfera.
     * 
     * @param r Raio a ser verificado.
     * @param t_min Parâmetro mínimo do raio.
     * @param t_max Parâmetro máximo do raio.
     * @param rec Registro de colisão, caso haja interseção.
     * @return Verdadeiro se houver interseção, falso caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

    /**
     * @brief Renderiza a esfera na tela.
     * 
     * @param renderer Renderizador SDL.
     * @param width Largura da janela.
     * @param height Altura da janela.
     */
    virtual void render(SDL_Renderer* renderer, int width, int height) const override;


private:
    Vec3 center; ///< Centro da esfera.
    double radius; ///< Raio da esfera.
};

#endif // SPHERE_H
