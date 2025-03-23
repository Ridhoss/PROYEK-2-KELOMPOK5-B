#ifndef BASICFUNCTION_H
#define BASICFUNCTION_H
#include <graphics.h>
#include "mechanism.h"

typedef const char* CSTR;
typedef enum { Center, Random } typePenempatanTulisan;

// header mengambil warna
int AmbilWarna(CSTR color);
// header membuat tulisan
void tulisan(int x, int y, int widthP, int heightP, CSTR warna, CSTR teks, int ukuran, typePenempatanTulisan penempatan);
// header kotak
void Kotak(int x1, int y1, int x2, int y2, CSTR warna);
// prosedur untuk membuat hiasan titik putih secara acak
void Titik();
// header membuat tombol
void tombol(int x, int y, int panjang, int lebar, CSTR warna, CSTR teks, int ukuranTeks);
// prosedur untuk membuat hiasan awan
void gambarAwan(int x, int y);

#endif   