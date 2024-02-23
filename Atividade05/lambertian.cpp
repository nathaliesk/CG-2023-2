// lambertian.cpp
#include "lambertian.h"
#include "vec3.h" // Assegure-se de incluir este cabeçalho se necessário para a função random_in_unit_sphere()

/**
 * @brief Construtor da classe Lambertian. Inicializa um material Lambertiano com um albedo específico.
 * 
 * @param albedo Coeficiente de reflexão do material, influenciando sua cor e brilho.
 */
Lambertian::Lambertian(const Vec3& albedo) : albedo_(albedo) {}

/**
 * @brief Calcula o espalhamento de um raio que atinge este material.
 * 
 * Este método determina como um raio é espalhado/refletido por uma superfície Lambertiana. A direção do raio
 * espalhado é determinada somando a normal no ponto de interseção com um vetor aleatório dentro de uma esfera unitária.
 * Isso simula o espalhamento difuso da luz.
 * 
 * @param r_in O raio incidente.
 * @param rec Registro de colisão que contém informações sobre o ponto de interseção.
 * @param attenuation A atenuação (perda de intensidade) da luz como resultado do espalhamento.
 * @param scattered O raio resultante após o espalhamento.
 * @return true Sempre retorna verdadeiro para materiais Lambertianos, indicando que o raio foi espalhado.
 */
bool Lambertian::scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 scatter_direction = rec.normal + random_in_unit_sphere();
    // Verifica se a direção de dispersão é quase nula e ajusta se necessário
    if (scatter_direction.near_zero()) {
        scatter_direction = rec.normal;
    }
    scattered = Ray(rec.p, scatter_direction);
    attenuation = albedo_;
    return true;
}