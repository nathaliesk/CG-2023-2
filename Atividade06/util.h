#ifndef UTIL_H
#define UTIL_H

#include "vec3.h"
#include <iostream>
#include <cstdlib>

// Definição da classe Color
using Color = Vec3;

/**
 * @brief Escreve a cor de um pixel no formato de pixel em um fluxo de saída.
 * 
 * @param out O fluxo de saída onde a cor será escrita.
 * @param pixel_color A cor do pixel a ser escrita.
 */
void write_color(std::ostream &out, const Color &pixel_color) {
    // Escreve a cor no formato de pixel (convertendo de float para int e garantindo que esteja no intervalo [0,255])
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

inline double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

/**
 * @brief Limita o valor entre um intervalo específico.
 * 
 * @param x O valor a ser limitado.
 * @param min O valor mínimo do intervalo.
 * @param max O valor máximo do intervalo.
 * @return O valor limitado dentro do intervalo.
 */
inline double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

/**
 * @brief Calcula a cor de um raio.
 * 
 * @param origin A origem do raio.
 * @param direction A direção do raio.
 * @param world O mundo da cena.
 * @return A cor calculada para o raio.
 */
Vec3 ray_color(const Vec3& origin, const Vec3& direction, Hitable *world) {
    // Implemente a lógica para calcular a cor do raio
    // Retorne uma cor de exemplo para evitar erros de compilação
    return Vec3(0.5, 0.7, 1.0);
}


#endif // UTIL_H