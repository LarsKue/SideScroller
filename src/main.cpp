#include <iostream>

#include "SDL2/SDL.h"
#include "Game.h"

Game *game = nullptr;

const int maxFps = 144;
const int frameDelay = 1000 / maxFps;



int main(int argc, char** argv) {

    int a = 0;
    int *b = &a;
    *b = 1;
    std::cout << a;

    Uint32 frameStart;
    int frameTime;

    // Initializing the game
    game = new Game();
    game->init("SideScroller", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

    // Game loop, keeps the game running
    while (game->running()) {
        // Get ticks since program start
        frameStart = SDL_GetTicks();

        // Handle the game
        game->handleEvents();
        game->update();
        game->render();

        // Calculate time it took to complete one game frame and delay it until it matches the max maxFps
        frameTime = SDL_GetTicks() - frameStart;
//        Game::frameTime = frameTime;
//        Game::frameDelay = frameDelay;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
        Game::FPS = 1000.0/(SDL_GetTicks() - frameStart);

    }

    // Cleans and stops the program
    game->clean();

    return 0;
}