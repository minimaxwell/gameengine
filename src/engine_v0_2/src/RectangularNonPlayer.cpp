/* 
 * File:   RectangularNonPlayer.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:02
 */

#include "RectangularNonPlayer.h"

using namespace ge;

RectangularNonPlayer::RectangularNonPlayer( float width, float height, eColor baseColor, int fuzz,Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition ) :
                                            NonPlayer( new sf::RectangleShape( sf::Vector2f( width, height ) ) , baseColor, fuzz, movement, lifetime, initPosition ), m_width( width ), m_height( height ) {
}

RectangularNonPlayer::RectangularNonPlayer( float width, float height, const ge::Color& color,Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition ) : 
                                            NonPlayer( new sf::RectangleShape( sf::Vector2f( width, height ) ) , color, movement, lifetime, initPosition ), m_width( width ), m_height( height ){
    
}


RectangularNonPlayer::~RectangularNonPlayer() {
}

NonPlayer * RectangularNonPlayer::clone() const{
    return new RectangularNonPlayer( m_width, m_height, m_color, new Movement(*m_movement), m_lifetime , m_initPosition );
}