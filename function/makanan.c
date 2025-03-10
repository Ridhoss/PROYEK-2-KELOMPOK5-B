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
    *x = 20 + (rand() % ((SCREEN_WIDTH - 40) / 20)) * 20; // membuat posisi acak pada sumbu x
    *y = 60 + (rand() % ((SCREEN_HEIGHT - 80) / 20)) * 20; // membuat posisi acak pada sumbu y
}

//Fungsi membuat makanan
void Makanan(int x, int y) {
    Kotak(x, y, x + 20, y + 20, "RED"); // Menggambar makanan dalam bentuk kotak merah
}