#include <iostream>

#include "SDL2/SDL.h"
#include "Game.h"

using namespace std;

Game *game = nullptr;

const int FPS = 144;
const int frameDelay = 1000 / FPS;

int main(int argc, char** argv) {
    Uint32 frameStart;
    int frameTime;

    // Initializing the game
    game = new Game();
    game->init("SideScroller", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    // Game loop, keeps the game running
    while (game->running()) {
        // Get ticks since program start
        frameStart = SDL_GetTicks();

        // Handle the game
        game->handleEvents();
        game->update();
        game->render();

        // Calculate time it took to complete one game frame and delay it until it matches the FPS
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }

    // Cleans and stops the program
    game->clean();

    return 0;
}