#include <iostream>
#include "Game.h"

using namespace std;

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
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            cout << "Renderer created!" << endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_WaitEvent(&event);
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
}

void Game::render() {
    SDL_RenderClear(renderer);

    // add here stuff to render

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}