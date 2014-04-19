/* 
 * File:   Transformation.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:04
 */

#include "Transformation.h"

using namespace ge;

Transformation::Transformation( float lifetime ) : m_trajectory(nullptr), m_rotation(nullptr), m_scale(nullptr) , m_lifetime(lifetime) , m_started(false) {
}

Transformation::Transformation(const Transformation& orig) : m_lifetime(orig.m_lifetime), m_started(false) {
    if( orig.m_trajectory != nullptr ){
        m_trajectory = orig.m_trajectory->clone();
    }
    
    if( orig.m_rotation != nullptr ){
        m_rotation = orig.m_rotation->clone();
    }
    
    if( orig.m_scale != nullptr ){
        m_scale = orig.m_scale->clone();
    }
}

Transformation::~Transformation() {
}

sf::Transform Transformation::transform(float elapsed){
    sf::Transform tr;
    
    if( m_trajectory != nullptr )
        tr.translate( m_trajectory->movement(elapsed) );
    
    if( m_rotation != nullptr )
        tr.rotate( m_rotation->rotation(elapsed) );
    
    if( m_scale != nullptr )
        tr.scale( m_scale->scale(elapsed) );
    
    return tr;
}

void Transformation::start(){
    m_started = true;
    m_clock.restart();
}

bool Transformation::hasEnded() const{
    return  m_lifetime > 0.f &&  m_clock.getElapsedTime().asSeconds() > m_lifetime;
}

void Transformation::trajectory( Trajectory * trajectory ){
    m_trajectory = trajectory;
}

void Transformation::rotation( Rotation * rotation ){
    m_rotation = rotation;
}

void Transformation::scale( Scale * scale){
    m_scale = scale;
}
