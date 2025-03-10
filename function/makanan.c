#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/makanan.h"
#include "../header/mainhead.h"
#include "../header/pages.h"
#include "../header/ular.h"
#include "../header/stopwatch.h"



// Fungsi membuat posisi acak  
void GenerateRandomPosition(int *x, int *y) {
    *x = 20 + (rand() % ((SCREEN_WIDTH - 40) / 20)) * 20;
    *y = 60 + (rand() % ((SCREEN_HEIGHT - 80) / 20)) * 20;
}

// Fungsi untuk menentukan jenis makanan secara acak
makananType GeneratemakananType() {
    int random = rand() % 10; // 0-9

    if (random < 4) return NORMAL;   // 40% makanan normal
    if (random < 8) return SPECIAL;  // 40% makanan spesial
    return POISON;                   // 20% makanan beracun
}

// Fungsi membuat makanan
void Makanan(MakananStruct makanan) {
    switch (makanan.type) {
        case NORMAL:
            Kotak(makanan.x, makanan.y, makanan.x + 20, makanan.y + 20, "RED");  // Makanan biasa (merah)
            break;
        case SPECIAL:
            Kotak(makanan.x, makanan.y, makanan.x + 20, makanan.y + 20, "BLUE"); // Makanan spesial (biru)
            break;
        case POISON:
            Kotak(makanan.x, makanan.y, makanan.x + 20, makanan.y + 20, "GREEN"); // Makanan beracun (hijau)
            break;
    }
}
