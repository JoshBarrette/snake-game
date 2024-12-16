#include "draw.h"

#include "game_structs.h"

bool clear_background(Game* game) {
    SDL_SetRenderDrawColor(game->renderer, 245, 245, 245, 255);
    return SDL_RenderClear(game->renderer);
}

bool draw_rect(Game* game, SDL_FRect rec, Color color) {
    SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
    return SDL_RenderFillRect(game->renderer, &rec);
}