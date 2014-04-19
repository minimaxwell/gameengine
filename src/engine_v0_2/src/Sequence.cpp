/* 
 * File:   Sequence.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:03
 */

#include "Sequence.h"

using namespace ge;

Sequence::Sequence() : m_started(false) {
}

Sequence::Sequence(const Sequence& orig) : m_started(false) {
    for( std::multimap<int, NonPlayer *>::const_iterator it = orig.m_timeline.begin(); it != orig.m_timeline.end() ; it++){
        addNonPlayer( it->first , it->second->clone() );
    }
}

Sequence::~Sequence() {
}


void Sequence::start(){
    m_started = true;
    m_clock.restart();
}
        
bool Sequence::hasNext() const{
    return m_started && ! ended() && m_timeline.begin()->first < m_clock.getElapsedTime().asMilliseconds();
}

NonPlayer * Sequence::next(){
    if( ! hasNext() )
        return nullptr;
    
    NonPlayer * player = m_timeline.begin()->second;
    m_timeline.erase( m_timeline.begin() );
    return player;
    
}

bool Sequence::ended() const{
    return m_timeline.empty();
}

void Sequence::addNonPlayer( int timestamp , NonPlayer * player ){
    m_timeline.insert( std::pair<int, NonPlayer *>( timestamp, player ) );
}