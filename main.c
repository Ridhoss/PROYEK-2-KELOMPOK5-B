#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "header/basicfunction.h"
#include "header/pages.h"
#include "header/makanan.h"
#include "header/ular.h"
#include "header/stopwatch.h"
#include "header/mechanism.h"

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int posisiLayar = 0;

    for (;;) {
        cleardevice();
        if(posisiLayar == 0) {
            tampilanAwal();
        } else if(posisiLayar == 1) {
            tampilanArena();
        }

        char key = getch();
        if(key == 101) {
            posisiLayar = 1;
        } else if(key == 27) {
            break;
        }
    }

    getch();
    closegraph();
    return 0;

}
