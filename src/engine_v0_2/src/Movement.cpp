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
    for( std::multimap<unsigned long long, Transformation *>::const_iterator it = orig.m_timeline.begin() ; it != orig.m_timeline.end() ; it++ ){
        addTransformation( it->first ,  new Transformation( *( it->second  ) ) );
    }
}

Movement::~Movement() {
}

void Movement::update( unsigned long long elapsed , sf::Shape * shape ){
    
    if( ! m_started )
        return;

  
    
    // huhu transIt
    std::vector<Transformation *>::iterator transIt = m_activeTransformations.begin() ;
    while( transIt != m_activeTransformations.end()  ){
        
        TransformationComponent tc = (*transIt)->transform(elapsed);
        shape->move( tc.translation );
        shape->rotate( tc.rotation );
        shape->scale( tc.scale );
        
        if( (*transIt)->hasEnded() ){
            Transformation * tr_toDelete = *transIt;
            transIt = m_activeTransformations.erase( transIt );
            delete tr_toDelete;
        }else{
            transIt++ ;
        }
        
    }
        
      // we find the movement that need to be activated during the elapsed time
    std::multimap< unsigned long long, Transformation * >::iterator it = m_timeline.begin();
    while( it != m_timeline.end() && it->first <= m_elapsedTime + elapsed ){
        Transformation * tr = it->second;
        tr->start();
        
        TransformationComponent tc = it->second->transform( m_elapsedTime + elapsed - it->first );
        shape->move( tc.translation );
        shape->rotate( tc.rotation );
        shape->scale( tc.scale );
        
        m_activeTransformations.push_back( it->second );
        it = m_timeline.erase( it ); // we remove the first element.
    }
    
    m_elapsedTime += elapsed;
    
}
                
void Movement::addTransformation( unsigned long long departureTimestamp , Transformation * transformation ){
    m_timeline.insert(
    std::pair<unsigned long long, Transformation *>(
        departureTimestamp,
        transformation)
    );
}
        
void Movement::start(){
    m_elapsedTime = 0;
    m_started = true;
}