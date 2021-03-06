/* 
 * File:   Transformation.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:04
 */

#include "Transformation.h"
#include "Game.h"
#include "ColorEffect.h"
#include<iostream>
using namespace ge;

Transformation::Transformation( unsigned long long lifetime ) : m_trajectory(nullptr), m_rotation(nullptr), m_scale(nullptr) , m_colorEffect(nullptr) , m_lifetime(lifetime) , m_started(false), m_ended(false) {
}

Transformation::Transformation(const Transformation& orig) :m_trajectory(nullptr), m_rotation(nullptr), m_scale(nullptr), m_colorEffect(nullptr),  m_lifetime(orig.m_lifetime), m_started(false), m_ended(false) {
    if( orig.m_trajectory != nullptr ){
        m_trajectory = orig.m_trajectory->clone();
    }
    
    if( orig.m_rotation != nullptr ){
        m_rotation = orig.m_rotation->clone();
    }
    
    if( orig.m_scale != nullptr ){
        m_scale = orig.m_scale->clone();
    }
    
    if( orig.m_colorEffect != nullptr ){
        m_colorEffect = orig.m_colorEffect->clone();
    }
}

Transformation::~Transformation() {
}

TransformationComponent Transformation::transform(unsigned long long elapsed){
    
    TransformationComponent tr = { sf::Vector2f(0,0) , 0 , sf::Vector2f( 1.f , 1.f ) , false, ge::Color::white};

    
    if( m_ended ){
        return tr;
    }
    
    if( m_aliveTime + elapsed >= m_lifetime ){
        m_ended = true;
        elapsed = m_lifetime - m_aliveTime;
    }
    
    m_aliveTime += elapsed;
    
    if( m_trajectory != nullptr )
        tr.translation =  m_trajectory->movement(elapsed) ;
    
    if( m_rotation != nullptr )
        tr.rotation =  m_rotation->rotation(elapsed) ;
    
    if( m_scale != nullptr )
        tr.scale =  m_scale->scale(elapsed) ;
    
    if( m_colorEffect != nullptr ){
        tr.color = m_colorEffect->color(elapsed, tr.colorChange);
    }
    
    return tr;
}

void Transformation::start(){
    m_aliveTime = 0;
    m_started = true;
}

bool Transformation::hasEnded() const{
    return  m_ended;
}

unsigned long long Transformation::lifetime() const{
    return m_lifetime;
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

void Transformation::colorEffect( ColorEffect * colorEffect ){
    m_colorEffect = colorEffect;
}


void Transformation::nonPlayer( NonPlayer * nonPlayer ){
    m_nonPlayer = nonPlayer;
    
     if( m_trajectory != nullptr )
         m_trajectory->nonPlayer( nonPlayer );
    
    if( m_rotation != nullptr )
        m_rotation->nonPlayer( nonPlayer );
    
    if( m_scale != nullptr )
        m_scale->nonPlayer( nonPlayer );
}