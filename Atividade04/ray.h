// ray.h
// Este arquivo define a classe Ray, que representa um raio no espaço.

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
public:
    Ray() {}
    Ray(const Vec3& origin, const Vec3& direction) : orig(origin), dir(direction) {}

    Vec3 origin() const { return orig; }
    Vec3 direction() const { return dir; }
    Vec3 at(double t) const { return orig + t * dir; }

private:
    Vec3 orig;
    Vec3 dir;
};

#endif // RAY_H
