#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../header/basicfunction.h"
#include "../header/makanan.h"
#include "../header/pages.h"
#include "../header/ular.h"
#include "../header/stopwatch.h"
#include "../header/mechanism.h"

// prosedur untuk tampilan awal
// pembuat modul : Ridho
// dimodifikasi oleh : Salma
void tampilanAwal() {
    setbkcolor(BLACK);
    cleardevice();

    Titik(); 

    // Menampilkan logo snacksnake
    readimagefile(
        "assets/judul.bmp",
        (fullscreen_width - 300) / 2,
        10,
        (fullscreen_width - 300) / 2 + 300,
        10 + 207
    );


    int iconWidth = 25, iconHeight = 25;

    //Pojok Kiri Atas: icon music_logo
    readimagefile(
        "assets/music_logo.bmp",
        15, 20,
        10 + iconWidth, 10 + iconHeight
    );

    //Pojok Kanan Atas: icon guide_logo
    readimagefile(
        "assets/guide_logo.bmp",
        fullscreen_width - iconWidth - 10, 20,
        fullscreen_width - 10, 10 + iconHeight
    );

    // Pojok Kiri Bawah: icon snake_logo
    readimagefile(
        "assets/snake_logo.bmp",
        10, fullscreen_height - iconHeight - 30,
        10 + iconWidth, fullscreen_height - 40
    );

    // Pojok Kanan Bawah: arena_logo
    readimagefile(
        "assets/arena_logo.bmp",
        fullscreen_width - iconWidth - 20, fullscreen_height - iconHeight - 30,
        fullscreen_width - 10, fullscreen_height - 40
    );

    int tombolLebar = 200, tombolTinggi = 50;
    int posisiX = (fullscreen_width - tombolLebar) / 2;
    int posisiY = 300;

    tombol(posisiX, posisiY, tombolLebar, tombolTinggi, "GREEN", "START", 3);
    tombol(posisiX, posisiY + 80, tombolLebar, tombolTinggi, "BLUE", "LEADERBOARD", 3);
    tombol(posisiX, posisiY + 150, tombolLebar, tombolTinggi, "RED", "EXIT", 3);


    //klik start dan quit!
    while (1) {
        int x, y;
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            
            if (x >= posisiX && x <= posisiX + tombolLebar && y >= posisiY && y <= posisiY + tombolTinggi) {
                tampilanPlay();
                break;
            }
            if (x >= posisiX && x <= posisiX + tombolLebar && y >= posisiY + 150 && y <= posisiY + 150 + tombolTinggi) {
                exit(0);
            }
        }
    }
}


// prosedur untuk tampilan play sebelum ingame
// pembuat modul : Salma
// dimodifikasi oleh : -
void tampilanPlay() {
    setbkcolor(BLACK); 
    cleardevice();

    Titik(); 
    
    for (int i = 0; i < fullscreen_width + 40; i += 60) {  
        gambarAwan(i, 0);
    }

    char judul[] = "GET READY!";
    tulisan(0, 130, fullscreen_width, 0, "WHITE", judul, 6, Center);


    int tombolLebar = 150, tombolTinggi = 50;
    int posisiX = (fullscreen_width - tombolLebar) / 2;
    int posisiY = 220;

    tombol(posisiX, posisiY, tombolLebar, tombolTinggi, "GREEN", "Play", 3);

    // Event klik tombol
    while (1) {
        int x, y;
        // Jika tombol kiri mouse ditekan
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);

            gameOver = false;
            tampilanArena();
            break;
        }
    }
} 

// prosedur untuk tampilan arena ingame
// pembuat modul : Salma
// dimodifikasi oleh : -
void tampilanArena() 
{
    setbkcolor(WHITE);
    cleardevice();

    Kotak(20, 60, SCREEN_WIDTH - 20, SCREEN_HEIGHT - 20, "BLACK");

    tombol(520, 15, 100, 30, "GREEN", "PAUSE", 2);
    
    tampilkanLeaderboard();

    // Inisialisasi ular
    InitUlar();

    // Mulai loop game
    LoopGame();
}

// prosedur untuk tampilan popup saat game di pause
// pembuat modul : Ridho
// dimodifikasi oleh : -
void PopUpPause() 
{
    int popupX = SCREEN_WIDTH / 4;
    int popupY = SCREEN_HEIGHT / 4;
    int popupWidth = SCREEN_WIDTH / 2;
    int popupHeight = SCREEN_HEIGHT / 2;

    Kotak(popupX, popupY, popupX + popupWidth, popupY + popupHeight, "CYAN");
    setbkcolor(CYAN); 
    tulisan(popupX + popupWidth / 2, popupY + 50, 0, 0, "GREY", "GAME PAUSED", 5, Center);
    tombol(popupX + (popupWidth / 2) - 50, popupY + popupHeight / 2 - 20, 100, 40, "GREEN", "RESUME", 2);
    tombol(popupX + (popupWidth / 2) - 50, popupY + popupHeight / 2 + 30, 100, 40, "RED", "EXIT", 2);
    setbkcolor(CYAN);
}
