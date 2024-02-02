// define a classe Visualize, responsável pela criação da janela de visualização e pela renderização dos triângulos.

#ifndef VISUALIZE_H
#define VISUALIZE_H

#include <vector>
#include "hitable.h"
#include <SDL.h>

class Visualize {
public:
    Visualize(int width, int height);
    ~Visualize();

    void run();
    void setWorld(Hitable *world);

private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    int width_;
    int height_;
    Hitable *world_;
};

#endif // VISUALIZE_H
