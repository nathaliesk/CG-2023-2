#ifndef MATERIAL_METAL_H
#define MATERIAL_METAL_H

#include "material.h"

/**
 * @brief Classe para definir um material metálico.
 */
class MaterialMetal : public Material {
public:
    /**
     * @brief Construtor da classe MaterialMetal.
     * 
     * @param albedo Cor do material.
     * @param fuzziness Fator de desfoque (0 para sem desfoque).
     */
    MaterialMetal(const Vec3& albedo, double fuzziness) : albedo_(albedo), fuzziness_(fuzziness < 1 ? fuzziness : 1) {}

    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;

private:
    Vec3 albedo_; ///< Cor do material.
    double fuzziness_; ///< Fator de desfoque.
};

#endif // MATERIAL_METAL_H