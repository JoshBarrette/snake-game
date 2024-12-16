#include <SDL3/SDL_timer.h>

#include "draw.h"
#include "game.h"
#include "game_input.h"
#include "game_structs.h"
#include "window.h"

int main() {
    Game* game = new Game;
    init_window(game);
    init_game(game);

    while (true) {
        game->frameCounter %= 1000;
        clear_background(game);

        if (game->running) {
            update_game(game);
        }

        render_grid(game);

        handle_input(game);

        SDL_RenderPresent(game->renderer);

        SDL_Delay(FRAME_DELAY);
        game->frameCounter += FRAME_DELAY;
    }

    return 0;
}
