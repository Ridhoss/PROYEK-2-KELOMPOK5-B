#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <graphics.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define BORDER_SIZE 20
#define CELL_SIZE 20
#define MAX_LENGTH ((SCREEN_WIDTH - 2 * BORDER_SIZE) / CELL_SIZE) * ((SCREEN_HEIGHT - 2 * BORDER_SIZE) / CELL_SIZE)

extern time_t start_time;
extern time_t paused_time;
extern int elapsed_time;
extern int total_paused_duration;
extern bool stopwatch_running;

void Tampilkanscore();

void Stopwatch();

void startStopwatch();


#endif   
