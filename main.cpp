#include <iostream>
#include "game.h"

int main(){
 
    Game game;
 
    //game loop
    while(game.running()){ 
 
        game.update();
        game.render();  
    }
  
}