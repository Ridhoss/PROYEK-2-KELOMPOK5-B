#ifndef MAINHEAD_H
#define MAINHEAD_H

// header mengambil warna
int AmbilWarna(const char *color);
// header kotak
void Kotak(int x1, int y1, int x2, int y2, const char *warna);
// header membuat tombol
void tombol(int x, int y, int panjang, int lebar, const char *warna, const char *teks);

#endif   