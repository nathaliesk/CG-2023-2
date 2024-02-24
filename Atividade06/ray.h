#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/**
 * @brief Classe que representa um raio no espaço tridimensional.
 */
class Ray {
public:
    /**
     * @brief Construtor padrão.
     */
    Ray() {}

    /**
     * @brief Construtor de inicialização.
     * 
     * @param origin Origem do raio.
     * @param direction Direção do raio.
     */
    Ray(const Vec3& origin, const Vec3& direction) : orig(origin), dir(direction) {}

    /**
     * @brief Retorna a origem do raio.
     * 
     * @return A origem do raio.
     */
    Vec3 origin() const { return orig; }

    /**
     * @brief Retorna a direção do raio.
     * 
     * @return A direção do raio.
     */
    Vec3 direction() const { return dir; }

    /**
     * @brief Retorna um ponto ao longo do raio com base em um parâmetro t.
     * 
     * @param t Parâmetro que indica a distância ao longo do raio.
     * @return O ponto ao longo do raio correspondente ao parâmetro t.
     */
    Vec3 at(double t) const { return orig + t * dir; }

    /**
     * @brief Calcula a cor de um raio.
     * 
     * @param r O raio para calcular a cor.
     * @return A cor calculada para o raio.
     */
    Vec3 ray_color(const Ray& r) {
        // Implementação da função para calcular a cor do raio
    }

private:
    Vec3 orig; ///< Origem do raio.
    Vec3 dir;  ///< Direção do raio.
};

#endif // RAY_H