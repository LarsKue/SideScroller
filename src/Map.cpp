//
// Created by Lars on 31/03/2018.
//

#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = {
        {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

Map::Map() {
    dirtTex = new TextureManager("assets/dirt_v1.png");
    grassTex = new TextureManager("assets/grass_v1.png");
    waterTex = new TextureManager("assets/water_v1.png");

    LoadMap(lvl1);

    src.x = 0;
    src.y = 0;
    src.w = tex_size;
    src.h = tex_size;

    dest.x = 0;
    dest.y = 0;
    dest.w = tex_size * tex_scalar;
    dest.h = tex_size * tex_scalar;
}

void Map::LoadMap(int arr[20][25]) {
    for(int row = 0; row < 20; row++) {
        for(int column = 0; column < 25; column++) {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::DrawMap() {
    int type = 0;

    for(int row = 0; row < 20; row++) {
        for(int column = 0; column < 25; column++) {
            type = map[row][column];

            dest.x = column * tex_size * tex_scalar;
            dest.y = row * tex_size * tex_scalar;

            switch(type) {
                case 0:
                    waterTex->Draw(src, dest);
                    break;
                case 1:
                    grassTex->Draw(src, dest);
                    break;
                case 2:
                    dirtTex->Draw(src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}

