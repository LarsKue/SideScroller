#ifndef GAME_H
#define GAME_H

#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; };

    static SDL_Renderer *renderer;
    static SDL_Window *window;
    static int width;
    static int height;

private:

    bool fullscreen = false;
    int cnt = 0;
    bool isRunning;
};

#endif