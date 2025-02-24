#include "../header/mainhead.h"
#include <graphics.h>

// function warna
int AmbilWarna(const char *color) {
    if (strcmp(color, "BLACK") == 0) return BLACK;
    if (strcmp(color, "BLUE") == 0) return BLUE;
    if (strcmp(color, "GREEN") == 0) return GREEN;
    if (strcmp(color, "CYAN") == 0) return CYAN;
    if (strcmp(color, "RED") == 0) return RED;
    if (strcmp(color, "MAGENTA") == 0) return MAGENTA;
    if (strcmp(color, "BROWN") == 0) return BROWN;
    if (strcmp(color, "LIGHTGRAY") == 0) return LIGHTGRAY;
    if (strcmp(color, "DARKGRAY") == 0) return DARKGRAY;
    if (strcmp(color, "LIGHTBLUE") == 0) return LIGHTBLUE;
    if (strcmp(color, "LIGHTGREEN") == 0) return LIGHTGREEN;
    if (strcmp(color, "LIGHTCYAN") == 0) return LIGHTCYAN;
    if (strcmp(color, "LIGHTRED") == 0) return LIGHTRED;
    if (strcmp(color, "LIGHTMAGENTA") == 0) return LIGHTMAGENTA;
    if (strcmp(color, "YELLOW") == 0) return YELLOW;
    if (strcmp(color, "WHITE") == 0) return WHITE;
    
    return WHITE;
}

// procedure membuat kotak
void Kotak(int x1, int y1, int x2, int y2, const char *warna) {

    int ambilwarna = AmbilWarna(warna);
    setcolor(ambilwarna);

    line(x1, y1, x2, y1); // Garis atas
    line(x2, y1, x2, y2); // Garis kanan
    line(x2, y2, x1, y2); // Garis bawah
    line(x1, y2, x1, y1); // Garis kiri
}