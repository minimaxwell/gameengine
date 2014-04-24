/* 
 * File:   Player.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 16:47
 */

#include "Player.h"

using namespace ge;

Player::Player( const std::vector<ge::Color>& colorPoll, const sf::Vector2f& initPosition, double baseSpeed , MovementController * movementController) : m_currentColorIndex(0), m_colorPoll(colorPoll), m_position(initPosition), m_baseSpeed(baseSpeed), m_movementController(movementController) {
}

Player::~Player() {
    delete m_shape;
}

void Player::update( unsigned long long elapsed ){
    
    sf::Vector2f deplacement = m_movementController->move(elapsed);
    deplacement.x *= m_baseSpeed;
    deplacement.y *= m_baseSpeed;
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
    m_shape->setOrigin( m_shape->getGlobalBounds().width / 2 , m_shape->getGlobalBounds().height / 2 );
    m_shape->setPosition( m_position );
    m_shape->setFillColor(  m_colorPoll[ m_currentColorIndex ].color() );
}

void Player::movementController( MovementController * movementController ){
    MovementController * toDelete = m_movementController;
    m_movementController = movementController;
    delete toDelete;
}
        
MovementController * Player::movementController() const{
    return m_movementController;
}