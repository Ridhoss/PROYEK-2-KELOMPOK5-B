#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/mainhead.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_LENGTH 100
#define CELL_SIZE 20

// Variabel global untuk ular
extern Segment ular[MAX_LENGTH]; // Array untuk menyimpan tubuh ular
extern int panjangUlar;          // Panjang awal ular
extern Direction arah;           // Arah pergerakan ular

// Fungsi untuk mengonversi warna dari string ke nilai integer
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
void tulisan(int x, int y, int lebar, int tinggi, CSTR warna, CSTR teks, int ukuran, typePenempatanTulisan penempatan) 
{
    setcolor(AmbilWarna(warna));
    settextstyle(BOLD_FONT, HORIZ_DIR, ukuran);

    char teksCopy[100];
    strcpy(teksCopy, teks);

    int textX, textY, textWidth, textHeight;

    if (penempatan == Center) {
        textWidth = textwidth(teksCopy);
        textHeight = textheight(teksCopy);
        textX = x + (lebar - textWidth) / 2;
        textY = y + (tinggi - textHeight) / 2;

    } else if (penempatan == Random) {
        textX = x;
        textY = y;
    }

    outtextxy(textX, textY, teksCopy);
}

// Fungsi menggambar kotak berisi warna
void Kotak(int x1, int y1, int x2, int y2, CSTR warna) 
{
    int ambilwarna = AmbilWarna(warna);

    setfillstyle(SOLID_FILL, ambilwarna);
    bar(x1, y1, x2, y2);

    setcolor(ambilwarna);
    rectangle(x1, y1, x2, y2);
}

// Fungsi membuat tombol dengan teks (lebih praktis)
void tombol(int x, int y, int panjang, int lebar, CSTR warna, CSTR teks, int ukuranTeks) 
{
    Kotak(x, y, x + panjang, y + lebar, warna);
    setbkcolor(AmbilWarna(warna));
    tulisan(x, y, panjang, lebar, "WHITE", teks, ukuranTeks, Center);
}

// Fungsi membuat posisi acak  
void GenerateRandomPosition(int *x, int *y) {
    *x = 20 + (rand() % ((SCREEN_WIDTH - 40) / 20)) * 20; // membuat posisi acak pada sumbu x
    *y = 60 + (rand() % ((SCREEN_HEIGHT - 80) / 20)) * 20; // membuat posisi acak pada sumbu y
}

//Fungsi membuat makanan
void Makanan(int x, int y) {
    Kotak(x, y, x + 20, y + 20, "RED"); // Menggambar makanan dalam bentuk kotak merah
}

// Variabel global untuk ular
Segment ular[MAX_LENGTH]; // Array untuk menyimpan posisi tubuh ular
int panjangUlar = 3;      // Panjang awal ular
Direction arah = RIGHT;   // Arah awal pergerakan ular

// Inisialisasi posisi awal ular
void InitUlar() {
    int startX = SCREEN_WIDTH / 2;
    int startY = SCREEN_HEIGHT / 2;

    for (int i = 0; i < panjangUlar; i++) {
        ular[i].x = startX - (i * CELL_SIZE);
        ular[i].y = startY;
    }
}

// Menggerakkan ular
void GerakUlar() {
    // Pindahkan badan ular mengikuti kepala
    for (int i = panjangUlar - 1; i > 0; i--) {
        ular[i] = ular[i - 1];
    }

    // Gerakkan kepala ular berdasarkan arah
    if (arah == UP) ular[0].y -= CELL_SIZE;
    if (arah == DOWN) ular[0].y += CELL_SIZE;
    if (arah == LEFT) ular[0].x -= CELL_SIZE;
    if (arah == RIGHT) ular[0].x += CELL_SIZE;
}

// Mengecek tabrakan dengan dinding atau tubuh sendiri
void CekTabrakan() {
    // Cek tabrakan dengan dinding
    if (ular[0].x < 20 || ular[0].x >= SCREEN_WIDTH - 20 ||
        ular[0].y < 60 || ular[0].y >= SCREEN_HEIGHT - 20) {
        exit(0);
    }
    // Cek tabrakan dengan tubuh sendiri
    for (int i = 1; i < panjangUlar; i++) {
        if (ular[0].x == ular[i].x && ular[0].y == ular[i].y) {
            exit(0);
        }
    }
}

// Mengecek apakah ular makan makanan
void CekMakanMakanan(int *makananX, int *makananY) {
    if (ular[0].x == *makananX && ular[0].y == *makananY) {
        panjangUlar++; // Tambah panjang ular
        GenerateRandomPosition(makananX, makananY); // Munculkan makanan baru
    }
}

// Menggambar ulang ular di layar
void GambarUlar() {
    for (int i = 0; i < panjangUlar; i++) {
        Kotak(ular[i].x, ular[i].y, ular[i].x + CELL_SIZE, ular[i].y + CELL_SIZE, "GREEN");
    }
}

// Loop utama game
void LoopGame() {
    int makananX, makananY;
    GenerateRandomPosition(&makananX, &makananY);

    while (1) {
        if (kbhit()) { // Cek jika ada input keyboard
            char key = getch();
            if (key == 72 && arah != DOWN) arah = UP;    // Panah atas
            if (key == 80 && arah != UP) arah = DOWN;    // Panah bawah
            if (key == 75 && arah != RIGHT) arah = LEFT; // Panah kiri
            if (key == 77 && arah != LEFT) arah = RIGHT; // Panah kanan
        }

        cleardevice(); // Bersihkan layar
        Kotak(20, 60, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, "BLACK"); // Gambar arena
        Makanan(makananX, makananY); // Gambar makanan
        GerakUlar(); // Perbarui posisi ular
        CekTabrakan(); // Cek tabrakan
        CekMakanMakanan(&makananX, &makananY); // Cek apakah ular makan makanan
        GambarUlar(); // Gambar ulang ular

        delay(100); // Beri jeda agar pergerakan lebih halus
    }
}