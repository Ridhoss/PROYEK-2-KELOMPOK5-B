#ifndef ULAR_H
#define ULAR_H
#include <graphics.h>
#include "mechanism.h"

typedef struct {int x, y;} Segment;
typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

// Variabel global untuk ular
extern Segment ular[MAX_LENGTH];
extern int panjangUlar;
extern Direction arah;

void InitUlar();

void GerakUlar();

void CekTabrakan();

bool CekMakanMakanan(MakananStruct *makanan);

void GambarUlar();

#endif