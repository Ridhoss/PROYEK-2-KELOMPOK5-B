#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/mainhead.h"
#include "../header/pages.h"
#include "../header/makanan.h"
#include "../header/ular.h"
#include "../header/stopwatch.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void tampilanAwal() {
    setbkcolor(CYAN);
    cleardevice();

    char judul[] = "SNACK SNAKE B5";
    tulisan(0, 120, SCREEN_WIDTH, 0, "WHITE", judul, 6, Center);

    int tombolLebar = 200, tombolTinggi = 50;
    int posisiX = (SCREEN_WIDTH - tombolLebar) / 2;
    int posisiY = 190;

    tombol(posisiX, posisiY, tombolLebar, tombolTinggi, "DARKGRAY", "START", 3);
    tombol(posisiX, posisiY + 80, tombolLebar, tombolTinggi, "DARKGRAY", "EXIT", 3);
}

void tampilanArena() {
    setbkcolor(CYAN);
    cleardevice();

    Kotak(20, 60, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, "WHITE");

    tombol(520, 15, 100, 30, "DARKGRAY", "PAUSE", 2);

    // Inisialisasi ular
    InitUlar();

    // Mulai loop game
    LoopGame();

    // char score[100] = "Score: 0";
    // tulisan(20, 20, 0, 0, "WHITE", score, 2, Random);

    // char stopwatch[100] = "00:20:00";
    // tulisan(0, 30, SCREEN_WIDTH, 0, "WHITE", stopwatch, 2, Center);
}