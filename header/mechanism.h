#ifndef MECHANISM_H
#define MECHANISM_H
#include <graphics.h>

extern bool paused;
extern bool gameOver;
extern int kepalaX;
extern int kepalaY;
extern int score;
extern int makananX;
extern int makananY;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define BORDER_SIZE 20
#define CELL_SIZE 20

#define MAX_LENGTH ((SCREEN_WIDTH - 2 * BORDER_SIZE) / CELL_SIZE) * ((SCREEN_HEIGHT - 2 * BORDER_SIZE) / CELL_SIZE)

// prosedur untuk menampilkan score
void Tampilkanscore();
// prosedur untuk tombol mekanisme tombol pause
void Tombolpause();
// prosedur untuk menghandle interaksi tombol pause
void HandlePause(int x, int y);
// header loop game
void LoopGame();
// header reset
void ResetGame();

#endif   