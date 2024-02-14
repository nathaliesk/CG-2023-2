#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

/**
 * @brief Classe para representar uma câmera.
 */
class Camera {
public:
    /**
     * @brief Construtor da classe Camera.
     * 
     * @param lookfrom Posição da câmera.
     * @param lookat Ponto para onde a câmera está olhando.
     * @param vup Vetor de "cima" da câmera.
     * @param vfov Campo de visão vertical em graus.
     * @param aspect Aspect ratio da imagem.
     */
    Camera(Vec3 lookfrom, Vec3 lookat, Vec3 vup, double vfov, double aspect) {
        Vec3 u, v, w;
        double theta = vfov * M_PI / 180;
        double half_height = tan(theta / 2);
        double half_width = aspect * half_height;
        origin = lookfrom;
        w = unit_vector(lookfrom - lookat);
        u = unit_vector(cross(vup, w));
        v = cross(w, u);
        lower_left_corner = origin - half_width * u - half_height * v - w;
        horizontal = 2 * half_width * u;
        vertical = 2 * half_height * v;
    }

    /**
     * @brief Calcula o raio a partir da câmera.
     * 
     * @param s Parâmetro horizontal.
     * @param t Parâmetro vertical.
     * @return Ray Raio resultante.
     */
    Ray get_ray(double s, double t) const {
        return Ray(origin, lower_left_corner + s * horizontal + t * vertical - origin);
    }

private:
    Vec3 origin;
    Vec3 lower_left_corner;
    Vec3 horizontal;
    Vec3 vertical;
};

#endif // CAMERA_H