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

int score = 0;
time_t start_time;
int elapsed_time = 0;

//Fungsi Score
void TampilkanSkor() {
    char scoreText[20];
    sprintf(scoreText, "Score: %d", score);
    tulisan(30, 20, 100, 30, "WHITE", scoreText, 2, Center);
} 

//stopwatch
void Stopwatch() {
    elapsed_time = time(NULL) - start_time;
    int minutes = elapsed_time / 60;
    int seconds = elapsed_time % 60;

    char time_str[10];
    sprintf(time_str, "%02d:%02d", minutes, seconds);
    
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

    int text_width = textwidth(time_str);
    int x_center = (SCREEN_WIDTH / 2) - (text_width / 2); // Tengah atas

    outtextxy(x_center, 20, time_str);
}

//Fungsi untuk memulai stopwatch
void startStopwatch() {
    start_time = time(NULL);
}