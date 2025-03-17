#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../header/stopwatch.h"
#include "../header/mainhead.h"
#include "../header/pages.h"
#include "../header/makanan.h"
#include "../header/ular.h"

time_t start_time;
time_t paused_time = 0;
int elapsed_time = 0;
int total_paused_duration = 0;
bool stopwatch_running = false;

//Fungsi Score
void Tampilkanscore() {
    // Konversi score ke string
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);

    // Set warna teks dan latar belakang agar terlihat jelas
    setcolor(WHITE);
    setbkcolor(CYAN);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

    // Tampilkan teks score di layar
    outtextxy(30, 20, scoreText);
}

//stopwatch
void Stopwatch() {
    if (stopwatch_running && !paused) {
        elapsed_time = time(NULL) - start_time - total_paused_duration;
    }

    int minutes = elapsed_time / 60;
    int seconds = elapsed_time % 60;

    char time_str[10];
    sprintf(time_str, "%02d:%02d", minutes, seconds);

    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

    int text_width = textwidth(time_str);
    int x_center = (SCREEN_WIDTH / 2) - (text_width / 2);

    outtextxy(x_center, 20, time_str);
}


//Fungsi untuk memulai stopwatch
void startStopwatch() {
    start_time = time(NULL);
}