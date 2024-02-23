#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "vec3.h"

/**
 * @class Camera
 * @brief Classe que representa uma câmera no contexto de ray tracing.
 * 
 * Esta classe é responsável por configurar a posição e orientação da câmera na cena, assim como calcular os raios
 * que são lançados a partir da câmera para os pixels na imagem.
 */
class Camera {
public:
    /**
     * @brief Construtor que configura a câmera.
     * 
     * @param lookfrom A posição da câmera na cena.
     * @param lookat O ponto para o qual a câmera está olhando.
     * @param vup Um vetor que representa a direção "para cima" no espaço da cena.
     * @param vfov O campo de visão vertical da câmera em graus.
     * @param aspect A razão de aspecto da imagem (largura / altura).
     */
    Camera(const Vec3& lookfrom, const Vec3& lookat, const Vec3& vup, double vfov, double aspect);

    /**
     * @brief Calcula e retorna um raio que passa de um ponto específico da câmera através de um pixel na imagem.
     * 
     * @param s A coordenada horizontal normalizada do pixel na imagem.
     * @param t A coordenada vertical normalizada do pixel na imagem.
     * @return Ray O raio calculado a partir da posição da câmera através do pixel especificado.
     */
    Ray get_ray(double s, double t) const;

private:
    Vec3 origin; // A posição da câmera.
    Vec3 lower_left_corner; // O canto inferior esquerdo da área de visualização.
    Vec3 horizontal; // A largura da área de visualização.
    Vec3 vertical; // A altura da área de visualização.
    // Mais atributos podem ser necessários dependendo da implementação específica da câmera.
};

#endif // CAMERA_H