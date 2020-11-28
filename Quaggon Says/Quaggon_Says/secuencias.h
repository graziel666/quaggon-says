 #pragma once

#include "Globals.h"






void startGame(){
  nivelActual = 1;
  while (nivelActual <= nivelMax){
    for (int i = 0; i <= nivelActual; i++){
      secuencia[i] = random(4)%100;

      //down
      if (secuencia[i] == 0){
        //draws quaggon
        quaggonFrame = random(0,4);  //set frame
        if (quaggonFrame == 3) quaggonFrame = 0; //resets the waddle
        drawQuaggon();
        dispLives();
        //arduboy.setCursor(0,0);
        //arduboy.print(secuencia[i]);
        arduboy.delayShort(2000);
        
        quaggonFrame = 16; //empty frame
        drawQuaggon();
        dispLives();
        arduboy.delayShort(300);
      }
      
      //up
      else if (secuencia[i] == 1){
        //draws quaggon
        quaggonFrame = random(4,8);  //set frame
        
        if (quaggonFrame == 7) quaggonFrame = 4; //resets the waddle
        drawQuaggon();
        dispLives();
        //arduboy.setCursor(0,0);
        //arduboy.print(secuencia[i]);
        arduboy.delayShort(2000);
        
        quaggonFrame = 16; //empty frame
        drawQuaggon();
        dispLives();
        arduboy.delayShort(300);
      }
      
      //right
      else if (secuencia[i] == 2){
        //draws quaggon
        quaggonFrame = random(8,12);  //set frame
        
        if (quaggonFrame == 11) quaggonFrame = 8; //resets the waddle
        drawQuaggon();
        dispLives();
        //arduboy.setCursor(0,0);
        //arduboy.print(secuencia[i]);
        arduboy.delayShort(2000);
        
        quaggonFrame = 16; //empty frame
        drawQuaggon();
        dispLives();
        arduboy.delayShort(300);
      }

      //left
      else if (secuencia[i] == 3){
        //draws quaggon
        quaggonFrame = random(12,16);  //set frame
        
        if (quaggonFrame == 15) quaggonFrame = 12; //resets the waddle
        drawQuaggon();
        dispLives();
        //arduboy.setCursor(0,0);
        //arduboy.print(secuencia[i]);
        arduboy.delayShort(2000);
        
        quaggonFrame = 16; //empty frame
        drawQuaggon();
        dispLives();
        arduboy.delayShort(300);
      }
      
    }

    for (int j = 3; j > 0; j --){
      arduboy.clear();
      arduboy.setTextSize(1);
      arduboy.setCursor(20,20);
      arduboy.print("Quaggon says");
      arduboy.setTextSize(1);
      arduboy.setCursor(20,30);
      arduboy.print("get Ready!");
      arduboy.setCursor(63,40);
      arduboy.setTextSize(1);
      arduboy.print(j);
      arduboy.setTextSize(1);
      dispLives();
      arduboy.delayShort(500);
    }

    arduboy.clear();
    arduboy.setTextSize(2);
    arduboy.setCursor(40, 25);
    arduboy.print("COO!");
    arduboy.display();
    arduboy.delayShort(1000);
    arduboy.clear();
    arduboy.setTextSize(1);
    dispLives();


    btnImput();
    nivelActual ++;
    movimientos ++;

    if (lives <= 0) {
      gameOver();
    }
    
  }
  
}
