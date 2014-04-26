/* 
 * File:   Level.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:03
 */

#include "Level.h"
#include "Game.h"

using namespace ge;

Level::Level( Background * background, std::vector<ge::Color> playerColorPoll ) : m_background(background) , m_playerColorPoll(playerColorPoll), m_started(false) {
}

Level::Level(const Level& orig) : m_started(false) {
    for(std::multimap< unsigned long long, Sequence * >::const_iterator it = orig.m_timeline.begin() ; it != orig.m_timeline.end() ; it++ ){
        addSequence( it->first ,it->second->clone());
    }
}

Level::~Level() {
    delete m_background;
}

void Level::addSequence( unsigned long long timestamp, Sequence * sequence ){
    m_timeline.insert( std::pair<unsigned long long, Sequence *>(timestamp, sequence) );
}

bool Level::hasEnded() const{
    return m_timeline.empty();
}

void Level::start(){
    m_started = true;
    m_elapsedTime = 0;
}

void Level::draw( sf::RenderTarget * target ) const{
    for( std::vector<Sequence *>::const_iterator it = m_activeSequences.begin() ; it != m_activeSequences.end() ; it++ ){
        (*it)->draw(target);
    }
}

void Level::update(unsigned long long elapsed){
    
    std::vector<Sequence *>::iterator sIt = m_activeSequences.begin();
    while( sIt != m_activeSequences.end() ){
        
        (*sIt)->update(elapsed);
        
        if( (*sIt)->ended() ){
            Sequence * s_toDelete = *sIt;
            sIt = m_activeSequences.erase( sIt );
            delete s_toDelete;
        }else{
            sIt++;
        }
        
    }
    
    std::multimap<unsigned long long, Sequence *>::iterator it = m_timeline.begin();
    while( it != m_timeline.end() && it->first <= m_elapsedTime + elapsed ){
        
        Sequence * s = it->second;
        s->start();
        s->update( m_elapsedTime + elapsed - it->first );
        m_activeSequences.push_back( s );
        it = m_timeline.erase( it );
        
    }
    
    m_elapsedTime += elapsed;
    
}

Player * Level::player(){
    return m_player;
}

void Level::player( Player * player ){
    m_player = player;
}