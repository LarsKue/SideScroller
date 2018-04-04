
#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Collision.h"
#include "ECS/Components.h"
#include "Vector2D.h"

Map* map;

TextureManager* playerTex;

SDL_Renderer *Game::renderer = nullptr;
SDL_Window *Game::window = nullptr;
SDL_Event Game::event;
double Game::FPS = 144;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

auto& water1(manager.addEntity());
auto& water2(manager.addEntity());
auto& water3(manager.addEntity());

auto& water11(manager.addEntity());
auto& water12(manager.addEntity());
auto& water13(manager.addEntity());

auto& water21(manager.addEntity());
auto& water22(manager.addEntity());
auto& water23(manager.addEntity());

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
        printf("Subsystems initialized!\n");

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            printf( "Window created!\n");
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            printf( "Renderer created!\n");
        }

        cnt = (width / 2 - 100) * 20;
        isRunning = true;
    } else
        isRunning = false;

    playerTex = new TextureManager("assets/player.png");

//    player = new GameObject(playerTex, 50, 50, 2);
//    player2 = new GameObject(playerTex, 50, 50, 1);
    map = new Map();

    //ecs implementation

    player.addComponent<TransformComponent>(2);
    player.addComponent<SpriteComponent>("assets/player.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");

    wall.addComponent<TransformComponent>(300, 300, 20, 300, 1);
    wall.addComponent<SpriteComponent>("assets/dirt_v4.png");
    wall.addComponent<ColliderComponent>("wall");


    // Water Tests
    water1.addComponent<TransformComponent>(1400, 100);
    water2.addComponent<TransformComponent>(1208, 100);
    water3.addComponent<TransformComponent>(1592, 100);

    water11.addComponent<TransformComponent>(1400, 400);
    water12.addComponent<TransformComponent>(1208, 400);
    water13.addComponent<TransformComponent>(1592, 400);

    water21.addComponent<TransformComponent>(1400, 800);
    water22.addComponent<TransformComponent>(1208, 800);
    water23.addComponent<TransformComponent>(1592, 800);

    water1.addComponent<SpriteComponent>("assets/Wateranimation.png", 10, 100);
    water2.addComponent<SpriteComponent>("assets/Wateranimation.png", 10, 100);
    water3.addComponent<SpriteComponent>("assets/Wateranimation.png", 10, 100);

    water11.addComponent<SpriteComponent>("assets/wateranimationtest02.png", 10, 100);
    water12.addComponent<SpriteComponent>("assets/wateranimationtest02.png", 10, 100);
    water13.addComponent<SpriteComponent>("assets/wateranimationtest02.png", 10, 100);

    water21.addComponent<SpriteComponent>("assets/waterbodyhorizontaltest01.png", 60, 1000/60, true);
    water22.addComponent<SpriteComponent>("assets/waterbodyhorizontaltest01.png", 60, 1000/60, true);
    water23.addComponent<SpriteComponent>("assets/waterbodyhorizontaltest01.png", 60, 1000/60, true);


}

// Handles the user input
void Game::handleEvents() {
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            // These are the keyboard presses
            // printf( SDL_GetKeyName( event.key.keysym.sym ));
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
//                case SDLK_d:
//                    player->d_pressed = true;
//                    break;
//                case SDLK_a:
//                    player->a_pressed = true;
//                    break;
//                case SDLK_SPACE:
//                    player->space_pressed = true;
//                    break;
                default:
                    break;
            }
            break;
        case SDL_KEYUP:
            // These are the keyboard presses
            // printf( SDL_GetKeyName( event.key.keysym.sym ));
            switch (event.key.keysym.sym) {
//                case SDLK_d:
//                    player->d_pressed = false;
//                    break;
//                case SDLK_a:
//                    player->a_pressed = false;
//                    break;
//                case SDLK_SPACE:
//                    player->space_pressed = false;
//                    player->jumped = false;
//                    player->jumpadd = false;
//                    break;
                default:
                    break;
            }
        default:
            break;
    }
}

// This is what happens every frame
void Game::update() {
    manager.refresh();
    manager.update();

    if (player.getComponent<TransformComponent>().position.x > 500)
        player.getComponent<SpriteComponent>().setTex("assets/wateranimationtest02.png", 10, 100);

    if (player.getComponent<TransformComponent>().position.x > width) {
        player.getComponent<TransformComponent>().position.x =
                0 - player.getComponent<SpriteComponent>().get_destRect().w;
    }
    if (player.getComponent<TransformComponent>().position.x < -player.getComponent<SpriteComponent>().get_destRect().w) {
        player.getComponent<TransformComponent>().position.x = width;
    }
    if (player.getComponent<TransformComponent>().position.y > height) {
        player.getComponent<TransformComponent>().position.y =
                0 - player.getComponent<SpriteComponent>().get_destRect().h;
    }
    if (player.getComponent<TransformComponent>().position.y < -player.getComponent<SpriteComponent>().get_destRect().h) {
        player.getComponent<TransformComponent>().position.y = height;
    }

    // Collision detection
    if (Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider)){
        player.getComponent<TransformComponent>().scale = 4;
        printf("Wall hit!\n");
    }
    else
        player.getComponent<TransformComponent>().scale = 2;
}

// This is what gets rendered every frame
void Game::render() {
    SDL_RenderClear(renderer);

    // add stuff to render here
    // remember layer order (lowest should be drawn first)
    map->DrawMap();
    manager.draw();

    SDL_RenderPresent(renderer);
}

// Cleans the game and stops the program
void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf( "Game cleaned");
}