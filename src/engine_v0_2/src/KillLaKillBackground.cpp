/* 
 * File:   KillLaKillBackground.cpp
 * Author: maxwell
 * 
 * Created on 24 avril 2014, 18:58
 */

#include "KillLaKillBackground.h"
#include "Game.h"

using namespace ge;

KillLaKillBackground::KillLaKillBackground( unsigned int nbLines ) : Background() , m_nbLines(nbLines), m_vertices( nbLines ), m_rotatingSpeeds(nbLines){
    
    
    
    for( unsigned int i = 0 ; i < m_nbLines ; i++ ){
        
        sf::Vector2f rectParams( Game::parameters.gameWidth * 2, (rand() % 4) + 1 );
        m_vertices[i] = new sf::RectangleShape( rectParams );  
        m_vertices[i]->setOrigin( rectParams.x / 2 , rectParams.y / 2 );

        m_rotatingSpeeds[i] = ( 5 + ( rand() % 355 ) ) / 360.f;
        m_rotatingSpeeds[i] = (rand() % 2 == 1 ? -m_rotatingSpeeds[i] : m_rotatingSpeeds[i] );
        
        m_vertices[i]->move( 50 + (rand() % Game::parameters.gameWidth - 100 ) ,
                             50 + (rand() % Game::parameters.gameHeight - 100 ));
        m_vertices[i]->rotate( rand() % 360 );
        
        m_vertices[i]->setFillColor( sf::Color(255,10,10,100) ) ;
        
    }
    
}



KillLaKillBackground::~KillLaKillBackground() {
}


void KillLaKillBackground::update(unsigned long long elapsed){
    
    for( unsigned int i = 0 ; i < m_nbLines ; i++ ){
        double elapsedD = elapsed / 1000000.f;
        m_vertices[i]->rotate( elapsedD * m_rotatingSpeeds[i]);
    }
    
}
        
void KillLaKillBackground::draw( sf::RenderTarget& target, sf::RenderStates states ) const{

    for( unsigned int i = 0 ; i < m_nbLines ; i++ ){
        target.draw( *m_vertices[i] );
    }
    
}