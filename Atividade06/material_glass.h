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
    MaterialGlass(double refraction_idx) : refraction_idx_(refraction_idx) {}

    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;

private:
    double refraction_idx_; ///< Índice de refração.
};

#endif // MATERIAL_GLASS_H