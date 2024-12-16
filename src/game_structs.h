#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FRAME_DELAY = 20;
const int SNAKE_SQUARE_SIZE = 20;
const int SNAKE_SPEED = 20;
const int GRID_ROWS = (SCREEN_HEIGHT / SNAKE_SQUARE_SIZE);
const int GRID_COLS = (SCREEN_WIDTH / SNAKE_SQUARE_SIZE);

struct SnakePoint {
    int x_pos;
    int y_pos;
    char point_direction;
    SnakePoint* next;

    SnakePoint() {}

    SnakePoint(int x, int y, char dir) {
        this->x_pos = x;
        this->y_pos = y;
        this->point_direction = dir;
    }
};

struct FoodPoint {
    int x_pos;
    int y_pos;
};

struct Game {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int frameCounter;
    bool running;
    char snake_direction;
    SnakePoint* head;
    SnakePoint* tail;
    FoodPoint food;
    int** grid;
    bool did_eat;
    bool did_move;
    int score = 0;
};

enum directions {
    d_up = 'u',
    d_down = 'd',
    d_left = 'l',
    d_right = 'r'
};

struct Color {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
};
