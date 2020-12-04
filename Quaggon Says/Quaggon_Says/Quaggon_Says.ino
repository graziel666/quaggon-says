/*this is entirely bassed on Arduboy Says from Slade1972
 *i'm not trying to use his work, this is just a way to learn, trying to modify it to my likes
 *and adding the almighty Quaggon!
 */

#include "Globals.h"

/*//music
int melodia[ ] = {262, 196, 196, 220, 196, 0, 247, 262};
int duracionNotas[] = {4, 8, 8, 4, 4, 4, 4, 4};*/





void setup(){
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.display();
  arduboy.clear();
  arduboy.audio.begin();
  
}

void loop() {
   if(!(arduboy.nextFrame())) {
    return;
  }
  arduboy.pollButtons();
  

  arduboy.clear();  
  gameloop();
  arduboy.display();
 

}
