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

// header mengambil warna
int AmbilWarna(CSTR color);
// header membuat tulisan
void tulisan(int x, int y, int lebar, int tinggi, CSTR warna, CSTR teks, int ukuran, typePenempatanTulisan penempatan);
// header kotak
void Kotak(int x1, int y1, int x2, int y2, CSTR warna);
// header membuat tombol
void tombol(int x, int y, int panjang, int lebar, CSTR warna, CSTR teks, int ukuranTeks);
//header random posisi
void GenerateRandomPosition(int *x, int *y);
//header membuat makanan
void Makanan(int x, int y);
//header skor
void TampilkanSkor();
//header Inisialisasi posisi awal ular
void InitUlar();
//header Menggerakkan ular berdasarkan input
void GerakUlar();
//header Mengecek apakah ular bertabrakan dengan dinding/tubuhnya sendiri
void CekTabrakan();
//header Mengecek apakah ular memakan makanan
void CekMakanMakanan();
//header Menggambar ulang ular di layar
void GambarUlar();
//header stopwatch
void stopwatch();
//header memulai stopwatch
void startStopwatch();
//header Loop utama game
void LoopGame();

#endif   