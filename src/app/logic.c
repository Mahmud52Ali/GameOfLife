#include "logic.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <unistd.h>
#endif

void clear_console(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void sleep_ms(void) {
#if defined(_WIN32) || defined(_WIN64)
    Sleep(SLEEPTIME);
#else
    usleep(SLEEPTIME * 1000);
#endif
}

int load_grid_from_file(const char *path, int grid[20][20]) {
    FILE *f = fopen(path, "r");
    if (!f) {
        return 0;
    }

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            int val = 0;
            if (fscanf(f, "%d", &val) != 1) {
                val = 0;
            }
            grid[i][j] = val;
        }
    }

    fclose(f);
    return 1;
}

void draw_grid(int grid[20][20]) {
    clear_console();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++)
            printf("%c", grid[i][j] ? 'O' : ' ');
        printf("\n");
    }
}

void update_grid (int grid[20][20]) {
    int new_grid[20][20] = {0};

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++) {
            int live_neighbors = count_live_neighbors(i, j, grid);

            if (grid[i][j])
                new_grid[i][j] = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
            else 
                new_grid[i][j] = (live_neighbors == 3) ? 1 : 0;
            
        }

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            grid[i][j] = new_grid[i][j];
}

int count_live_neighbors(int x, int y, int grid[20][20]) {
    int count = 0;

    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0)
                continue;

            int neighbor_x = x + i;
            int neighbor_y = y + j;

            if (neighbor_x >= 0 && neighbor_x < 20 && neighbor_y >= 0 && neighbor_y < 20)
                count += 1 * (grid[neighbor_x][neighbor_y] != 0);
        }

    return count;
}