// atividade02.cpp
#include "vec3.h"

/**
 * @brief Sobrecarga do operador de soma para vetores.
 * 
 * @return Um novo vetor que é a soma dos dois vetores fornecidos.
 */
Vec3 operator+(const Vec3& lhs, const Vec3& rhs) {
    return Vec3(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

/**
 * @brief Sobrecarga do operador de subtração para vetores.
 * 
 * @return Um novo vetor que é a diferença entre os dois vetores fornecidos.
 */
Vec3 operator-(const Vec3& lhs, const Vec3& rhs) {
    return Vec3(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

/**
 * @brief Sobrecarga do operador de multiplicação por escalar.
 * 
 * @return Um novo vetor que é o vetor original multiplicado por um escalar.
 */
Vec3 operator*(const Vec3& v, double t) {
    return Vec3(v.x() * t, v.y() * t, v.z() * t);
}

/**
 * @brief Sobrecarga do operador de multiplicação por escalar (comutativo).
 * 
 * @return Um novo vetor que é o vetor original multiplicado por um escalar.
 */
Vec3 operator*(double t, const Vec3& v) {
    return v * t;
}

/**
 * @brief Sobrecarga do operador de divisão por escalar.
 * 
 * @return Um novo vetor que é o vetor original dividido por um escalar.
 */
Vec3 operator/(const Vec3& v, double t) {
    return v * (1/t);
}

/**
 * @brief Produto escalar entre dois vetores.
 * 
 * @return O produto escalar entre os dois vetores fornecidos.
 */
double dot(const Vec3& lhs, const Vec3& rhs) {
    return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}

/**
 * @brief Produto vetorial entre dois vetores.
 * 
 * @return O produto vetorial entre os dois vetores fornecidos.
 */
Vec3 cross(const Vec3& lhs, const Vec3& rhs) {
    return Vec3(lhs.y() * rhs.z() - lhs.z() * rhs.y(),
                lhs.z() * rhs.x() - lhs.x() * rhs.z(),
                lhs.x() * rhs.y() - lhs.y() * rhs.x());
}

/**
 * @brief Retorna um vetor unitário na mesma direção do vetor fornecido.
 */
Vec3 unit_vector(const Vec3& v) {
    return v / v.length();
}

int main() {
    // Exemplos de uso da classe Vec3 e suas operações

    Vec3 v1(1, 2, 3);
    Vec3 v2(4, 5, 6);

    // Adição de vetores
    Vec3 result_add = v1 + v2;

    // Subtração de vetores
    Vec3 result_sub = v1 - v2;

    // Multiplicação por escalar
    Vec3 result_mul = v1 * 2.0;

    // Produto escalar
    double result_dot = dot(v1, v2);

    // Produto vetorial
    Vec3 result_cross = cross(v1, v2);

    return 0;
}