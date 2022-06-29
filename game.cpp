
#include "game.h"

Game::Game(){
    this->initializeVariables();
    this->initializeWindow();
}
Game::~Game(){
    delete this->window;
}
void Game::update(){
   this->pollEvents();
}
void Game::pollEvents(){
     //event polling
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    } 
}
void Game::render(){
    this->window->clear(sf::Color::Blue);
    this->window->display();
}
const bool Game::running() const{

    return this->window->isOpen();
}

void Game::initializeVariables(){

    this->window = nullptr;

}

void Game::initializeWindow(){
    
    this->videoMode.width = 800;
    this->videoMode.height = 600;
  

    this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close 
    | sf::Style::Resize);

}