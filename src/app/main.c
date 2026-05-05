#include "logic.h"
#include <stdlib.h>

int grid[20][20] = {0};

int main () {

    load_grid_from_file(TEST_GRID_PLACE, grid);

    while (1) {
        draw_grid(grid);
        update_grid(grid);
        sleep_ms();
    }

    return 0;  
}