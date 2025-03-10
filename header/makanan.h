#ifndef MAKANAN_H
#define MAKANAN_H
#include <graphics.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_LENGTH 100
#define CELL_SIZE 20

void GenerateRandomPosition(int *x, int *y);

void Makanan(int x, int y);

#endif   