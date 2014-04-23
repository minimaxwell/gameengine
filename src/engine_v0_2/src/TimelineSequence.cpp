/* 
 * File:   TimelineSequence.cpp
 * Author: maxwell
 * 
 * Created on 23 avril 2014, 22:34
 */

#include "TimelineSequence.h"
#include <iostream>
using namespace ge;

TimelineSequence::TimelineSequence() {
}

TimelineSequence::~TimelineSequence() {
}

void TimelineSequence::update(unsigned long long elapsed){
    
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
    
    std::multimap<unsigned long long, NonPlayer *>::iterator tlIt = m_timeline.begin();
    while( tlIt != m_timeline.end() && tlIt->first <= m_elapsedTime + elapsed ){
        NonPlayer * pl = tlIt->second;
        pl->start();
        pl->update( m_elapsedTime + elapsed - tlIt->first );
        m_activeEntities.push_back(pl);
        tlIt = m_timeline.erase( tlIt );
        
    }
    
    m_elapsedTime += elapsed;
    
}

bool TimelineSequence::ended() const{
    return m_started && m_timeline.empty() && m_activeEntities.empty();
}

void TimelineSequence::addEntity( unsigned long long startingTimestamp,  NonPlayer * entity ){
    m_timeline.insert(
        std::pair<unsigned long long, NonPlayer *>(
            startingTimestamp,
            entity
        )
    );
}

Sequence * TimelineSequence::clone() const{
    TimelineSequence * s = new TimelineSequence();
    
    for( std::multimap<unsigned long long, NonPlayer *>::const_iterator it = m_timeline.begin() ; it != m_timeline.end() ; it++ ){
        s->addEntity( it->first , it->second->clone() );
    }
        
    return s;
}