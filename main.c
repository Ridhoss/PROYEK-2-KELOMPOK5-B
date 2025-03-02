#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include "header/mainhead.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    setbkcolor(CYAN);
    cleardevice();

    tombol(150, 150, 150, 50, "RED", "Klik Saya");
    
    getch();
    closegraph();
    return 0;
}