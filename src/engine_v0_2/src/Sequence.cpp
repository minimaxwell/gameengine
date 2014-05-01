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

Sequence::~Sequence() {
}

void Sequence::draw( sf::RenderTarget * target ) const{
    for(std::vector< NonPlayer * >::const_iterator it = m_activeEntities.begin() ; it != m_activeEntities.end() ; it++){
        target->draw( *((*it)->shape()) );
    }
}

void Sequence::start(){
    m_started = true;
    m_elapsedTime = 0;
}

void Sequence::player(  Player * player ){
    m_player = player;
}