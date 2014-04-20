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
                      float lifetime,
                      const sf::Vector2f& initPosition ) : m_shape( shape ), m_color( ge::Color::createColor( baseColor, fuzz ) , baseColor ), m_movement( movement ), m_lifetime( lifetime ), m_currtime(0), m_initPosition(initPosition) {
    m_shape->setPosition( m_initPosition );
}


NonPlayer::NonPlayer( sf::Shape * shape, ge::Color color, Movement * movement, float lifetime, const sf::Vector2f& initPosition ) : m_shape(shape), m_color(color), m_movement(movement), m_lifetime(lifetime), m_currtime(0), m_initPosition(initPosition) {
    m_shape->setPosition( m_initPosition );
}

NonPlayer::~NonPlayer() {
    std::cout << "deleted" << std::endl;
}

void NonPlayer::update(float elapsed){
    m_currtime += elapsed;
    return m_movement->movement(elapsed , m_shape);
}
        
bool NonPlayer::canBeDestroyed() const{
    return ( m_lifetime > 0 ) &&  ( m_currtime > m_lifetime );
}

void NonPlayer::start(){
    m_shape->setFillColor( m_color.color() );
    m_movement->start();
}

sf::Shape * NonPlayer::shape() const{
    return m_shape;
}
