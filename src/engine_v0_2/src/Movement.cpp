/* 
 * File:   Movement.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:04
 */

#include "Movement.h"

using namespace ge;

Movement::Movement() : m_started(false) {
}

Movement::Movement(const Movement& orig) : m_started(false) {
    for( std::multimap<int, Transformation *>::const_iterator it = orig.m_timeline.begin(); it != orig.m_timeline.end() ; it++){
        addTransformation( it->first , new Transformation( *( it->second) ) );
    }
}

Movement::~Movement() {
}

sf::Transform Movement::movement(float elapsed){
    
    if( !m_started )
        return sf::Transform();
    
    // TODO : The transformation began somewhere during "elasped". We need to find when, and apply the transformation to this period.
    std::multimap<int, Transformation *>::iterator it = m_timeline.begin();
    while(m_timeline.begin()->first < m_clock.getElapsedTime().asMilliseconds() && it != m_timeline.end() ){
        m_currentTransformations.push_back( it->second );
        it = m_timeline.erase( it );
    }
    
    sf::Transform tr;
    std::vector<Transformation *>::iterator itt = m_currentTransformations.begin() ;
    while( itt != m_currentTransformations.end()  ){
        if( (*itt)->hasEnded() ){
            itt = m_currentTransformations.erase( itt );
        }else{
            tr.combine((*itt)->transform(elapsed));
            itt++;
        }
    }
    return tr;
}
        
void Movement::addTransformation( int timestamp, Transformation * transformation ){
    m_timeline.insert( std::pair<int, Transformation *>(timestamp, transformation) );
}

void Movement::start(){
    m_started = true;
    m_clock.restart();
}