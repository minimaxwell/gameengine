/* 
 * File:   NonPlayer.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 17:49
 */

#include "NonPlayer.h"
#include <iostream>

using namespace ge;

NonPlayer::NonPlayer( sf::Shape * shape,
                      eColor baseColor,
                      int fuzz,
                      Movement * movement,
                      unsigned long long lifetime,
                      const sf::Vector2f& initPosition ) : m_shape( shape ), m_color( ge::Color::createColor( baseColor, fuzz ) , baseColor ), m_movement( movement ), m_lifetime( lifetime ), m_currTime(0), m_initPosition(initPosition) {
    m_shape->setPosition( m_initPosition );
}


NonPlayer::NonPlayer( sf::Shape * shape, ge::Color color, Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition ) : m_shape(shape), m_color(color), m_movement(movement), m_lifetime(lifetime), m_currTime(0), m_initPosition(initPosition) {
    m_shape->setPosition( m_initPosition );
}

NonPlayer::~NonPlayer() {
    std::cout << "deleted" << std::endl;
}

void NonPlayer::update(unsigned long long elapsed){
    m_currTime += elapsed;
    m_movement->update(elapsed , m_shape);
}
        
bool NonPlayer::canBeDestroyed() const{
    return  ( m_currTime > m_lifetime );
}

void NonPlayer::start(){
    m_shape->setFillColor( m_color.color() );
    m_movement->start();
}

sf::Shape * NonPlayer::shape() const{
    return m_shape;
}
