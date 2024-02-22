// vec3.h

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

/**
 * @brief Classe para representar um vetor 3D.
 * 
 * Um vetor 3D é uma entidade matemática que tem magnitude (comprimento) e direção. 
 * Ele é frequentemente usado para representar posições, direções de luz, cores, entre outros.
 */
class Vec3 {
public:
    /**
     * @brief Construtor padrão. Inicializa o vetor com coordenadas (0, 0, 0).
     */
    Vec3() : e{0,0,0} {}

    /**
     * @brief Construtor de inicialização.
     * 
     * @param e0 Componente x do vetor.
     * @param e1 Componente y do vetor.
     * @param e2 Componente z do vetor.
     */
    Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    /**
     * @brief Retorna a coordenada x do vetor.
     */
    double x() const { return e[0]; }

    /**
     * @brief Retorna a coordenada y do vetor.
     */
    double y() const { return e[1]; }

    /**
     * @brief Retorna a coordenada z do vetor.
     */
    double z() const { return e[2]; }

    /**
     * @brief Sobrecarga do operador de negação.
     * 
     * @return Um novo vetor com todas as coordenadas negadas.
     */
    Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }

    /**
     * @brief Sobrecarga do operador de acesso a coordenadas.
     * 
     * @param i O índice da coordenada desejada (0 para x, 1 para y, 2 para z).
     * @return O valor da coordenada no índice especificado.
     */
    double operator[](int i) const { return e[i]; }

    /**
     * @brief Sobrecarga do operador de acesso a coordenadas (com atribuição).
     * 
     * @param i O índice da coordenada desejada (0 para x, 1 para y, 2 para z).
     * @return A referência para a coordenada no índice especificado.
     */
    double& operator[](int i) { return e[i]; }

    /**
     * @brief Sobrecarga do operador de adição e atribuição.
     * 
     * @param v O vetor a ser somado.
     * @return Uma referência para o vetor resultante da soma.
     */
    Vec3& operator+=(const Vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    /**
     * @brief Sobrecarga do operador de divisão e atribuição por escalar.
     * 
     * @param t O escalar pelo qual o vetor será dividido.
     * @return Uma referência para o vetor resultante da divisão.
     */
    Vec3& operator/=(const double t) {
        e[0] /= t;
        e[1] /= t;
        e[2] /= t;
        return *this;
    }

    /**
     * @brief Retorna o comprimento (magnitude) do vetor.
     * 
     * @return O comprimento do vetor.
     */
    double length() const {
        return sqrt(length_squared());
    }

    /**
     * @brief Retorna o quadrado do comprimento (magnitude) do vetor.
     * 
     * @return O quadrado do comprimento do vetor.
     */
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

public:
    double e[3]; /**< As coordenadas x, y e z do vetor. */
};

/**
 * @brief Gera um vetor aleatório dentro de uma esfera unitária.
 * 
 * @return Um vetor aleatório dentro de uma esfera unitária.
 */
Vec3 random_in_unit_sphere() {
    while (true) {
        auto p = Vec3(rand(), rand(), rand()) * 2.0 - Vec3(1, 1, 1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

// Operadores globais

/**
 * @brief Sobrecarga do operador de saída para imprimir um vetor no formato (x, y, z).
 * 
 * @param out O fluxo de saída.
 * @param v O vetor a ser impresso.
 * @return O fluxo de saída modificado.
 */
inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

/**
 * @brief Sobrecarga do operador de adição entre dois vetores.
 * 
 * @param u Um vetor.
 * @param v Um vetor.
 * @return Um novo vetor que é a soma dos vetores u e v.
 */
inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

/**
 * @brief Sobrecarga do operador de subtração entre dois vetores.
 * 
 * @param u Um vetor.
 * @param v Um vetor.
 * @return Um novo vetor que é a diferença entre os vetores u e v.
 */
inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

/**
 * @brief Sobrecarga do operador de multiplicação entre dois vetores (componente a componente).
 * 
 * @param u Um vetor.
 * @param v Um vetor.
 * @return Um novo vetor que é o produto dos vetores u e v (componente a componente).
 */
inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

/**
 * @brief Sobrecarga do operador de multiplicação por escalar.
 * 
 * @param t O escalar.
 * @param v O vetor.
 * @return Um novo vetor que é o resultado da multiplicação do vetor v pelo escalar t.
 */
inline Vec3 operator*(double t, const Vec3 &v) {
    return Vec3(t * v.x(), t * v.y(), t * v.z());
}

/**
 * @brief Sobrecarga do operador de multiplicação por escalar (comutativo).
 * 
 * @param v O vetor.
 * @param t O escalar.
 * @return Um novo vetor que é o resultado da multiplicação do vetor v pelo escalar t.
 */
inline Vec3 operator*(const Vec3 &v, double t) {
    return t * v;
}

/**
 * @brief Sobrecarga do operador de divisão de um vetor por um escalar.
 * 
 * @param v O vetor.
 * @param t O escalar.
 * @return Um novo vetor que é o resultado da divisão do vetor v pelo escalar t.
 */
inline Vec3 operator/(Vec3 v, double t) {
    return (1 / t) * v;
}

/**
 * @brief Calcula o produto escalar entre dois vetores.
 * 
 * @param u Um vetor.
 * @param v Um vetor.
 * @return O produto escalar entre os vetores u e v.
 */
inline double dot(const Vec3 &u, const Vec3 &v) {
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

/**
 * @brief Calcula o produto vetorial entre dois vetores.
 * 
 * @param u Um vetor.
 * @param v Um vetor.
 * @return Um novo vetor que é o resultado do produto vetorial entre os vetores u e v.
 */
inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

/**
 * @brief Retorna o vetor unitário na mesma direção do vetor fornecido.
 * 
 * @param v O vetor.
 * @return Um novo vetor que tem a mesma direção do vetor fornecido, mas magnitude 1.
 */
inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}

#endif // VEC3_H