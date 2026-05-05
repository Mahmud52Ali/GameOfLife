#ifndef LOGIC_H
#define LOGIC_H

#define SLEEPTIME 100
#define TEST_GRID_PLACE "src/input/test_field.txt"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear_console(void); // Кроссплатформенная очистка консоли
void sleep_ms(void); // Кроссплатформенный sleep
int load_grid_from_file(const char *path, int grid[20][20]); // Загрузка поля из файла
void draw_grid(int grid[20][20]); // Отрисовываем поле в консоль
void update_grid(int grid[20][20]); // Обновляем поле с учетом правил "Игра жизнь"
int count_live_neighbors(int x, int y, int grid[20][20]); // Подсчёт живых соседей

#endif 