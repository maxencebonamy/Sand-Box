#include "config.h"

// The name of the game window
const std::string WINDOW_TITLE { "SandBox" };
// The number of images displayed per second
const int WINDOW_FPS { 120 };
// The dimensions of the window (in pixels)
const Vector2 WINDOW_SIZE { 1280, 720 };

// The length of the side of a cell (in pixels)
const float CELL_SIZE { 5 };
// The dimensions of the grid (in pixels)
const Vector2 GRID_SIZE { WINDOW_SIZE / CELL_SIZE };

const sf::Color BACKGROUND_COLOR { 12, 15, 10 };