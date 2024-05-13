#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP

#include "ApplicationElements.h"
#include "Libs.h"

const int ROWS = SCREEN_HEIGHT / CELL_SIZE;
const int COLS = SCREEN_WIDTH / CELL_SIZE;

namespace cellularAutomaton {
    class game_of_life {
    public:
        game_of_life()
            : system(ROWS, std::vector<bool>(COLS, false)),
            manualCells(ROWS, std::vector<bool>(COLS, false)) {
            system_init();
        }

        std::vector<Vector2> newCells;

        std::vector<std::vector<bool>> system;

        void update_system(bool manualMode);

        bool generate_system(bool manualMode);

        void add_cell(Vector2 position, bool manualMode);

        void create_artificial_generation(int newborns_amount, bool manualMode);

        void clear_manual_cells();

        int count_alive_neighbors(int x, int y, const std::vector<std::vector<bool>>& targetSystem);

        void system_init();

    private:
       
        std::vector<std::vector<bool>> manualCells;

    };
} // namespace cellularAutomaton

#endif // GAME_OF_LIFE_HPP