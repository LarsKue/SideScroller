//
// Created by Lars on 27/03/2018.
//

#include <iostream>

#include "include/SDL2/SDL.h"

using namespace std;

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        cout << "Something went wrong! " << SDL_GetError() << endl;
    }

    SDL_Window *window = SDL_CreateWindow("SideScroller", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          1280, 720, SDL_WINDOW_OPENGL);
    if(window == nullptr) {
        cout << "Something also went wrong here" << endl;
    }
    SDL_Delay(2000);
    SDL_Quit();
    return 0;
}