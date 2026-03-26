#include "first_input.h"
#include <stdio.h>

void first_input(char **current) {
    int c;
    int coll = 0;
    int row = 0;
    while ((c = getchar()) != EOF && row <= HEIGHT - 1) {
        if (coll > WIDTH - 1) {
            coll = 0;
            row += 1;
            if (row > HEIGHT - 1)
                break;
        }
        if (c == '\n') {
            for (; coll <= WIDTH - 1; coll++) {
                current[row][coll] = ' ';
            }
            row += 1;
            coll = 0;
        } else if (c == 'O') {
            current[row][coll] = 'O';
            coll++;
        } else {
            current[row][coll] = ' ';
            coll++;
        }
    }
    if (row != HEIGHT - 1) {
        for (int i = row; i <= HEIGHT - 1; i++) {
            int start = (i == row) ? coll : 0;
            for (int j = start; j <= WIDTH - 1; j++) {
                current[i][j] = ' ';
            }
        }
    }
}
