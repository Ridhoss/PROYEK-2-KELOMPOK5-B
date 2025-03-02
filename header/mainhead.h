#ifndef MAINHEAD_H
#define MAINHEAD_H
#include <graphics.h>

typedef const char* CSTR;
typedef enum { Center, Random } typePenempatanTulisan;

// header mengambil warna
int AmbilWarna(CSTR color);
// header membuat tulisan
void tulisan(int x, int y, int lebar, int tinggi, CSTR warna, CSTR teks, int ukuran, typePenempatanTulisan penempatan);
// header kotak
void Kotak(int x1, int y1, int x2, int y2, CSTR warna);
// header membuat tombol
void tombol(int x, int y, int panjang, int lebar, CSTR warna, CSTR teks, int ukuranTeks);
//header stopwatch
void stopwatch();
#endif   