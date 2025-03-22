#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../header/pages.h"
#include "../header/mainhead.h"
#include "../header/makanan.h"
#include "../header/ular.h"
#include "../header/stopwatch.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// Fungsi untuk menggambar titik-titik putih secara acak di layar
void Titik() {
    int jml = 20;  
    int ukuran = 4;   

    srand(time(NULL)); // Seed untuk posisi acak

    for (int i = 0; i < jml; i++) {
        int x = rand() % getmaxx(); // Acak posisi x
        int y = rand() % getmaxy(); // Acak posisi y

        setfillstyle(SOLID_FILL, AmbilWarna("WHITE"));
        fillellipse(x, y, ukuran / 2, ukuran / 2); 
    }
}

void tampilanAwal() {
    setbkcolor(BLACK);
    cleardevice();

    Titik(); 

    char judul[] = "SNACK SNAKE B5";
    tulisan(0, 120, SCREEN_WIDTH, 0, "WHITE", judul, 6, Center);

    int tombolLebar = 200, tombolTinggi = 50;
    int posisiX = (SCREEN_WIDTH - tombolLebar) / 2;
    int posisiY = 190;

    tombol(posisiX, posisiY, tombolLebar, tombolTinggi, "GREEN", "START", 3);
    tombol(posisiX, posisiY + 80, tombolLebar, tombolTinggi, "RED", "EXIT", 3);

    //klik start dan quit!
    while (1) {
        int x, y;
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
            if (x >= posisiX && x <= posisiX + tombolLebar && y >= posisiY && y <= posisiY + tombolTinggi) {
                tampilanPlay();
                break;
            }
            if (x >= posisiX && x <= posisiX + tombolLebar && y >= posisiY + 80 && y <= posisiY + 80 + tombolTinggi) {
                exit(0);
            }
        }
    }
}

// Fungsi untuk menggambar awan
void gambarAwan(int x, int y) {
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, 30, 20);
    fillellipse(x + 20, y + 10, 30, 20);
    fillellipse(x - 20, y + 10, 30, 20);
    fillellipse(x + 40, y, 30, 20);
    fillellipse(x - 40, y, 30, 20);
}

void tampilanPlay() {
    setbkcolor(BLACK); 
    cleardevice();

    Titik(); 

    
    for (int i = 0; i < SCREEN_WIDTH + 40; i += 60) {  
        gambarAwan(i, 0);
    }
   
    char judul[] = "GET READY!";
    tulisan(0, 130, SCREEN_WIDTH, 0, "WHITE", judul, 6, Center);


    int tombolLebar = 150, tombolTinggi = 50;
    int posisiX = (SCREEN_WIDTH - tombolLebar) / 2;
    int posisiY = 220;

    tombol(posisiX, posisiY, tombolLebar, tombolTinggi, "GREEN", "Play", 3);

    // Event klik tombol
    while (1) {
        int x, y;
        // Jika tombol kiri mouse ditekan
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Memulai permainan setelah tombol diklik
            stopwatch_running = true; 
            startStopwatch();
            gameOver = false;
            tampilanArena();
            break;
        }
    }
} 

void tampilanArena() {
    setbkcolor(CYAN);
    cleardevice();

    Kotak(20, 60, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, "WHITE");

    tombol(520, 15, 100, 30, "DARKGRAY", "PAUSE", 2);

    // Inisialisasi ular
    InitUlar();

    // Mulai loop game
    LoopGame();

    // char score[100] = "Score: 0";
    // tulisan(20, 20, 0, 0, "WHITE", score, 2, Random);

    // char stopwatch[100] = "00:20:00";
    // tulisan(0, 30, SCREEN_WIDTH, 0, "WHITE", stopwatch, 2, Center);
}