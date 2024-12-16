#include "window.h"

#include <SDL3/SDL_hints.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <_stdlib.h>

#include "draw.h"
#include "game_structs.h"

void init_window(Game* game) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    game->window = SDL_CreateWindow("Snake", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

    if (!game->window) {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_SetHint("SDL_RENDER_SCALE_QUALITY", "linear");

    game->renderer = SDL_CreateRenderer(game->window, "opengl");

    if (!game->renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    game->snake_direction = 'r';
}
