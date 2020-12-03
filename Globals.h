#pragma once

#include <Arduboy2.h>

Arduboy2 arduboy;
Sprites sprites;

//gamestates
#define Tittle 0
#define Game 1
#define Over 2
#define Score 3

int gamestate = Tittle;


//screenThings
//frame
uint8_t quaggonFrame = 0;
uint8_t quaggonSize = 16;


//x e y for half screen (not anymore)
int screenX = WIDTH/2 - quaggonSize;
int screenY = HEIGHT/2 - quaggonSize;


//secuencias
//lvl
int nivelActual = 1; //actual level
int movimientos = 1; //moves per level
int vel = 500; //game speed
const int nivelMax = 50; //max level (if someone get here, is getting a cookie)

 //secuencia
int secuencia[nivelMax]; //actual sequence
int secuenciaUser[nivelMax]; //user sequence

bool roundLost;      
bool gameReset; 
int lives = 1;




//score
int score = 0;

#include "bitmaps.h"
#include "screenThings.h"
#include "secuencias.h"
#include "gamestates.h"
//#include <melodias.h>
