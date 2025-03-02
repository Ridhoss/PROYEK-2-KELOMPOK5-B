#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "header/mainhead.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // background
    setbkcolor(CYAN);
    cleardevice();

    // tulisan judul
    char judul[50] = "SNACK SNAKE B5";
    tulisan(0, 120, SCREEN_WIDTH, 0, "WHITE", judul, 6, Center);

    // ukuran tombol
    int tombolLebar = 200;
    int tombolTinggi = 50;
    int posisiX = (SCREEN_WIDTH - tombolLebar) / 2;
    int posisiY = 190;

    // tombol Start
    tombol(posisiX, posisiY, tombolLebar, tombolTinggi, "DARKGRAY", "START" , 3);
    // tombol Exit
    tombol(posisiX, posisiY + 80, tombolLebar, tombolTinggi, "DARKGRAY", "EXIT", 3);

    getch();
    closegraph();
    return 0;
}
