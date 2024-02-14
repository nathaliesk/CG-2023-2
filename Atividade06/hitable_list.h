#ifndef HITABLE_LIST_H
#define HITABLE_LIST_H

#include "hitable.h"

/**
 * @brief Classe para representar uma lista de objetos hitable.
 */
class HitableList : public Hitable {
public:
    /**
     * @brief Construtor da classe HitableList.
     * 
     * @param l Lista de objetos hitable.
     * @param n Número de objetos na lista.
     */
    HitableList(Hitable **l, int n) : list(l), list_size(n) {}

    /**
     * @brief Verifica se há interseção entre um raio e os objetos da lista.
     * 
     * @param r Raio a ser verificado.
     * @param t_min Parâmetro mínimo do raio.
     * @param t_max Parâmetro máximo do raio.
     * @param rec Registro de colisão, caso haja interseção.
     * @return Verdadeiro se houver interseção, falso caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

private:
    Hitable **list; ///< Lista de objetos hitable.
    int list_size; ///< Número de objetos na lista.
};

#endif // HITABLE_LIST_H