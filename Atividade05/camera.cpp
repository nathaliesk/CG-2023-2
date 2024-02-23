#include "camera.h"
#include <cmath> // Necessário para operações matemáticas como tan() e M_PI

/**
 * @brief Construtor da classe Camera, inicializa a câmera com parâmetros específicos.
 * 
 * Configura a posição, orientação, campo de visão vertical (vfov), e a razão de aspecto (aspect) da câmera.
 * Calcula a base ortonormal para a câmera e o canto inferior esquerdo da visão da câmera.
 * 
 * @param lookfrom Posição da câmera.
 * @param lookat Ponto para onde a câmera está olhando.
 * @param vup Vetor de "cima" da câmera.
 * @param vfov Campo de visão vertical em graus.
 * @param aspect Razão de aspecto da imagem.
 */
Camera::Camera(const Vec3& lookfrom, const Vec3& lookat, const Vec3& vup, double vfov, double aspect) {
    double theta = vfov * M_PI / 180;
    double half_height = tan(theta / 2);
    double half_width = aspect * half_height;

    origin = lookfrom;
    Vec3 w = unit_vector(lookfrom - lookat);
    Vec3 u = unit_vector(cross(vup, w));
    Vec3 v = cross(w, u);

    lower_left_corner = origin - half_width * u - half_height * v - w;
    horizontal = 2 * half_width * u;
    vertical = 2 * half_height * v;
}

/**
 * @brief Calcula e retorna um raio que passa por um ponto específico da imagem vista pela câmera.
 * 
 * Este método utiliza as coordenadas normalizadas (s, t) do pixel na imagem para calcular o raio.
 * 
 * @param s Coordenada horizontal normalizada do pixel.
 * @param t Coordenada vertical normalizada do pixel.
 * @return Ray O raio calculado a partir da câmera através do pixel especificado.
 */
Ray Camera::get_ray(double s, double t) const {
    return Ray(origin, lower_left_corner + s * horizontal + t * vertical - origin);
}