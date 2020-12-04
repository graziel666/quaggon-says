#pragma once

#include "Globals.h"




void drawQuaggon();


void updateQuaggonDance()
{
  // tiempo actual
  //unsigned long currentTime = millis();
  firstQuaggonDanceFrame = 0;
  lastQuaggonDanceFrame = 13;
  
  if(currentTime >= targetTime){
    targetTime = (currentTime + quaggonDelayTime);
    
    if(quaggonFrame < lastQuaggonDanceFrame)
      ++quaggonFrame; // quaggonFrame = quaggonFrame + 1
    else
      quaggonFrame = firstQuaggonDanceFrame;
  }
}



void drawQuaggon(){                       //simplify the animation
  //if (quaggonFrame <= 13) {
  //  quaggonFrame++;
  //}
  updateQuaggonDance();
  sprites.drawPlusMask(screenX, 30, Quaggon, quaggonFrame);

  
}

void gameOver(){

  if (lives <= 0){
    arduboy.clear();
    arduboy.setCursor(40, 10);
    arduboy.setTextSize(2);
    arduboy.print("FOO!");
    arduboy.setTextSize(1);
    arduboy.setCursor(0, HEIGHT/2);
    arduboy.print("Press A + B to Reset");
    arduboy.display();
    delay(1000);
    nivelActual = 1;
    movimientos = 2;
    score = 0;
    lives = 1;
    gameReset = false;
   
  }
  
  else if (gameReset == true) {
    arduboy.clear();
    arduboy.setCursor(0, HEIGHT/2);
    arduboy.print("Press A + B to Reset");
    arduboy.display();
    delay(1000);
    nivelActual = 1;
    movimientos = 2;
    score = 0;
    lives = 1;
    gameReset = false;
  }
  else {
    arduboy.clear();
    arduboy.setCursor(40, 10);
    arduboy.setTextSize(2);
    arduboy.println("Coo!");
    arduboy.setTextSize(1);
    arduboy.setCursor(0, HEIGHT/2);
    arduboy.println("You beat the game");
    arduboy.println("Press A & B to begin");
    arduboy.display();
  }

  while (!(arduboy.pressed(A_BUTTON | B_BUTTON))) {
    //do nothing until A + B are pressed
    arduboy.delayShort(100);
    arduboy.clear();
  }
   gamestate = Tittle;
}


void dispLives(){
  arduboy.setCursor(0, 5);
  arduboy.print("Round: ");
  arduboy.print(nivelActual);
  //arduboy.setCursor(75, 9);
  //arduboy.print("Lives: ");
  //arduboy.print(lives);
  arduboy.setCursor(75, 5);
  arduboy.print("Score: ");
  arduboy.print(score);
  arduboy.display();
}

void btnImput(){
  int i = 0;
  roundLost = false;

    do {
      arduboy.pollButtons();

      if (arduboy.pressed(UP_BUTTON | B_BUTTON)){
        arduboy.clear();
        arduboy.setCursor(35,20);
        arduboy.setTextSize(1);
        arduboy.print("please wait");
        arduboy.setTextSize(1);
        arduboy.setCursor(15,30);
        arduboy.print("Quaggons resseting");
        arduboy.setCursor(45,40);
        arduboy.print("the game");
        arduboy.display();
        arduboy.delayShort(1000);
        gameReset = true;
        gameOver();
      }

       if (arduboy.justReleased(DOWN_BUTTON)){
        //draws quaggon
                          sound.tone(NOTE_C3,75);
        
        
        
        quaggonFrame = random(0,3);  //set frame
        
        if (quaggonFrame == 2) quaggonFrame = 0; //resets the waddle
        drawQuaggon();
        dispLives();
        arduboy.delayShort(500);
        
        quaggonFrame = 14; //empty frame
        drawQuaggon();
        if (secuencia[i] == 0){
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
                        sound.tone(NOTE_D3,75);
        
        
        
        quaggonFrame = random(3,6);  //set frame
        
        if (quaggonFrame == 5) quaggonFrame = 3; //resets the waddle
        drawQuaggon();
        dispLives();
        arduboy.delayShort(500);
        
        quaggonFrame = 14; //empty frame
        drawQuaggon();
        if (secuencia[i] == 1){
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
                        sound.tone(NOTE_E3,75);
        
        
        
        quaggonFrame = random(6,10);  //set frame
        
        if (quaggonFrame == 9) quaggonFrame = 6; //resets the waddle
        drawQuaggon();
        dispLives();
        arduboy.delayShort(500);
        
        quaggonFrame = 14; //empty frame
        drawQuaggon();
        if (secuencia[i] == 2){
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
                        sound.tone(NOTE_F3,75);
        
        
        
        quaggonFrame = random(10,14);  //set frame
        
        if (quaggonFrame == 13) quaggonFrame = 10; //resets the waddle
        drawQuaggon();
        dispLives();
        arduboy.delayShort(500);
        
        quaggonFrame = 14; //empty frame
        drawQuaggon();
        if (secuencia[i] == 3){
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
    } else {
      arduboy.clear();
      arduboy.setTextSize(2);
      arduboy.setCursor(40,15);
      arduboy.print("COO!");
      arduboy.setTextSize(1);
      arduboy.setCursor(25,40);
      arduboy.print("Good JoOoOoB");
      arduboy.display();
      //dispLives();
      arduboy.delayShort(1500);
      arduboy.clear();
    }
}
