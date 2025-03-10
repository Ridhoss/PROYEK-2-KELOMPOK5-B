#ifndef ULAR_H
#define ULAR_H
#include <graphics.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_LENGTH 100
#define CELL_SIZE 20

typedef struct {int x, y;} Segment;
typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

// Variabel global untuk ular
extern Segment ular[MAX_LENGTH]; // Array untuk menyimpan tubuh ular
extern int panjangUlar;          // Panjang awal ular
extern Direction arah;           // Arah pergerakan ular

void InitUlar();

void GerakUlar();

void CekTabrakan();

bool CekMakanMakanan(MakananStruct *makanan);

void GambarUlar();

#endif