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
        quaggonFrame = random(0,3);  //set frame
        if (quaggonFrame == 2) quaggonFrame = 0; //resets the waddle
        drawQuaggon();
        dispLives();
        //arduboy.setCursor(0,0);
        //arduboy.print(secuencia[i]);
        arduboy.delayShort(2000);
        
        quaggonFrame = 14; //empty frame
        drawQuaggon();
        dispLives();
        arduboy.delayShort(300);
      }
      
      //up
      else if (secuencia[i] == 1){
        //draws quaggon
        quaggonFrame = random(3,6);  //set frame
        
        if (quaggonFrame == 5) quaggonFrame = 3; //resets the waddle
        drawQuaggon();
        dispLives();
        //arduboy.setCursor(0,0);
        //arduboy.print(secuencia[i]);
        arduboy.delayShort(2000);
        
        quaggonFrame = 14; //empty frame
        drawQuaggon();
        dispLives();
        arduboy.delayShort(300);
      }
      
      //right
      else if (secuencia[i] == 2){
        //draws quaggon
        quaggonFrame = random(6,10);  //set frame
        
        if (quaggonFrame == 9) quaggonFrame = 6; //resets the waddle
        drawQuaggon();
        dispLives();
        //arduboy.setCursor(0,0);
        //arduboy.print(secuencia[i]);
        arduboy.delayShort(2000);
        
        quaggonFrame = 14; //empty frame
        drawQuaggon();
        dispLives();
        arduboy.delayShort(300);
      }

      //left
      else if (secuencia[i] == 3){
        //draws quaggon
        quaggonFrame = random(10,14);  //set frame
        
        if (quaggonFrame == 13) quaggonFrame = 10; //resets the waddle
        drawQuaggon();
        dispLives();
        //arduboy.setCursor(0,0);
        //arduboy.print(secuencia[i]);
        arduboy.delayShort(2000);
        
        quaggonFrame = 14; //empty frame
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
