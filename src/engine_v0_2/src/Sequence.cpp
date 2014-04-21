/* 
 * File:   Sequence.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:03
 */

#include "Sequence.h"
#include "Game.h"

using namespace ge;

Sequence::Sequence() : m_started(false) {
}

Sequence::Sequence(const Sequence& orig) : m_started(false) {
    for( std::multimap<unsigned long long, NonPlayer *>::const_iterator it = orig.m_timeline.begin(); it != orig.m_timeline.end() ; it++){
        addNonPlayer( it->first , it->second->clone() );
    }
}

Sequence::~Sequence() {
}


void Sequence::start(){
    m_started = true;
    m_startingTimestamp = Game::currentTimestamp;
}
        
bool Sequence::hasNext() const{
    return m_started && ! ended() && m_timeline.begin()->first < ( Game::currentTimestamp - m_startingTimestamp ) ;
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

void Sequence::addNonPlayer( unsigned long long timestamp , NonPlayer * player ){
    m_timeline.insert( std::pair<unsigned long long, NonPlayer *>( timestamp, player ) );
}