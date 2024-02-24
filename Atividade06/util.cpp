#ifndef UTIL_CPP
#define UTIL_CPP

#include "util.h"

/**
 * @brief Escreve a cor de um pixel no formato de pixel em um fluxo de saída.
 * 
 * @param out O fluxo de saída onde a cor será escrita.
 * @param pixel_color A cor do pixel a ser escrita.
 * @param samples_per_pixel O número de amostras por pixel.
 */
void write_color(std::ostream &out, const Color &pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide a cor total pelo número de amostras e aplica a correção gama
    auto scale = 1.0 / samples_per_pixel;
    r = std::sqrt(scale * r);
    g = std::sqrt(scale * g);
    b = std::sqrt(scale * b);

    // Escreve a cor no formato de pixel (convertendo de float para int e garantindo que esteja no intervalo [0,255])
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

/**
 * @brief Retorna um número aleatório no intervalo [0,1).
 * 
 * @return Um número aleatório no intervalo [0,1).
 */
double random_double() {
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
double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

#endif // UTIL_CPP