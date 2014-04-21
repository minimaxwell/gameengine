/* 
 * File:   JoystickController.cpp
 * Author: maxwell
 * 
 * Created on 20 avril 2014, 21:07
 */

#include "JoystickController.h"
#include "Game.h"

using namespace ge;

JoystickController::JoystickController( unsigned int joystick ) : threshold(10.f), m_joystick(joystick) {
}

JoystickController::~JoystickController() {
}

sf::Vector2f JoystickController::move(unsigned long long elapsed) const{
    sf::Vector2f movement;
        
    double elapsedSeconds = elapsed / 1000000.0;
    
    double x,y,speed;
    
    x = sf::Joystick::getAxisPosition( m_joystick , configuration.x_axis );
    y = sf::Joystick::getAxisPosition( m_joystick , configuration.y_axis );
    speed = 100.f + sf::Joystick::getAxisPosition( m_joystick , configuration.speedUp );
        
    x = ( x < -threshold || x > threshold ) ? x / 100 : 0.f ;
    y = ( y < -threshold || y > threshold ) ? y / 100 : 0.f ;
    
    speed = 1.f + ( ( speed > ( threshold - 100.f ) ) ? speed / 100.f : 0.f );
        
    movement.x = x * speed *  elapsedSeconds;
    movement.y = y * speed *  elapsedSeconds;
    
    return movement;
}

bool JoystickController::pauseEvent(const sf::Event& event) const{
    return event.joystickButton.button == configuration.pause;
}
        
bool JoystickController::useEvent(const sf::Event& event) const{
    return event.joystickButton.button == configuration.use;
}

bool JoystickController::selectEvent(const sf::Event& event) const{
    return event.joystickButton.button == configuration.select;
}

bool JoystickController::toggleColor(const sf::Event& event) const{
    return event.joystickButton.button == configuration.toggleColor;
}