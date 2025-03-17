#ifndef MAKANAN_H
#define MAKANAN_H
#include <graphics.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define BORDER_SIZE 20
#define CELL_SIZE 20
#define MAX_LENGTH ((SCREEN_WIDTH - 2 * BORDER_SIZE) / CELL_SIZE) * ((SCREEN_HEIGHT - 2 * BORDER_SIZE) / CELL_SIZE)

void GenerateRandomPosition(int *x, int *y);

void Makanan(int x, int y);

#endif   