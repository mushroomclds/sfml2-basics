#include "game.h"
#include <iostream>

Game::Game(){
    this->initializeVariables();
    this->initializeWindow();
    this->initializeEnemies();
}
Game::~Game(){
    delete this->window;
}
void Game::update(){
   this->pollEvents();

    std::cout << "mouse pos: " << sf::Mouse::getPosition(*this->window).x << " "
     << sf::Mouse::getPosition(*this->window).y << std::endl;

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
    
    this->window->draw(this->enemy);

    this->window->display();

}
const bool Game::running() const{

    return this->window->isOpen();
}
////////////////////////////////////////////////////////////////////////////////////////////////

void Game::initializeEnemies(){

    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(0.5f, 0.5f);
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);

}



////////////////////////////////////////////////////////////////////////////////////////////////

void Game::initializeVariables(){

    this->window = nullptr;

}

void Game::initializeWindow(){
    
    this->videoMode.width = 800;
    this->videoMode.height = 600;
  

    this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close 
    | sf::Style::Resize);

    this->window->setFramerateLimit(144);

}