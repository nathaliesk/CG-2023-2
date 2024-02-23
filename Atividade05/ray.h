#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/**
 * @class Ray
 * @brief Representa um raio no espaço tridimensional.
 * 
 * Esta classe é usada para modelar raios de luz na simulação de ray tracing, armazenando a origem e a direção do raio.
 */
class Ray {
public:
    /**
     * @brief Construtor padrão que inicializa um raio com origem e direção zeradas.
     */
    Ray() : orig(Vec3()), dir(Vec3()) {}

    /**
     * @brief Construtor que inicializa um raio com uma origem e direção específicas.
     * 
     * @param origin A origem do raio.
     * @param direction A direção do raio.
     */
    Ray(const Vec3& origin, const Vec3& direction) : orig(origin), dir(direction) {}

    /**
     * @brief Retorna a origem do raio.
     * 
     * @return A origem do raio como um vetor tridimensional.
     */
    Vec3 origin() const { return orig; }

    /**
     * @brief Retorna a direção do raio.
     * 
     * @return A direção do raio como um vetor tridimensional.
     */
    Vec3 direction() const { return dir; }

    /**
     * @brief Calcula e retorna a posição do raio em um parâmetro t.
     * 
     * Isso permite encontrar pontos ao longo do raio a partir da origem na direção do raio.
     * 
     * @param t O parâmetro que define a distância ao longo do raio a partir da origem.
     * @return O ponto no espaço tridimensional correspondente ao valor de t.
     */
    Vec3 at(double t) const { return orig + t * dir; }

private:
    Vec3 orig; ///< A origem do raio.
    Vec3 dir;  ///< A direção do raio.
};

#endif // RAY_H