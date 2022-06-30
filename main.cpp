#include <iostream>
#include "game.h"


/*
    Game constructor -> Initialize functions : window, enemies, etc.
    while loop -> game.runnin() : check if game is still running 
        -> game.update() : check for window closed
        -> game.render() : clear window then display new one 
*/


int main(){

    std::srand(static_cast<unsigned>(time(NULL)));

    Game game;
 
    //game loop
    while(game.running() && !game.getEndGame()){ 
 
        game.update();
        game.render();  
    }
  
} 