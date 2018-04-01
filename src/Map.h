//
// Created by Lars on 31/03/2018.
//

#ifndef SIDESCROLLER_MAP_H
#define SIDESCROLLER_MAP_H

#include "Game.h"
#include "TextureManager.h"

class Map {
public:
    Map();
    ~Map();

    void LoadMap(int arr[20][25]);
    void DrawMap();

private:
    int tex_size = 32;
    int tex_scalar = 2;
    SDL_Rect src, dest;
    TextureManager *dirtTex, *grassTex, *waterTex;

//    SDL_Texture* dirt;
//    SDL_Texture* grass;
//    SDL_Texture* water;

    int map[20][25];

};

#endif //SIDESCROLLER_MAP_H
