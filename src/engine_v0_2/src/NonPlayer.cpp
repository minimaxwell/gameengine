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
                      const sf::Vector2f& initPosition,
                      Player * player ) : m_shape( shape ), m_color( ge::Color::createColor( baseColor, fuzz ) , baseColor ), m_fuzz(fuzz), m_movement( movement ), m_lifetime( lifetime ), m_currTime(0), m_initPosition(initPosition), m_player(player) {
    m_shape->setOrigin( m_shape->getGlobalBounds().width / 2 , m_shape->getGlobalBounds().height / 2 );
    m_shape->setPosition( m_initPosition );
    m_movement->nonPlayer( this );
}


NonPlayer::NonPlayer( sf::Shape * shape, ge::Color color, Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition, Player * player ) : m_shape(shape), m_color(color), m_movement(movement), m_lifetime(lifetime), m_currTime(0), m_initPosition(initPosition), m_player(player) {
    m_shape->setOrigin( m_shape->getGlobalBounds().width / 2 , m_shape->getGlobalBounds().height / 2 );
    m_shape->setPosition( m_initPosition );
    m_movement->nonPlayer( this );
}

NonPlayer::~NonPlayer() {
    std::cout << "deleted" << std::endl;
}

void NonPlayer::update(unsigned long long elapsed){
    m_currTime += elapsed;
    m_movement->update(elapsed , m_shape);

    if( m_player->collidesWith(this) ){
        m_color = ge::Color::yellow;
        m_shape->setFillColor( ge::Color::yellow.color() );
    }
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

void NonPlayer::player(  Player *  player ){
    m_player = player;
}

ge::Color NonPlayer::color() const{
    return m_color;
}

void NonPlayer::color( const ge::Color& color ){
    m_color = color;
}