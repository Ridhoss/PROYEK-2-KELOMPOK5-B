#pragma once
#ifndef MAKANAN_H
#define MAKANAN_H
#include <graphics.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define BORDER_SIZE 20
#define CELL_SIZE 20
#define MAX_LENGTH ((SCREEN_WIDTH - 2 * BORDER_SIZE) / CELL_SIZE) * ((SCREEN_HEIGHT - 2 * BORDER_SIZE) / CELL_SIZE)

typedef enum {
    NORMAL,
    SPECIAL,
    POISON
} makananType;

// Struktur untuk makanan
typedef struct {
    int x, y;
    makananType type;
    double spawnTime; // Waktu saat makanan muncul
} MakananStruct;

void GenerateRandomPosition(int *x, int *y);

void Makanan(MakananStruct makanan);

makananType GeneratemakananType();

#endif   