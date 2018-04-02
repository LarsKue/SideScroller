
#include "Game.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Map.h"

using namespace std;

GameObject* player;
GameObject* player2;
Map* map;

TextureManager* playerTex;

SDL_Renderer *Game::renderer = nullptr;
SDL_Window *Game::window = nullptr;
double Game::FPS = 144;

// Initializes the game class (what happens upon creation)
Game::Game() {}

// Uninitializes the game class (what happens upon deletion)
Game::~Game() {}

// Initializes the game
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    this->width = width;
    this->height = height;
    this->fullscreen = fullscreen;

    // Sets the flag to fullscreen mode
    int flags = 0;
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    // Sets up the window and opens it
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "Subsystems initialized!" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            cout << "Window created!" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 100, 255);
            cout << "Renderer created!" << endl;
        }

        cnt = (width / 2 - 100) * 20;
        isRunning = true;
    } else
        isRunning = false;

    playerTex = new TextureManager("assets/player.png");

    player = new GameObject(playerTex, 50, 50, 1);
    player2 = new GameObject(playerTex, 50, 50, 1);
    map = new Map();

}

// Handles the user input
void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            // These are the keyboard presses
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
                case SDLK_d:
                    player->d_pressed = true;
                    break;
                case SDLK_a:
                    player->a_pressed = true;
                    break;
                case SDLK_SPACE:
                    player->space_pressed = true;
                    break;
                default:
                    break;
            }
            break;
        case SDL_KEYUP:
            // These are the keyboard presses
            cout << SDL_GetKeyName( event.key.keysym.sym ) << endl;
            switch (event.key.keysym.sym) {
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
                case SDLK_d:
                    player->d_pressed = false;
                    break;
                case SDLK_a:
                    player->a_pressed = false;
                    break;
                case SDLK_SPACE:
                    player->space_pressed = false;
                    break;
                default:
                    break;
            }
        default:
            break;
    }
}

// This is what happens every frame
void Game::update() {
    player->Update();
    player2->Update();
}

// This is what get's rendered every frame
void Game::render() {
    SDL_RenderClear(renderer);

    // add stuff to render here
    map->DrawMap();
    player->Render();
//    player2->Render();

    SDL_RenderPresent(renderer);
}

// Cleans the game and stops the program
void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}