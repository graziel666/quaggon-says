#pragma once

#include "Globals.h"









void drawQuaggon(){                       //simplify the animation
  if (quaggonFrame <= 15) {
    quaggonFrame++;
  }
  
  sprites.drawPlusMask(screenX, screenY, Quaggon, quaggonFrame);

  //arduboy.display();
  
}

void gameOver(){

  if (lives <= 0){
    arduboy.clear();
    arduboy.setCursor(0, 0);
    arduboy.print("Press A + B to Reset");
    arduboy.display();
    delay(1000);
   
  }
  
  else if (gameReset = true) {
    arduboy.clear();
    arduboy.setCursor(0, 0);
    arduboy.print("Press A + B to Reset");
    arduboy.display();
    delay(1000);
    gameReset = false;
  }
  else {
    arduboy.clear();
    arduboy.setCursor(WIDTH/2, 0);
    arduboy.setTextSize(2);
    arduboy.println("Coo!");
    arduboy.setTextSize(1);
    arduboy.println("You beat the game");
    arduboy.println("Press A & B to begin");
    arduboy.display();
  }

  while (!(arduboy.pressed(A_BUTTON + B_BUTTON))) {
    //do nothing until A + B are pressed
    delay(100);
  }
   gamestate = Tittle;
}


void dispLives(){
  arduboy.setCursor(75, 0);
  arduboy.print("Round: ");
  arduboy.print(nivelActual);
  //arduboy.setCursor(75, 9);
  //arduboy.print("Lives: ");
  //arduboy.print(lives);
  arduboy.setCursor(75, 55);
  arduboy.print("Score: ");
  arduboy.print(score);
  arduboy.display();
}

void btnImput(){
  int i = 0;
  roundLost = false;

    do {
      arduboy.pollButtons();

      if (arduboy.pressed(UP_BUTTON + B_BUTTON)){
        arduboy.clear();
        arduboy.setCursor(WIDTH/2,HEIGHT/2);
        arduboy.setTextSize(2);
        arduboy.println("please wait");
        arduboy.setTextSize(1);
        arduboy.println("Quaggons resseting the game");
        arduboy.display();
        arduboy.delayShort(500);
        gameReset = true;
        gameOver();
      }

       if (arduboy.justReleased(DOWN_BUTTON)){
        //draws quaggon
        quaggonFrame = random(0,4);  //set frame
        
        if (quaggonFrame == 3) quaggonFrame = 0; //resets the waddle
        drawQuaggon();
        dispLives();
        arduboy.delayShort(500);
        
        quaggonFrame = 16; //empty frame
        drawQuaggon();
        if (secuenciaUser[i] == 0){
          i++;
          score++;
        }
        else {
          lives --;
          roundLost = true;
          break;
        }
        dispLives();
      }

      if (arduboy.justReleased(UP_BUTTON)){
        //draws quaggon
        quaggonFrame = random(4,8);  //set frame
        
        if (quaggonFrame == 7) quaggonFrame = 4; //resets the waddle
        drawQuaggon();
        dispLives();
        arduboy.delayShort(500);
        
        quaggonFrame = 16; //empty frame
        drawQuaggon();
        if (secuenciaUser[i] == 1){
          i++;
          score++;
        }
        else {
          lives --;
          roundLost = true;
          break;
        }
        dispLives();
      }

      if (arduboy.justReleased(RIGHT_BUTTON)){
        //draws quaggon
        quaggonFrame = random(8,12);  //set frame
        
        if (quaggonFrame == 11) quaggonFrame = 8; //resets the waddle
        drawQuaggon();
        dispLives();
        arduboy.delayShort(500);
        
        quaggonFrame = 16; //empty frame
        drawQuaggon();
        if (secuenciaUser[i] == 2){
          i++;
          score++;
        }
        else {
          lives --;
          roundLost = true;
          break;
        }
        dispLives();
      }

      if (arduboy.justReleased(LEFT_BUTTON)){
        //draws quaggon
        quaggonFrame = random(12,16);  //set frame
        
        if (quaggonFrame == 15) quaggonFrame = 12; //resets the waddle
        drawQuaggon();
        dispLives();
        arduboy.delayShort(500);
        
        quaggonFrame = 16; //empty frame
        drawQuaggon();
        if (secuenciaUser[i] == 3){
          i++;
          score++;
        }
        else {
          lives --;
          roundLost = true;
          break;
        }
        dispLives();
      }

    } while (i < movimientos);

    if (roundLost){
      gameReset = true;
      nivelActual --;
      movimientos--;
    }
}
