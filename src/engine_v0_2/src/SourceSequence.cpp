/* 
 * File:   SourceSequence.cpp
 * Author: maxwell
 * 
 * Created on 24 avril 2014, 23:12
 */

#include "SourceSequence.h"

using namespace ge;

SourceSequence::SourceSequence( NonPlayer * baseNonPlayer , unsigned long long delay , long nbElements) : m_nbElements(nbElements), m_delay(delay) , m_baseNonPlayer(baseNonPlayer) {
    m_nextElement = 0;
    m_createdElements = 0;
}

SourceSequence::~SourceSequence() {
}

void SourceSequence::update(unsigned long long elapsed){
    
    std::vector< NonPlayer * >::iterator it = m_activeEntities.begin();
    while( it != m_activeEntities.end() ){
        (*it)->update(elapsed);
        
        if( (*it)->canBeDestroyed() ){
            NonPlayer * pl_toDelete = *it;
            it = m_activeEntities.erase(it);
            delete pl_toDelete;
        }else{
            it++;
        }
    }
    
    while( m_elapsedTime + elapsed >= m_nextElement && ( m_nbElements < 0 || m_createdElements < m_nbElements ) ){
        NonPlayer * nonPlayer = m_baseNonPlayer->clone();
        nonPlayer->start();
        nonPlayer->update( m_elapsedTime + elapsed - m_nextElement );
        m_activeEntities.push_back( nonPlayer );
        m_nextElement += m_delay;
        if( m_nbElements > 0 ){
            m_createdElements++;
        }
    }
    
    m_elapsedTime += elapsed;
    
}

bool SourceSequence::ended() const{
    return m_nbElements >= 0 && m_createdElements < m_nbElements && m_activeEntities.empty()  ;
}

void SourceSequence::addEntity( unsigned long long startingTimestamp,  NonPlayer * entity ){
    (void) startingTimestamp;
    (void) entity;
    // do nothing
}

Sequence * SourceSequence::clone() const{
    return new SourceSequence( m_baseNonPlayer->clone(), m_delay, m_nbElements );
}