#ifndef HITABLE_LIST_H
#define HITABLE_LIST_H

#include "hitable.h"

/**
 * @brief Classe para representar uma lista de objetos hitables.
 */
class HitableList : public Hitable {
public:
    /**
     * @brief Construtor da classe HitableList.
     * 
     * @param list Lista de ponteiros para objetos hitables.
     * @param size Tamanho da lista.
     */
    HitableList(Hitable **list, int size) : list_(list), size_(size) {}

    /**
     * @brief Função para determinar se um raio atinge algum objeto na lista.
     * 
     * @param r Raio a ser verificado.
     * @param t_min Parâmetro de tempo mínimo.
     * @param t_max Parâmetro de tempo máximo.
     * @param rec Registro de colisão.
     * @return true Se o raio atinge algum objeto, false caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

private:
    Hitable **list_; ///< Lista de ponteiros para objetos hitables.
    int size_;       ///< Tamanho da lista.
};

#endif // HITABLE_LIST_H