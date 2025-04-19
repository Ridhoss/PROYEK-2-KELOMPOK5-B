#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../header/basicfunction.h"
#include "../header/makanan.h"
#include "../header/pages.h"
#include "../header/ular.h"
#include "../header/stopwatch.h"
#include "../header/mechanism.h"

// Fungsi untuk mengonversi warna dari string ke nilai integer
// pembuat modul : Ridho
// dimodifikasi oleh : -
int AmbilWarna(CSTR color) 
{
    if (strcmp(color, "BLACK") == 0) return BLACK;
    if (strcmp(color, "BLUE") == 0) return BLUE;
    if (strcmp(color, "GREEN") == 0) return GREEN;
    if (strcmp(color, "CYAN") == 0) return CYAN;
    if (strcmp(color, "RED") == 0) return RED;
    if (strcmp(color, "MAGENTA") == 0) return MAGENTA;
    if (strcmp(color, "BROWN") == 0) return BROWN;
    if (strcmp(color, "LIGHTGRAY") == 0) return LIGHTGRAY;
    if (strcmp(color, "DARKGRAY") == 0) return DARKGRAY;
    if (strcmp(color, "LIGHTBLUE") == 0) return LIGHTBLUE;
    if (strcmp(color, "LIGHTGREEN") == 0) return LIGHTGREEN;
    if (strcmp(color, "LIGHTCYAN") == 0) return LIGHTCYAN;
    if (strcmp(color, "LIGHTRED") == 0) return LIGHTRED;
    if (strcmp(color, "LIGHTMAGENTA") == 0) return LIGHTMAGENTA;
    if (strcmp(color, "YELLOW") == 0) return YELLOW;
    if (strcmp(color, "WHITE") == 0) return WHITE;
    
    return WHITE;
}

// Fungsi membuat teks
// pembuat modul : Ridho
// dimodifikasi oleh : -
void tulisan(int x, int y, int widthP, int heightP, CSTR warna, CSTR teks, int ukuran, typePenempatanTulisan penempatan) 
{
    setcolor(AmbilWarna(warna));
    settextstyle(BOLD_FONT, HORIZ_DIR, ukuran);

    char teksCopy[100];
    strcpy(teksCopy, teks);

    int textX, textY, textWidth, textHeight;

    if (penempatan == Center) {
        textWidth = textwidth(teksCopy);
        textHeight = textheight(teksCopy);
        textX = x + (widthP - textWidth) / 2;
        textY = y + (heightP - textHeight) / 2;

    } else if (penempatan == Random) {
        textX = x;
        textY = y;
    }

    outtextxy(textX, textY, teksCopy);
}

// Fungsi menggambar kotak berisi warna
// pembuat modul : Ridho
// dimodifikasi oleh : -
void Kotak(int x1, int y1, int x2, int y2, CSTR warna) 
{
    int ambilwarna = AmbilWarna(warna);

    setfillstyle(SOLID_FILL, ambilwarna);
    bar(x1, y1, x2, y2);

    setcolor(ambilwarna);
    rectangle(x1, y1, x2, y2);
}

// Fungsi untuk menggambar titik-titik putih secara acak di layar
// pembuat modul : Salma
// dimodifikasi oleh : -
void Titik() 
{
    int jml = 20;  
    int ukuran = 4;

    srand(time(NULL)); // Seed untuk posisi acak

    for (int i = 0; i < jml; i++) {
        int x = rand() % getmaxx(); // Acak posisi x
        int y = rand() % getmaxy(); // Acak posisi y

        setfillstyle(SOLID_FILL, AmbilWarna("WHITE"));
        fillellipse(x, y, ukuran / 2, ukuran / 2); 
    }
}

// Fungsi membuat tombol dengan teks (lebih praktis)
// pembuat modul : Ridho
// dimodifikasi oleh : -
void tombol(int x, int y, int panjang, int lebar, CSTR warna, CSTR teks, int ukuranTeks) 
{
    Kotak(x, y, x + panjang, y + lebar, warna);
    setbkcolor(AmbilWarna(warna));
    tulisan(x, y, panjang, lebar, "WHITE", teks, ukuranTeks, Center);
}

// Fungsi untuk menggambar awan
// pembuat modul : Salma
// dimodifikasi oleh : -
void gambarAwan(int x, int y) 
{
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, 30, 20);
    fillellipse(x + 20, y + 10, 30, 20);
    fillellipse(x - 20, y + 10, 30, 20);
    fillellipse(x + 40, y, 30, 20);
    fillellipse(x - 40, y, 30, 20);
}