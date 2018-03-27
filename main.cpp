//
// Created by Lars on 27/03/2018.
//

#include <iostream>

#include "include/SDL2/SDL.h"

using namespace std;

int main(int argc, char** argv) {
    bool quit = false;
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        cout << "Something went wrong! " << SDL_GetError() << endl;
        SDL_Quit();
        return 0;
    }
    // Creating the window to draw in
    SDL_Window *window = SDL_CreateWindow("SideScroller", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          1280, 720, SDL_WINDOW_OPENGL);
    // Creating a renderer for draw calls to affect the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    // Selecting the color for drawing (blue)
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Delay(50);
    if(window == nullptr) {
        cout << "Something also went wrong here" << endl;
    }
    // loop for as long as we don't quit the game
    while(!quit) {
        //clearing the window with the selected render color
        SDL_RenderClear(renderer);
        // check for keypresses
        SDL_Event keyevent;

        SDL_WaitEvent(&keyevent);

        if(keyevent.type == SDL_KEYDOWN) {
            cout << SDL_GetKeyName(keyevent.key.keysym.sym) << endl;
//            quit = true;
//            SDL_Quit();
//            return 0;
        }
        if(keyevent.type == SDL_QUIT) {
            SDL_Quit();
            return 0;
        }


        // screen update
        SDL_RenderPresent(renderer);
    }

}