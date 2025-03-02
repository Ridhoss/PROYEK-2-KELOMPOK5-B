#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "header/mainhead.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    srand(time(NULL));

    // background
    setbkcolor(CYAN);
    cleardevice();

    // arena
    Kotak(20, 60, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, "BLACK");

    // ular
    Kotak(20, 60, 40, 80, "GREEN");

    // makanan 
    int makananX, makananY;
    GenerateRandomPosition(&makananX, &makananY);
    Makanan(makananX, makananY);
    
    getch();
    closegraph();
    return 0;
}
