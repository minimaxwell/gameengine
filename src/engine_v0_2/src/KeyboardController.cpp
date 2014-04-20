/* 
 * File:   KeyboardController.cpp
 * Author: maxwell
 * 
 * Created on 20 avril 2014, 20:03
 */

#include "KeyboardController.h"
#include "SFML/Window/Keyboard.hpp"

using namespace ge;

KeyboardController::KeyboardController() {
    configuration.y_neg       = sf::Keyboard::Z;
    configuration.y_pos       = sf::Keyboard::S;
    configuration.x_neg       = sf::Keyboard::Q;
    configuration.x_pos       = sf::Keyboard::D;
    configuration.pause       = sf::Keyboard::Escape;
    configuration.select      = sf::Keyboard::Space;
    configuration.speedUp     = sf::Keyboard::LShift;
    configuration.toggleColor = sf::Keyboard::Space;
    configuration.use         = sf::Keyboard::BackSpace;
}

KeyboardController::~KeyboardController() {
}

sf::Vector2f KeyboardController::move(float elapsed) const{
    float speed = 1.f;
    sf::Vector2f movement;
    
    if(sf::Keyboard::isKeyPressed( configuration.speedUp ) ){
        speed *= 2;
    }
    
    if(sf::Keyboard::isKeyPressed( configuration.y_neg ) ){
        movement.y = -speed * elapsed;
    }
    
    if(sf::Keyboard::isKeyPressed( configuration.y_pos ) ){
        movement.y = speed * elapsed;
    }
    
    if(sf::Keyboard::isKeyPressed( configuration.x_neg ) ){
        movement.x = -speed * elapsed;
    }
    
    if(sf::Keyboard::isKeyPressed( configuration.x_pos ) ){
        movement.x = speed * elapsed;
    }
    
    return movement;
}

bool KeyboardController::pauseEvent(const sf::Event& event) const{
    return event.key.code == configuration.pause;
}
        
bool KeyboardController::useEvent(const sf::Event& event) const{
    return event.key.code == configuration.use;
}

bool KeyboardController::selectEvent(const sf::Event& event) const{
    return event.key.code == configuration.select;
}

bool KeyboardController::toggleColor(const sf::Event& event) const{
    return event.key.code == configuration.toggleColor;
}