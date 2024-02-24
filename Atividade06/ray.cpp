#ifndef RAY_CPP
#define RAY_CPP

#include "ray.h"

/**
 * @brief Retorna um ponto ao longo do raio com base em um parâmetro t.
 * 
 * @param t Parâmetro que indica a distância ao longo do raio.
 * @return O ponto ao longo do raio correspondente ao parâmetro t.
 */
Vec3 Ray::at(double t) const {
    return orig + t * dir;
}

#endif // RAY_CPP