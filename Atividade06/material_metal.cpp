#include "material_metal.h"

bool MaterialMetal::scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + fuzziness_ * random_in_unit_sphere());
    attenuation = albedo_;
    return (dot(scattered.direction(), rec.normal) > 0);
}