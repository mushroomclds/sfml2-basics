#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <ctime>
#include <sstream>

class Game
{
    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode; 
        sf::Event ev;

        std::vector<sf::RectangleShape> enemies;
        sf::RectangleShape enemy;
        unsigned points;
        float enemySpawnTimer;
        int health;
        float enemySpawnTimerMax;
        int maxEnemies;
        bool endGame;
        bool mouseHeld;

        sf::Font font; 

        sf::Text uiText;

        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;
        
 
        void initializeVariables();
        void initializeWindow();
        void initializeEnemies();
        void initializeFonts();
        void initializeText();
    public:
        Game();
        virtual ~Game();

        const bool running() const;
        void pollEvents();
        void update();
        void render();
        void updateMousePosition();

        bool getEndGame();

        void spawnEnemies();
        void updateEnemies();
        void renderEnemies(sf::RenderTarget& target);


        void renderText(sf::RenderTarget& target);
        void updateText();


};