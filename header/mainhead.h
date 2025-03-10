#ifndef MAINHEAD_H
#define MAINHEAD_H
#include <graphics.h>

typedef const char* CSTR;
typedef enum { Center, Random } typePenempatanTulisan;
typedef struct {int x, y;} Segment;
typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_LENGTH 100
#define CELL_SIZE 20

// Variabel global untuk ular
extern Segment ular[MAX_LENGTH]; // Array untuk menyimpan tubuh ular
extern int panjangUlar;          // Panjang awal ular
extern Direction arah;           // Arah pergerakan ular

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_LENGTH 100
#define CELL_SIZE 20

// header mengambil warna
int AmbilWarna(CSTR color);
// header membuat tulisan
void tulisan(int x, int y, int lebar, int tinggi, CSTR warna, CSTR teks, int ukuran, typePenempatanTulisan penempatan);
// header kotak
void Kotak(int x1, int y1, int x2, int y2, CSTR warna);
// header membuat tombol
void tombol(int x, int y, int panjang, int lebar, CSTR warna, CSTR teks, int ukuranTeks);
// header loop game
void LoopGame();

#endif   