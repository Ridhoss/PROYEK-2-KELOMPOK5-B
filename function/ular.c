#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/ular.h"
#include "../header/mainhead.h"
#include "../header/pages.h"
#include "../header/makanan.h"
#include "../header/stopwatch.h"

extern int score;

Segment ular[MAX_LENGTH];
int panjangUlar = 3;
Direction arah = RIGHT;

//Fungsi Inisialisasi posisi awal ular
void InitUlar() {
    int startX = SCREEN_WIDTH / 2;
    int startY = SCREEN_HEIGHT / 2;

    for (int i = 0; i < panjangUlar; i++) {
        ular[i].x = startX - (i * CELL_SIZE);
        ular[i].y = startY;
    }
}

//Fungsi Menggerakkan ular
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

//Fungsi Mengecek tabrakan dengan dinding atau tubuh sendiri
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

//FUngsi Mengecek apakah ular makan makanan
void CekMakanMakanan(int *makananX, int *makananY) {
    if (ular[0].x == *makananX && ular[0].y == *makananY) {
        panjangUlar++; // Tambah panjang ular
        score++; //menambah skor 
        GenerateRandomPosition(makananX, makananY); // Munculkan makanan baru
    }
}

//Fungsi Menggambar ulang ular di layar
void GambarUlar() {
    for (int i = 0; i < panjangUlar; i++) {
        Kotak(ular[i].x, ular[i].y, ular[i].x + CELL_SIZE, ular[i].y + CELL_SIZE, "GREEN");
    }
}