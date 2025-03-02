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

     // tulisan score
     setbkcolor(CYAN);
     char score[100] = "Score: 0";
     tulisan(20, 20, 0, 0, "WHITE", score, 2, Random);

     // tulisan stopwatch
    char stopwatch[100] = "00:20:00";
    tulisan(0, 30, SCREEN_WIDTH, 0, "WHITE", stopwatch, 2, Center);

    getch();
    closegraph();
    return 0;

}
