#ifndef HITABLE_LIST_H
#define HITABLE_LIST_H

#include "hitable.h"

/**
 * @class HitableList
 * @brief Representa uma lista de objetos que podem ser atingidos por raios.
 * 
 * Esta classe é uma coleção de objetos derivados da interface Hitable. Ela permite que um raio teste a interseção
 * com vários objetos na cena de uma vez, retornando informações sobre o ponto de interseção mais próximo, se houver.
 */
class HitableList : public Hitable {
public:
    HitableList() : list(nullptr), list_size(0) {}
    HitableList(Hitable** l, int n) : list(l), list_size(n) {}
    virtual ~HitableList();

    /**
     * @brief Testa se um raio atinge algum dos objetos na lista.
     * 
     * Percorre cada objeto na lista e verifica se o raio atinge. Retorna verdadeiro se pelo menos um objeto for atingido.
     * 
     * @param r O raio sendo testado.
     * @param t_min O valor mínimo de t para considerar uma interseção válida.
     * @param t_max O valor máximo de t para considerar uma interseção válida.
     * @param rec Estrutura para armazenar os detalhes da interseção mais próxima.
     * @return bool Verdadeiro se o raio atingir qualquer objeto na lista, falso caso contrário.
     */
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

private:
    Hitable **list; ///< Ponteiro para um array de ponteiros para objetos Hitable.
    int list_size;  ///< Tamanho da lista de objetos Hitable.
};

#endif // HITABLE_LIST_H