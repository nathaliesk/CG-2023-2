#ifndef HITABLE_H
#define HITABLE_H

#include "ray.h"
#include "material.h"

/**
 * @brief Classe abstrata para representar objetos que podem ser atingidos por raios.
 */
class Hitable {
public:
    /**
     * @brief Verifica se há interseção entre um raio e o objeto.
     * 
     * @param r Raio a ser verificado.
     * @param t_min Parâmetro mínimo do raio.
     * @param t_max Parâmetro máximo do raio.
     * @param rec Registro de colisão, se houver interseção.
     * @return true Se houve interseção, false caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};

/**
 * @brief Estrutura para armazenar informações de colisão.
 */
struct HitRecord {
    double t; ///< Parâmetro do raio onde ocorreu a colisão.
    Vec3 p; ///< Ponto de colisão.
    Vec3 normal; ///< Normal à superfície no ponto de colisão.
    // Mais informações podem ser adicionadas conforme necessário...
};

/**
 * @brief Classe para representar uma lista de objetos hitables.
 */
class HitableList : public Hitable {
public:
    /**
     * @brief Construtor da classe HitableList.
     * 
     * @param l Lista de objetos hitables.
     * @param n Número de objetos na lista.
     */
    HitableList(Hitable** l, int n) : list(l), list_size(n) {}

    /**
     * @brief Verifica se há interseção entre um raio e a lista de objetos.
     * 
     * @param r Raio a ser verificado.
     * @param t_min Parâmetro mínimo do raio.
     * @param t_max Parâmetro máximo do raio.
     * @param rec Registro de colisão, se houver interseção.
     * @return true Se houve interseção, false caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

private:
    Hitable** list; ///< Lista de objetos hitables.
    int list_size; ///< Número de objetos na lista.
};

#endif // HITABLE_H
