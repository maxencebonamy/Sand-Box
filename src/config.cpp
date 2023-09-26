#include "config.h"

// The name of the game window
const std::string WINDOW_TITLE { "SandBox" };
// The number of images displayed per second
const int WINDOW_FPS { 120 };
// The dimensions of the window (in pixels)
const Vector2 WINDOW_SIZE { 1920, 1080 };

const bool WINDOW_FULLSCREEN { true };

// The length of the side of a cell (in pixels)
const float CELL_SIZE { 5 };
// The dimensions of the grid (in pixels)
const Vector2 GRID_SIZE { WINDOW_SIZE / CELL_SIZE };