#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../header/mainhead.h"
#include "../header/makanan.h"
#include "../header/pages.h"
#include "../header/ular.h"
#include "../header/stopwatch.h"

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



void LoopGame() 
{
    int activePage = 0; // Buffer untuk double buffering
    double lastUpdate = clock(); // Waktu terakhir frame diperbarui
    double lastMoveTime = clock(); // Waktu terakhir ular bergerak
    double frameDelay = 1000.0 / 60.0; // 60 FPS
    double snakeSpeed = 150.0; // Kecepatan ular dalam ms (lebih besar = lebih lambat)

    MakananStruct makanan;
    GenerateRandomPosition(&makanan.x, &makanan.y);
    makanan.type = GeneratemakananType();
    makanan.spawnTime = clock(); // Simpan waktu makanan muncul

    startStopwatch(); // Mulai stopwatch

    // **Loop utama game**
    while (1) {
        double currentTime = clock();

        // **Input pemain**
        if (kbhit()) {
            char key = getch();
            if (key == 72 && arah != DOWN) arah = UP;    
            if (key == 80 && arah != UP) arah = DOWN;    
            if (key == 75 && arah != RIGHT) arah = LEFT; 
            if (key == 77 && arah != LEFT) arah = RIGHT; 
        }

        // **Batasi FPS (Frame Per Second)**
        if (currentTime - lastUpdate < frameDelay) continue;
        lastUpdate = currentTime;

        // **Gerakkan ular berdasarkan kecepatan**
        if (currentTime - lastMoveTime >= snakeSpeed) {
            GerakUlar();
            lastMoveTime = currentTime;
        }

        // **Hapus makanan poison setelah 5 detik**
        if (makanan.type == POISON && (currentTime - makanan.spawnTime) / CLOCKS_PER_SEC > 5) {
            printf("Makanan poison menghilang!\n");
            GenerateRandomPosition(&makanan.x, &makanan.y);
            makanan.type = GeneratemakananType();
            makanan.spawnTime = clock(); // Reset waktu spawn
        }

        // **Double Buffering**
        activePage = 1 - activePage;
        setactivepage(activePage);
        cleardevice(); // Bersihkan layar sebelum menggambar ulang elemen game

        // **Gambar elemen game**
        Kotak(20, 60, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, "WHITE");
        tombol(520, 15, 100, 30, "DARKGRAY", "PAUSE", 2);
        setbkcolor(CYAN);

        // **Gambar elemen game lainnya**
        Tampilkanscore();
        Stopwatch();
        CekTabrakan();
        Makanan(makanan);
        GambarUlar();

        // **Cek jika ular makan makanan**
        if (CekMakanMakanan(&makanan)) {
            GenerateRandomPosition(&makanan.x, &makanan.y);  
            makanan.type = GeneratemakananType();
            makanan.spawnTime = clock(); // Reset waktu spawn makanan
            
            printf("Score sekarang: %d\n", score);
        }

        // **Tampilkan buffer aktif**
        setvisualpage(activePage);
    }
}
