#pragma once
#ifndef MAKANAN_H
#define MAKANAN_H
#include <graphics.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_LENGTH 100
#define CELL_SIZE 20

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