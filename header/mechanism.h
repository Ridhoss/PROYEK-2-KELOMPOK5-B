#ifndef MECHANISM_H
#define MECHANISM_H
#include <graphics.h>

extern bool paused;
extern bool gameOver;
extern int score;

extern int fullscreen_width;
extern int fullscreen_height;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500

#define BORDER_SIZE 20
#define CELL_SIZE 20

#define MAX_LENGTH ((SCREEN_WIDTH - 2 * BORDER_SIZE) / CELL_SIZE) * ((SCREEN_HEIGHT - 2 * BORDER_SIZE) / CELL_SIZE)

// prosedur untuk menampilkan score
void Tampilkanscore();
// prosedur untuk tombol mekanisme tombol pause
void Tombolpause();
// prosedur untuk menghandle interaksi tombol pause
void HandlePause(int x, int y);
// header cek input user
void CekInputUser();
// header loop game
void LoopGame();
// header reset
void ResetGame();

#endif   