#include "sphere.h"
#include "hit_record.h"

/**
 * @brief Verifica se há interseção entre um raio e a esfera.
 * 
 * @param r Raio a ser verificado.
 * @param t_min Parâmetro mínimo do raio.
 * @param t_max Parâmetro máximo do raio.
 * @param rec Registro de colisão, se houver interseção.
 * @return true Se houve interseção, false caso contrário.
 */
bool Sphere::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    Vec3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = dot(oc, r.direction());
    double c = dot(oc, oc) - radius * radius;
    double discriminant = b * b - a * c;

    if (discriminant > 0) {
        double temp = (-b - sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.material = material;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;
            rec.material = material;
            return true;
        }
    }
    return false;
}