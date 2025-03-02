#include <graphics.h>
#include <conio.h>
#include <string.h>

// Fungsi untuk mengonversi warna dari string ke nilai integer
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

// Fungsi menggambar kotak berisi warna
void Kotak(int x1, int y1, int x2, int y2, const char *warna) {
    int ambilwarna = AmbilWarna(warna);

    setfillstyle(SOLID_FILL, ambilwarna);
    bar(x1, y1, x2, y2);

    setcolor(BLACK);
    rectangle(x1, y1, x2, y2);
}

// Fungsi membuat tombol dengan teks
void tombol(int x, int y, int panjang, int lebar, const char *warna, const char *teks) {
    Kotak(x, y, x + panjang, y + lebar, warna);

    // Buat salinan string karena fungsi WinBGI tidak menerima const char*
    char teksCopy[50];
    strcpy(teksCopy, teks);

    // Menampilkan teks
    setbkcolor(AmbilWarna(warna));
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    int textWidth = textwidth(teksCopy);
    int textHeight = textheight(teksCopy);
    int textX = x + (panjang - textWidth) / 2;
    int textY = y + (lebar - textHeight) / 2;

    outtextxy(textX, textY, teksCopy);
}