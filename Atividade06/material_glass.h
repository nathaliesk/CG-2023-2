#ifndef MATERIAL_GLASS_H
#define MATERIAL_GLASS_H

#include "material.h"

/**
 * @brief Classe para definir um material de vidro.
 */
class MaterialGlass : public Material {
public:
    /**
     * @brief Construtor da classe MaterialGlass.
     * 
     * @param refraction_idx Índice de refração do material.
     */
    MaterialGlass(double refraction_idx);

    /**
     * @brief Calcula a dispersão do raio ao interagir com o material de vidro.
     * 
     * @param r_in Raio de entrada.
     * @param rec Registro de colisão.
     * @param attenuation Atenuação do raio.
     * @param scattered Raio disperso.
     * @return true Se houver interação, false caso contrário.
     */
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;

private:
    double refraction_idx_; ///< Índice de refração.
};

#endif // MATERIAL_GLASS_H