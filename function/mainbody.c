#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/mainhead.h"
#include "../header/pages.h"
#include "../header/makanan.h"
#include "../header/ular.h"
#include "../header/stopwatch.h"

bool paused = false;

// Fungsi untuk mengonversi warna dari string ke nilai integer
int AmbilWarna(CSTR color) 
{
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

// Fungsi membuat teks
void tulisan(int x, int y, int lebar, int tinggi, CSTR warna, CSTR teks, int ukuran, typePenempatanTulisan penempatan) 
{
    setcolor(AmbilWarna(warna));
    settextstyle(BOLD_FONT, HORIZ_DIR, ukuran);

    char teksCopy[100];
    strcpy(teksCopy, teks);

    int textX, textY, textWidth, textHeight;

    if (penempatan == Center) {
        textWidth = textwidth(teksCopy);
        textHeight = textheight(teksCopy);
        textX = x + (lebar - textWidth) / 2;
        textY = y + (tinggi - textHeight) / 2;

    } else if (penempatan == Random) {
        textX = x;
        textY = y;
    }

    outtextxy(textX, textY, teksCopy);
}

// Fungsi menggambar kotak berisi warna
void Kotak(int x1, int y1, int x2, int y2, CSTR warna) 
{
    int ambilwarna = AmbilWarna(warna);

    setfillstyle(SOLID_FILL, ambilwarna);
    bar(x1, y1, x2, y2);

    setcolor(ambilwarna);
    rectangle(x1, y1, x2, y2);
}

// Fungsi membuat tombol dengan teks (lebih praktis)
void tombol(int x, int y, int panjang, int lebar, CSTR warna, CSTR teks, int ukuranTeks) 
{
    Kotak(x, y, x + panjang, y + lebar, warna);
    setbkcolor(AmbilWarna(warna));
    tulisan(x, y, panjang, lebar, "WHITE", teks, ukuranTeks, Center);
}

//Fungsi Loop utama game
void LoopGame() {
    int makananX, makananY;
    GenerateRandomPosition(&makananX, &makananY);
    startStopwatch();

    while (1) {
        if (kbhit()) { // Cek jika ada input keyboard
            char key = getch();
            
            // Cek apakah tombol yang ditekan adalah tombol arah atau pause
            if (key == 72 && arah != DOWN) arah = UP;    // Panah atas
            else if (key == 80 && arah != UP) arah = DOWN;    // Panah bawah
            else if (key == 75 && arah != RIGHT) arah = LEFT; // Panah kiri
            else if (key == 77 && arah != LEFT) arah = RIGHT; // Panah kanan
            else if (key == 'p' || key == 'P') { 
                paused = !paused; // Toggle pause
                while (kbhit()) getch(); // Buang input yang tersisa di buffer
            }
        }

        if (!paused) { 
            setbkcolor(CYAN);
            cleardevice(); 

            Kotak(20, 60, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, "WHITE");
            tombol(520, 15, 100, 30, "DARKGRAY", "PAUSE", 2);
            setbkcolor(CYAN);

            Stopwatch();
            Makanan(makananX, makananY); 

            GerakUlar();
            CekTabrakan(); 
            CekMakanMakanan(&makananX, &makananY); 

            GambarUlar(); 
            TampilkanSkor(); 
        } else {
            
            // posisi popup menu
            int popupX = SCREEN_WIDTH / 4;
            int popupY = SCREEN_HEIGHT / 4;
            int popupWidth = SCREEN_WIDTH / 2;
            int popupHeight = SCREEN_HEIGHT / 2;

            Kotak(popupX, popupY, popupX + popupWidth, popupY + popupHeight, "CYAN");
            tulisan(popupX + popupWidth / 2, popupY + 50, 0, 0, "GREY", "GAME PAUSED", 5, Center);
            tombol(popupX + (popupWidth / 2) - 50, popupY + popupHeight / 2 - 20, 100, 40, "GREEN", "RESUME", 2);
            tombol(popupX + (popupWidth / 2) - 50, popupY + popupHeight / 2 + 30, 100, 40, "RED", "EXIT", 2);


            while (paused) {
                if (kbhit()) {
                    char key = getch();
                    if (key == 'r' || key == 'R') {
                        paused = false;
                    } else if (key == 't' || key == 'T') {
                        exit(0);
                    }
                }
            }
        }

        delay(100); // Beri jeda agar pergerakan lebih halus
    }
}

