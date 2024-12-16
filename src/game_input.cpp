#include "game_input.h"

#include <SDL3/SDL_events.h>
#include <_stdlib.h>

#include "game.h"
#include "game_structs.h"

void handle_input(Game* game) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                exit(1);
            case SDL_EVENT_KEY_DOWN:
                if (game->did_move) break;

                switch (event.key.key) {
                    case SDLK_ESCAPE:
                        exit(0);
                    case SDLK_W:
                    case SDLK_UP:
                        if (game->snake_direction == d_down) break;
                        game->snake_direction = d_up;
                        game->did_move = true;
                        break;
                    case SDLK_S:
                    case SDLK_DOWN:
                        if (game->snake_direction == d_up) break;
                        game->snake_direction = d_down;
                        game->did_move = true;
                        break;
                    case SDLK_A:
                    case SDLK_LEFT:
                        if (game->snake_direction == d_right) break;
                        game->snake_direction = d_left;
                        game->did_move = true;
                        break;
                    case SDLK_D:
                    case SDLK_RIGHT:
                        if (game->snake_direction == d_left) break;
                        game->snake_direction = d_right;
                        game->did_move = true;
                        break;
                        // TODO:
                        // case SDLK_SPACE:
                        //     if (game->running) break;
                        //     init_game(game);
                }

            default:
                break;
        }
    }
}