#include <iostream>
#include "Game.h"

using namespace std;

SDL_Texture* playerTex = NULL;
SDL_Rect srcR, destR;

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "Subsystems initialized!" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            cout << "Window created!" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created!" << endl;
        }

        this->width = width;
        this->height = height;
        cnt = (width / 2 - 100) * 20;
        isRunning = true;
    } else
        isRunning = false;

    playerTex = IMG_LoadTexture(renderer, "assets/player.png");

}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            cout << SDL_GetKeyName( event.key.keysym.sym ) << endl;
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
                case SDLK_LEFT:
                    printf("LEFT\n");
                    break;
                case SDLK_RIGHT:
                    printf("RIGHT\n");
                    break;
                case SDLK_UP:
                    printf("UP\n");
                    break;
                case SDLK_DOWN:
                    printf("DOWN\n");
                    break;
            }
            break;

        default:
            break;
    }
}

void Game::update() {
    destR.w = 32*5;
    destR.h = 32*5;
    destR.x = cnt / 20;
    destR.y = 200;

    cnt++;
    if(cnt > width * 20)
        cnt = - destR.w * 20;
}

void Game::render() {
    SDL_RenderClear(renderer);

    // add here stuff to render
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}