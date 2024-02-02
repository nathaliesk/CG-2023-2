// triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hitable.h"

class Triangle : public Hitable {
public:
    Triangle() {}
    Triangle(Vec3 v0, Vec3 v1, Vec3 v2) : v0_(v0), v1_(v1), v2_(v2) {}

    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

private:
    Vec3 v0_, v1_, v2_;
};

#endif // TRIANGLE_H

// triangle.cpp
#include "triangle.h"

bool Triangle::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    Vec3 edge1 = v1_ - v0_;
    Vec3 edge2 = v2_ - v0_;
    Vec3 h = cross(r.direction(), edge2);
    double a = dot(edge1, h);

    if (a > -0.00001 && a < 0.00001) {
        return false; // ray is parallel to the triangle
    }

    double f = 1.0 / a;
    Vec3 s = r.origin() - v0_;
    double u = f * dot(s, h);
    if (u < 0.0 || u > 1.0) {
        return false;
    }

    Vec3 q = cross(s, edge1);
    double v = f * dot(r.direction(), q);
    if (v < 0.0 || u + v > 1.0) {
        return false;
    }

    double t = f * dot(edge2, q);
    if (t < t_min || t > t_max) {
        return false;
    }

    rec.t = t;
    rec.p = r.at(t);
    rec.normal = unit_vector(cross(edge1, edge2));
    return true;
}

// visualize.cpp
// Adicionar renderização do triângulo no loop principal

// main.cpp
// Adicionar criação do triângulo e inclusão na lista de hitables
