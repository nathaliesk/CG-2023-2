#ifndef HIT_RECORD_H
#define HIT_RECORD_H

#include "vec3.h"
#include "material.h" // Supondo que você tenha uma classe Material

/**
 * @brief Estrutura que registra as informações de colisão.
 */
struct HitRecord {
    double t;           ///< Parâmetro do raio na interseção.
    Vec3 p;              ///< Ponto de interseção.
    Vec3 normal;        ///< Vetor normal na interseção.
    Material *material; ///< Material da superfície na interseção.

    // Construtor padrão
    HitRecord() : t(0), p(Vec3()), normal(Vec3()), material(nullptr) {}
};

#endif // HIT_RECORD_H
