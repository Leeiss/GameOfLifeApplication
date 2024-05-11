#include "../headers/ApplicationLogic.h"

namespace cellularAutomaton {
    void game_of_life::update_system(bool manualMode) {
        auto& targetSystem = manualMode ? manualCells : system;
        auto new_system = targetSystem;
        newCells.clear();
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                // Calculate the number of live neighbors for the current cell.
                int alive_neighbors = count_alive_neighbors(i, j, targetSystem);
                // If the cell is alive and has 2 or 3 live neighbors, it remains alive.
                // If the cell is dead and has exactly 3 live neighbors, it becomes alive.
                new_system[i][j] = (targetSystem[i][j] && alive_neighbors >= 2 &&
                                    alive_neighbors <= 3) ||
                                    (!targetSystem[i][j] && alive_neighbors == 3);
            }
        }

        targetSystem = new_system;
    }

    bool game_of_life::generate_system(bool manualMode) {
        auto& targetSystem = manualMode ? manualCells : system;
        bool anyCellsLeft = false;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                Color cell_color =
                    targetSystem[i][j] ? Color{116, 66, 200, 255} : BLACK;
                DrawRectangle(j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE,
                            cell_color);
                if (targetSystem[i][j]) {
                    anyCellsLeft = true;
                }
            }
        }

        if (!anyCellsLeft && manualMode) {
            return false;
        }
        return true;
    }

    void game_of_life::add_cell(Vector2 position, bool manualMode) {
        int cell_x = static_cast<int>(position.x / CELL_SIZE);
        int cell_y = static_cast<int>(position.y / CELL_SIZE);

        if (cell_x >= 0 && cell_x < COLS && cell_y >= 0 && cell_y < ROWS) {
            if (manualMode) {
                if (!manualCells[cell_y][cell_x]) {
                    DrawRectangle(cell_x * CELL_SIZE, cell_y * CELL_SIZE, CELL_SIZE,
                                CELL_SIZE, Color{116, 66, 200, 255});
                    manualCells[cell_y][cell_x] = true;
                }
            } else {
                if (!system[cell_y][cell_x]) {
                    DrawRectangle(cell_x * CELL_SIZE, cell_y * CELL_SIZE, CELL_SIZE,
                                CELL_SIZE, Color{116, 66, 200, 255});
                    system[cell_y][cell_x] = true;
                }
            }
        }
    }

    void game_of_life::create_artificial_generation(int newborns_amount, bool manualMode) {
        if (manualMode) {
            return;
        }
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> dist_x(0, ROWS - 1);
        std::uniform_int_distribution<int> dist_y(0, COLS - 1);

        for (int i = 0; i < newborns_amount; ++i) {
            int random_x = dist_x(gen);
            int random_y = dist_y(gen);
            system[random_x][random_y] = true;

            Color cell_color = system[random_x][random_y] ? PINK : BLACK;
            DrawRectangle(random_y * CELL_SIZE, random_x * CELL_SIZE, CELL_SIZE,
                        CELL_SIZE, cell_color);
        }
    }

    void game_of_life::clear_manual_cells() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                manualCells[i][j] = false;
            }
        }
    }

    void game_of_life::system_init() {
        std::srand(static_cast<unsigned>(std::time(nullptr)));

        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                system[i][j] = std::rand() % 2 == 1;
            }
        }
    }

    int game_of_life::count_alive_neighbors(
        int x, int y, const std::vector<std::vector<bool>>& targetSystem) {
        int neighbors_counter = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int another_x = x + i;
                int another_y = y + j;

                if (another_x >= 0 && another_x < ROWS && another_y >= 0 &&
                    another_y < COLS) {
                    if (targetSystem[another_x][another_y]) {
                        ++neighbors_counter;
                    }
                }
            }
        }

        return neighbors_counter;
    }
} // namespace cellularAutomaton
