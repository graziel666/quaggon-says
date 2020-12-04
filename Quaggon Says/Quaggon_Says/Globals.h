#pragma once

#include <Arduboy2.h>
#include <ArduboyTones.h>




Arduboy2 arduboy;
Sprites sprites;
ArduboyTones sound(arduboy.audio.enabled);

//gamestates
#define Tittle 0
#define Game 1
#define Over 2
#define Score 3

int gamestate = Tittle;




//gameFunctions

unsigned long currentTime = millis();
unsigned long endTime = currentTime;

// tiempo de retardo
constexpr unsigned long delayTime = 2000; // 250 = 1/4 second
constexpr unsigned long quaggonDelayTime = 100;


// tiempo objetivo
unsigned long targetTime = 0;

//frame
uint8_t firstQuaggonDanceFrame = 0;
uint8_t lastQuaggonDanceFrame = 0;

uint8_t quaggonFrame = 0;
uint8_t quaggonSize = 16;
uint8_t emptyQuaggon = 14;


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
#include "gameFunctions.h"
#include "secuencias.h"
#include "gamestates.h"
//#include <melodias.h>
