/* 
 * File:   StarBackground.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:04
 */

#include "StarBackground.h"

using namespace ge;

StarBackground::StarBackground( const sf::Vector2f& baseSpeed, unsigned int nbElements ) : m_baseSpeed(baseSpeed), m_nbElements(nbElements) , m_depths(nbElements), m_vertices(sf::Points, nbElements) {
    
    for( unsigned int i = 0 ; i < m_nbElements ; i++ ){
        int depth = 50 + rand() % 150;
        m_vertices[i].color.r = depth;
        m_vertices[i].color.g = depth;
        m_vertices[i].color.b = depth;
        
        m_depths[i] = depth;
        
        m_vertices[i].position.x = rand() % 1440;
        m_vertices[i].position.y = rand() % 900;
    }

}

StarBackground::~StarBackground() {
}

void StarBackground::update(unsigned long long elapsed){
    for( unsigned int i = 0 ; i < m_nbElements ; i++ ){
        if( m_vertices[i].position.x < 0 || m_vertices[i].position.x > 1440 || m_vertices[i].position.y < 0 || m_vertices[i].position.y > 900 ){
            int depth = 50 + rand() % 150;
        m_vertices[i].color.r = depth;
        m_vertices[i].color.g = depth;
        m_vertices[i].color.b = depth;
        
        m_depths[i] = depth;
        
        m_vertices[i].position.x = 1440;
        m_vertices[i].position.y = rand() % 900;
        }
        
        double elapsedSeconds = ( elapsed / 1000000.0 ); // microseconds to seconds
        m_vertices[i].position.x += m_baseSpeed.x  * elapsedSeconds* ( m_depths[i] / 200.f );
        m_vertices[i].position.y += m_baseSpeed.y * elapsedSeconds * ( m_depths[i] / 200.f );
        
    }
}

void StarBackground::draw( sf::RenderTarget& target, sf::RenderStates states ) const{
    states.transform *= getTransform();

    states.texture = NULL;

    target.draw(m_vertices, states);
}

void StarBackground::baseSpeed( const sf::Vector2f& baseSpeed ){
    m_baseSpeed = baseSpeed;
}