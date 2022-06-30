#include "game.h"
#include <iostream>


Game::Game(){
    this->initializeVariables();
    this->initializeWindow();
    this->initializeFonts(); 
    this->initializeEnemies();
    this->initializeText();
}
Game::~Game(){
    delete this->window;
}
///////////////////////////////////////////////////////////////////////////////////////////
void Game::update(){ 
    this->pollEvents(); //this checks if window wants to be closed 
    if (!this->endGame){
        this->updateMousePosition(); //updates mouse postion and prints to terminal
        this->updateEnemies(); // creates enemies 
        this->updateText();
    }
    if(this->health <= 0){
        this->endGame = true;
    }
    
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
    
    this->renderEnemies(*this->window); //enemies will be on top of everything, to be seen on window 

    this->renderText(*this->window); 

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
void Game::updateMousePosition(){
    /*
        mousePosWindow is of type vector2i, this gets x and y values from getPosition
        getposition wants reference to relative window. deference pointer this->window
    */
    this->mousePosWindow = sf::Mouse::getPosition(*this->window); 
    // std::cout << mousePosWindow.x << " " << mousePosWindow.y << std::endl;
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow); 

}
void Game::spawnEnemies(){
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
    );

    this->enemy.setFillColor(sf::Color::Green);
    this->enemies.push_back(this->enemy); 
}
void Game::updateEnemies(){
    if(this->enemies.size() < this->maxEnemies){
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax){
            this->spawnEnemies();  
            this->enemySpawnTimer = 0.f;
        }
        else{
            this->enemySpawnTimer += 1.f;
        }
    }
    for(int i = 0; i < enemies.size(); i++){
        bool deleted = false; 
        this->enemies[i].move(0.f, 3.f);
        if(this->enemies[i].getPosition().y > this->window->getSize().y){
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1;
            std::cout << "Health :" << this->health << std::endl;

        }
               
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        
        if(this->mouseHeld == false){
            this->mouseHeld = true;
            bool deleted = false;
            for(size_t i = 0; i < this->enemies.size() && deleted == false; i++){
                if(this->enemies[i].getGlobalBounds().contains(this->mousePosView)){
                    deleted = true;
                    this->points += 1;
                    std::cout << "Points :" << this->points << std::endl;
                    this->enemies.erase(this->enemies.begin() + i);
                }
            }
        }
    }
    else{
        this->mouseHeld = false;
    }
}

void Game::renderEnemies(sf::RenderTarget& target){
    for(auto &e : this->enemies){
        target.draw(e);
    }
}

bool Game::getEndGame(){
    return this->endGame;
}
////////////////////////////////////////////////////////////////////////////////////////////////

void Game::initializeFonts(){

    this->font.loadFromFile("fonts/Dosis-Light.ttf");

}
void Game::initializeText(){
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(sf::Color::Yellow);
    this->uiText.setString("THiS");
}

void Game::updateText(){

    std::stringstream ss;
    ss << "Points: " << this->points << "\n" << "Health :" << this->health;

    this->uiText.setString(ss.str());
}
void Game::renderText(sf::RenderTarget& target){

    target.draw(this->uiText);

}

////////////////////////////////////////////////////////////////////////////////////////////////

void Game::initializeVariables(){

    this->window = nullptr;
    this->health = 20;
    this->endGame = false;
    this->points = 0;
    this->enemySpawnTimerMax = 15.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10; 
    this->mouseHeld = false;

}

void Game::initializeWindow(){
    
    this->videoMode.width = 800;
    this->videoMode.height = 600;
  

    this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close 
    | sf::Style::Resize);

    this->window->setFramerateLimit(144);

}