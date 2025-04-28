#ifndef ULAR_H
#define ULAR_H
#include <graphics.h>
#include "mechanism.h"

typedef struct Segment {
    int x, y;
    struct Segment *next;
} Segment;

typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

// Variabel global untuk ular
extern Segment *head;
extern Segment *tail;
extern Direction arah;

void InitUlar();

void GerakUlar();

void CekTabrakan();

bool CekMakanMakanan(MakananStruct *makanan);

void GambarUlar();

#endif