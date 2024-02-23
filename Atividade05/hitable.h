#ifndef HITABLE_H
#define HITABLE_H

#include "ray.h"

// Forward declaration para evitar dependência circular
class Material;

/**
 * @struct HitRecord
 * @brief Estrutura para armazenar detalhes de uma interseção raio-objeto.
 * 
 * Contém informações sobre o ponto de interseção, a normal da superfície no ponto de interseção,
 * e o material do objeto atingido.
 */
struct HitRecord {
    double t; ///< Distância ao ponto de interseção
    Vec3 p; ///< Ponto de interseção
    Vec3 normal; ///< Normal da superfície no ponto de interseção
    Material* mat_ptr; ///< Ponteiro para o material do objeto atingido
};

/**
 * @class Hitable
 * @brief Classe abstrata base para todos os objetos que podem ser atingidos por um raio.
 */
class Hitable {
public:
    /**
     * @brief Testa se um raio atinge este objeto.
     * 
     * @param r O raio sendo testado.
     * @param t_min O limite inferior do intervalo de teste.
     * @param t_max O limite superior do intervalo de teste.
     * @param rec Estrutura para armazenar os detalhes da interseção, se ocorrer.
     * @return true se o raio atinge o objeto, false caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};

#endif // HITABLE_H