// vec3.h
#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

/**
 * @brief Classe para manipulação de vetores 3D.
 */
class Vec3 {
public:
    /**
     * @brief Construtor padrão. Inicializa o vetor com zeros.
     */
    Vec3() : x_(0), y_(0), z_(0) {}

    /**
     * @brief Construtor de inicialização.
     * 
     * @param x Componente x do vetor.
     * @param y Componente y do vetor.
     * @param z Componente z do vetor.
     */
    Vec3(double x, double y, double z) : x_(x), y_(y), z_(z) {}

    /**
     * @brief Retorna a componente x do vetor.
     */
    double x() const { return x_; }

    /**
     * @brief Retorna a componente y do vetor.
     */
    double y() const { return y_; }

    /**
     * @brief Retorna a componente z do vetor.
     */
    double z() const { return z_; }

    /**
     * @brief Retorna o comprimento (magnitude) do vetor.
     */
    double length() const {
        return std::sqrt(length_squared());
    }

    /**
     * @brief Retorna o quadrado do comprimento (magnitude) do vetor.
     */
    double length_squared() const {
        return x_ * x_ + y_ * y_ + z_ * z_;
    }

    /**
     * @brief Sobrecarga do operador de negação.
     * 
     * @return Um novo vetor com todas as componentes negadas.
     */
    Vec3 operator-() const {
        return Vec3(-x_, -y_, -z_);
    }

    // Mais operadores e funções podem ser adicionados conforme necessário...

private:
    double x_;
    double y_;
    double z_;
};

// Funções globais

/**
 * @brief Sobrecarga do operador de soma para vetores.
 * 
 * @return Um novo vetor que é a soma dos dois vetores fornecidos.
 */
Vec3 operator+(const Vec3& lhs, const Vec3& rhs);

/**
 * @brief Sobrecarga do operador de subtração para vetores.
 * 
 * @return Um novo vetor que é a diferença entre os dois vetores fornecidos.
 */
Vec3 operator-(const Vec3& lhs, const Vec3& rhs);

/**
 * @brief Sobrecarga do operador de multiplicação por escalar.
 * 
 * @return Um novo vetor que é o vetor original multiplicado por um escalar.
 */
Vec3 operator*(const Vec3& v, double t);

/**
 * @brief Sobrecarga do operador de multiplicação por escalar (comutativo).
 * 
 * @return Um novo vetor que é o vetor original multiplicado por um escalar.
 */
Vec3 operator*(double t, const Vec3& v);

/**
 * @brief Sobrecarga do operador de divisão por escalar.
 * 
 * @return Um novo vetor que é o vetor original dividido por um escalar.
 */
Vec3 operator/(const Vec3& v, double t);

/**
 * @brief Produto escalar entre dois vetores.
 * 
 * @return O produto escalar entre os dois vetores fornecidos.
 */
double dot(const Vec3& lhs, const Vec3& rhs);

/**
 * @brief Produto vetorial entre dois vetores.
 * 
 * @return O produto vetorial entre os dois vetores fornecidos.
 */
Vec3 cross(const Vec3& lhs, const Vec3& rhs);

/**
 * @brief Retorna um vetor unitário na mesma direção do vetor fornecido.
 */
Vec3 unit_vector(const Vec3& v);

#endif // VEC3_H
