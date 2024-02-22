// define a classe Visualize, responsável pela criação da janela de visualização e pela renderização dos triângulos.

#ifndef VISUALIZE_H
#define VISUALIZE_H

#include <vector>
#include "hitable.h"
#include <SDL.h>

/**
 * @brief Classe para visualização de objetos em uma janela SDL.
 */
class Visualize {
public:
    /**
     * @brief Construtor da classe Visualize.
     * 
     * @param width Largura da janela.
     * @param height Altura da janela.
     */
    Visualize(int width, int height);

    /**
     * @brief Destrutor da classe Visualize.
     */
    ~Visualize();

    /**
     * @brief Inicia o loop de visualização.
     */
    void run();

    /**
     * @brief Define a lista de objetos a serem visualizados.
     * 
     * @param world Lista de objetos a serem visualizados.
     */
    void setWorld(Hitable *world);

private:
    SDL_Window* window_; ///< Janela SDL.
    SDL_Renderer* renderer_; ///< Renderizador SDL.
    int width_; ///< Largura da janela.
    int height_; ///< Altura da janela.
    Hitable *world_; ///< Lista de objetos a serem visualizados.
};

#endif // VISUALIZE_H
