/* 
 * File:   Level.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:03
 */

#include "Level.h"
#include "Game.h"

using namespace ge;

Level::Level( Background * background, std::vector<ge::Color> playerColorPoll ) : m_background(background) , m_playerColorPoll(playerColorPoll) {
}

Level::Level(const Level& orig) : m_started(false) {
    for(std::multimap< unsigned long long, Sequence * >::const_iterator it = orig.m_timeline.begin() ; it != orig.m_timeline.end() ; it++ ){
        addSequence( it->first , new Sequence( *( it->second ) ) );
    }
}

Level::~Level() {
    delete m_background;
}

void Level::addSequence( unsigned long long timestamp, Sequence * sequence ){
    m_timeline.insert( std::pair<unsigned long long, Sequence *>(timestamp, sequence) );
}

Sequence * Level::next(){
    if( !hasNext() )
        return nullptr;
    
    Sequence * s = m_timeline.begin()->second;
    m_timeline.erase( m_timeline.begin() );
    return s;
}

bool Level::hasNext() const{
    return m_started && ! hasEnded() && m_timeline.begin()->first < ( Game::currentTimestamp - m_startingTimestamp );
}

bool Level::hasEnded() const{
    return m_timeline.empty();
}

void Level::start(){
    m_started = true;
    m_startingTimestamp = Game::currentTimestamp;
}