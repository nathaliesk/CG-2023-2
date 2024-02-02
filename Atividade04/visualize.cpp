// define a classe Visualize, responsável pela criação da janela de visualização e pela renderização dos triângulos.

#include "visualize.h"

Visualize::Visualize(int width, int height) : width_(width), height_(height), world_(nullptr) {
    SDL_Init(SDL_INIT_VIDEO);
    window_ = SDL_CreateWindow("Visualização Inicial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_, height_, 0);
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}

Visualize::~Visualize() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

void Visualize::run() {
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
        SDL_RenderClear(renderer_);

        if (world_) {
            SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
            for (int y = 0; y < height_; y++) {
                for (int x = 0; x < width_; x++) {
                    Ray r(Vec3(0,0,0), Vec3((x+0.5)/width_ - 0.5, (y+0.5)/height_ - 0.5, -1));
                    HitRecord rec;
                    if (world_->hit(r, 0, DBL_MAX, rec)) {
                        SDL_RenderDrawPoint(renderer_, x, height_ - y);
                    }
                }
            }
        }

        SDL_RenderPresent(renderer_);
    }
}

void Visualize::setWorld(Hitable *world) {
    world_ = world;
}