#include "game.h"

#include <_stdlib.h>

#include "draw.h"
#include "game_structs.h"

void init_game(Game* game) {
    game->grid = new int*[GRID_ROWS];
    for (int i = 0; i < GRID_COLS; i++) {
        game->grid[i] = new int[GRID_COLS];
    }
    game->snake_direction = 'r';
    game->frameCounter = 0;
    game->running = true;
    game->did_eat = false;
    game->did_move = false;

    game->food.y_pos = GRID_ROWS / 2;
    game->food.x_pos = (GRID_COLS / 4) * 3;
    game->grid[game->food.y_pos][game->food.x_pos] = 2;

    game->head = new SnakePoint((GRID_COLS / 2) - 1, GRID_ROWS / 2, game->snake_direction);

    // SnakePoint* one = new SnakePoint((GRID_COLS / 2) - 2, GRID_ROWS / 2, game->snake_direction);
    // SnakePoint* two = new SnakePoint((GRID_COLS / 2) - 3, GRID_ROWS / 2, game->snake_direction);
    // SnakePoint* three = new SnakePoint((GRID_COLS / 2) - 4, GRID_ROWS / 2, game->snake_direction);

    // game->head->next = one;
    // one->next = two;
    // two->next = three;
    // game->tail = three;

    game->tail = game->head;
}

void render_grid(Game* game) {
    // for (int row = 0; row < GRID_ROWS; row++) {
    //     for (int col = 0; col < GRID_COLS; col++) {
    //         if (game->grid[row][col] == 1) {
    //             draw_rect(game, {col * 20.0f, row * 20.0f, 20, 20}, {0, 0, 0, 255});
    //         } else if (game->grid[row][col] == 2) {
    //             draw_rect(game, {col * 20.0f, row * 20.0f, 20, 20}, {0, 150, 0, 255});
    //         }
    //     }
    // }

    draw_rect(game, {game->food.x_pos * 20.0f, game->food.y_pos * 20.0f, 20, 20}, {0, 150, 0, 255});

    SnakePoint* current = game->head;
    while (current) {
        draw_rect(game, {current->x_pos * 20.0f, current->y_pos * 20.0f, 20, 20}, {0, 0, 0, 255});
        current = current->next;
    }
}

void add_food(Game* game) {
    srand(time(0));

    while (true) {
        int row = rand() % GRID_ROWS;
        int col = rand() % GRID_COLS;

        if (game->grid[row][col] == 0) {
            game->grid[row][col] = 2;
            game->food.x_pos = col;
            game->food.y_pos = row;

            return;
        }
    }
}

void update_game(Game* game) {
    if (game->frameCounter % 50 != 0) {
        return;
    }

    game->did_move = false;
    game->grid[game->tail->y_pos][game->tail->x_pos] = 0;
    int new_y = game->tail->y_pos;
    int new_x = game->tail->x_pos;

    char next_direction = game->snake_direction;
    char temp;
    SnakePoint* current = game->head;
    while (current) {
        temp = current->point_direction;
        current->point_direction = next_direction;
        next_direction = temp;

        switch (current->point_direction) {
            case d_up:
                current->y_pos -= 1;
                break;
            case d_down:
                current->y_pos += 1;
                break;
            case d_left:
                current->x_pos -= 1;
                break;
            case d_right:
                current->x_pos += 1;
                break;
        }

        if (current->y_pos < 0) {
            current->y_pos = GRID_ROWS - 1;
        } else if (current->y_pos >= GRID_ROWS) {
            current->y_pos = 0;
        }

        if (current->x_pos < 0) {
            current->x_pos = GRID_COLS - 1;
        } else if (current->x_pos >= GRID_COLS) {
            current->x_pos = 0;
        }

        current = current->next;
    }

    if (game->did_eat) {
        SnakePoint* new_tail = new SnakePoint(new_x, new_y, game->tail->point_direction);
        game->tail->next = new_tail;
        game->tail = new_tail;
        game->grid[new_y][new_x] = 1;

        game->did_eat = false;
        game->score++;

        add_food(game);
    } else if (game->grid[game->head->y_pos][game->head->x_pos] == 2) {
        game->did_eat = true;
    }

    if (game->grid[game->head->y_pos][game->head->x_pos] == 1) {
        game->running = false;
    } else {
        game->grid[game->head->y_pos][game->head->x_pos] = 1;
    }
}