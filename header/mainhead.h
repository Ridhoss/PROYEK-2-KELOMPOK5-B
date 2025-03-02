#ifndef MAINHEAD_H
#define MAINHEAD_H
#include <graphics.h>

typedef const char* CSTR;
typedef enum { Center, Random } typePenempatanTulisan;
typedef struct {int x, y;} Segment;
typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

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
// Inisialisasi posisi awal ular
void InitUlar();
// Menggerakkan ular berdasarkan input
void GerakUlar();
// Mengecek apakah ular bertabrakan dengan dinding/tubuhnya sendiri
void CekTabrakan();
// Mengecek apakah ular memakan makanan
void CekMakanMakanan();
// Menggambar ulang ular di layar
void GambarUlar();
// Loop utama game
void LoopGame();

#endif   