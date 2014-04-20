/* 
 * File:   Game.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 17:43
 */

#include "Game.h"
#include "KeyboardController.h"
#include "JoystickController.h"
#include <iostream>
using namespace ge;

GameParameters Game::parameters = { 1440, 900, "The game v 0.2 ", 9 };

Game::Game( Level * level ) : m_level(level) {
}


Game::~Game() {
    delete m_level;
    delete m_player;
    delete m_window;
}

void Game::render() const{
    
    m_window->clear();
    m_window->draw( *( m_level->m_background ) );
    m_window->draw( *( m_player->shape() ) );
    m_window->display();
}
        
void Game::update(float elapsed){
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        if( event.type == m_player->movementController()->handledEvent() ){
            if(m_player->movementController()->toggleColor( event ))
                    m_player->toggleColor();
        }
        
        if (event.type == sf::Event::Closed)
            m_window->close();
    }
    
    m_player->update(elapsed);
    m_level->m_background->update(elapsed);
    
}

void Game::launch(){
    
    m_window = new sf::RenderWindow(sf::VideoMode( Game::parameters.gameWidth , Game::parameters.gameHeight ), Game::parameters.gameTitle);
    
    m_window->setVerticalSyncEnabled(true);
    
        std::cout << "Scanning for external controllers..." << std::endl;
    
    unsigned int joystick = ge::NO_JOYSTICK ;
    for( unsigned int i = 0 ; i < 8 ; i++ ){
        if( sf::Joystick::isConnected( i ) ){
            std::cout << "Found controller, id " << i << std::endl;
            joystick = i;
        }
    }
    
    MovementController * controller;
    
    if( joystick != ge::NO_JOYSTICK ){
        std::cout << "Joystick " << joystick << " is taken as input device." << std::endl;
        JoystickController * c = new JoystickController( joystick );
        c->configuration = ge::XBOX360_CONTROLLER_CONFIGURATION;
        controller = c;
    }else{
        std::cout << "No external controller detected, using keyboard as input." << std::endl;
        controller = new KeyboardController();
    }
    
    m_player = new Player( m_level->playerColorPoll() , sf::Vector2f( Game::parameters.gameWidth / 2 , Game::parameters.gameHeight / 2 ) , 200.f , controller);
    m_player->shape( new sf::CircleShape( 10 ) );
    
    m_playing = true;
    
    loop();
}

void Game::loop(){
    
    
    sf::Clock clock;
    while( m_window->isOpen() && m_playing ){
        update(clock.restart().asSeconds());
        render();
    }
    
}