 #pragma once

#include "Globals.h"





void G_Tittle() {
  arduboy.setCursor(0, 0);
  //arduboy.print("Tittle");
  sprites.drawOverwrite(0, 0, mainSays, 0);

  if (arduboy.pressed(A_BUTTON + B_BUTTON)) {

    nivelActual = 1;
    movimientos = 2;
    score = 0;
    lives = 1;
    gameReset = false;

    arduboy.initRandomSeed();
    
    gamestate = Game;
  }
}

void G_Game() {
  arduboy.setCursor(0, 0);
  arduboy.print("Game");
  arduboy.clear();
  //drawQuaggon();          //just for testing

  startGame();
  arduboy.display();
  

  if (arduboy.justPressed(A_BUTTON)) {
    gamestate = Over;
  }
}

void G_Over() {
  arduboy.setCursor(0, 0);
  arduboy.print("Over");

  if (arduboy.justPressed(A_BUTTON)) {
    gamestate = Score;
  }
}

void H_Score() {
  arduboy.setCursor(0, 0);
  arduboy.print("Score");

  if (arduboy.justPressed(A_BUTTON)) {
    gamestate = Tittle;
  }
}

void gameloop() {
  switch (gamestate) {

    case Tittle:
      G_Tittle();
      break;

    case Game:
      G_Game();
      break;

    case Over:
      G_Over();
      break;

    case Score:
      H_Score();
      break;

  }
}
