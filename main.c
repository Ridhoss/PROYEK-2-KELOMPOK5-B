#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include "header/mainhead.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); 

    // batas tampilan
    Kotak(10, 10, SCREEN_WIDTH - 10, SCREEN_HEIGHT - 10, "WHITE");

    // arena
    Kotak(20, 60, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, "WHITE");

    // ular
    Kotak(20, 60, 40, 80, "GREEN");

    getch();
    closegraph();
    return 0;
}