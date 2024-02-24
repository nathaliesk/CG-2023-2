#ifndef VEC3_CPP
#define VEC3_CPP

#include "vec3.h"

/**
 * @brief Sobrecarga do operador de inserção para impressão de vetores.
 * 
 * @param out O fluxo de saída onde o vetor será impresso.
 * @param v O vetor a ser impresso.
 * @return O fluxo de saída com o vetor impresso.
 */
std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

/**
 * @brief Sobrecarga do operador de soma para adição de vetores.
 * 
 * @param u O primeiro vetor.
 * @param v O segundo vetor.
 * @return O vetor resultante da adição.
 */
Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

/**
 * @brief Sobrecarga do operador de subtração para subtração de vetores.
 * 
 * @param u O vetor do qual será subtraído.
 * @param v O vetor a ser subtraído.
 * @return O vetor resultante da subtração.
 */
Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

/**
 * @brief Sobrecarga do operador de multiplicação para multiplicação de vetores.
 * 
 * @param u O primeiro vetor.
 * @param v O segundo vetor.
 * @return O vetor resultante da multiplicação.
 */
Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

/**
 * @brief Sobrecarga do operador de multiplicação para multiplicação por um escalar.
 * 
 * @param t O escalar.
 * @param v O vetor a ser multiplicado.
 * @return O vetor resultante da multiplicação.
 */
Vec3 operator*(double t, const Vec3 &v) {
    return Vec3(t * v.x(), t * v.y(), t * v.z());
}

/**
 * @brief Sobrecarga do operador de multiplicação para multiplicação por um escalar.
 * 
 * @param v O vetor a ser multiplicado.
 * @param t O escalar.
 * @return O vetor resultante da multiplicação.
 */
Vec3 operator*(const Vec3 &v, double t) {
    return t * v;
}

/**
 * @brief Sobrecarga do operador de divisão para divisão de um vetor por um escalar.
 * 
 * @param v O vetor a ser dividido.
 * @param t O escalar divisor.
 * @return O vetor resultante da divisão.
 */
Vec3 operator/(Vec3 v, double t) {
    return (1 / t) * v;
}

/**
 * @brief Calcula o produto escalar entre dois vetores.
 * 
 * @param u O primeiro vetor.
 * @param v O segundo vetor.
 * @return O produto escalar entre os vetores.
 */
double dot(const Vec3 &u, const Vec3 &v) {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

/**
 * @brief Calcula o produto vetorial entre dois vetores.
 * 
 * @param u O primeiro vetor.
 * @param v O segundo vetor.
 * @return O produto vetorial entre os vetores.
 */
Vec3 cross(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

/**
 * @brief Retorna o vetor unitário na mesma direção do vetor dado.
 * 
 * @param v O vetor para o qual será calculado o vetor unitário.
 * @return O vetor unitário na mesma direção do vetor dado.
 */
Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}

#endif // VEC3_CPP