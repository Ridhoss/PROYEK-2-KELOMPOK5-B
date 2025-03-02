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

    // arena
    Kotak(20, 60, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, "WHITE");

    // ular
    // Kotak(20, 60, 40, 80, "WHITE");

    // tombol button
    tombol(520, 15, 100, 30, "DARKGRAY", "PAUSE", 2);

    getch();
    closegraph();
    return 0;

}
