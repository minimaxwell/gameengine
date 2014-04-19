/* 
 * File:   Player.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 16:47
 */

#include "Player.h"

using namespace ge;

Player::Player( const std::vector<ge::Color>& colorPoll, const sf::Vector2f& initPosition, float baseSpeed ) : m_currentColorIndex(0), m_colorPoll(colorPoll), m_position(initPosition), m_baseSpeed(baseSpeed) {
}

Player::~Player() {
}

void Player::update( float elapsed ){

    float speed = m_baseSpeed;
    sf::Vector2f deplacement;
    
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::LShift ) ){
        speed *= 2;
    }
    
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::Z ) ){
        deplacement.y = -speed * elapsed;
    }
    
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::S ) ){
        deplacement.y = speed * elapsed;
    }
    
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::Q ) ){
        deplacement.x = -speed * elapsed;
    }
    
    if(sf::Keyboard::isKeyPressed( sf::Keyboard::D ) ){
        deplacement.x = speed * elapsed;
    }
    
    m_position += deplacement;
    m_shape->setPosition(m_position);
    
}
        
void Player::toggleColor(){
    if( ++m_currentColorIndex > ( m_colorPoll.size() - 1 ) )
        m_currentColorIndex = 0;
    
    m_shape->setFillColor( m_colorPoll[ m_currentColorIndex ].color() );
    
}
        
bool Player::collidesWith( const sf::Shape& shape ) const{
    if( m_shape->getGlobalBounds().intersects( shape.getGlobalBounds() ) ){
        return true; // Dirty collision system. To be improved later.
    }
    
    return false;
}

const sf::Shape * Player::shape() const{
    return m_shape;
}
        
void Player::shape( sf::Shape * shape ){
    m_shape = shape;
    m_shape->setPosition( m_position );
    m_shape->setFillColor(  m_colorPoll[ m_currentColorIndex ].color() );
}