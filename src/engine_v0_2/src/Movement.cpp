/* 
 * File:   Movement.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:04
 */

#include "Movement.h"
#include "Game.h"
#include <iostream>
using namespace ge;

Movement::Movement() : m_started(false) {
}

Movement::Movement(const Movement& orig) : m_started(false) {
    for( std::multimap<unsigned long long, Transformation *>::const_iterator it = orig.m_timeline.begin(); it != orig.m_timeline.end() ; it++){
        addTransformation( it->first , new Transformation( *( it->second) ) );
    }
}

Movement::~Movement() {
}

void Movement::movement(unsigned long long elapsed, sf::Shape * shape){
    
    if( !m_started )
        return ;
    
    // TODO : The transformation began somewhere during "elasped". We need to find when, and apply the transformation to this period.
    std::multimap<unsigned long long, Transformation *>::iterator it = m_timeline.begin();
    while(m_timeline.begin()->first < Game::currentTimestamp - m_startingTime && it != m_timeline.end() ){
        it->second->start();
        m_currentTransformations.push_back( it->second );
        it = m_timeline.erase( it );
    }
    
    TransformationComponent tr;
    std::vector<Transformation *>::iterator itt = m_currentTransformations.begin() ;
    while( itt != m_currentTransformations.end()  ){
        if( (*itt)->hasEnded() ){
            itt = m_currentTransformations.erase( itt );
        }else{
            tr = (*itt)->transform(elapsed);
            
            shape->move( tr.translation );
            shape->rotate( tr.rotation );
            shape->scale( tr.scale );
            itt++;
        }
    }
}
        
void Movement::addTransformation( unsigned long long timestamp, Transformation * transformation ){
    m_timeline.insert( std::pair<unsigned long long, Transformation *>(timestamp, transformation) );
}

void Movement::start(){
    m_started = true;
    m_startingTime = Game::currentTimestamp;
}