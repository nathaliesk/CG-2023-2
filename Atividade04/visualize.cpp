// define a classe Visualize, responsável pela criação da janela de visualização e pela renderização dos triângulos.

#include "visualize.h"

/**
 * @brief Construtor da classe Visualize.
 * 
 * @param width Largura da janela de visualização.
 * @param height Altura da janela de visualização.
 */
Visualize::Visualize(int width, int height) : width_(width), height_(height) {
    SDL_Init(SDL_INIT_VIDEO);
    window_ = SDL_CreateWindow("Visualização Inicial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_, height_, 0);
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}

/**
 * @brief Destrutor da classe Visualize.
 */
Visualize::~Visualize() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

/**
 * @brief Inicia o loop de visualização.
 */
void Visualize::run() {
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Limpar a tela
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
        SDL_RenderClear(renderer_);

        // Renderizar objetos do mundo
        if (world_ != nullptr) {
            world_->render(renderer_, width_, height_);
        }

        // Atualizar a tela
        SDL_RenderPresent(renderer_);
    }
}

/**
 * @brief Define a lista de objetos a serem visualizados.
 * 
 * @param world Lista de objetos a serem visualizados.
 */
void Visualize::setWorld(Hitable *world) {
    world_ = world;
}