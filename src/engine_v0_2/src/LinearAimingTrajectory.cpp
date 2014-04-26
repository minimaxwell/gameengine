/* 
 * File:   LinearAimingTrajectory.cpp
 * Author: maxwell
 * 
 * Created on 26 avril 2014, 22:18
 */

#include "LinearAimingTrajectory.h"
#include "Player.h"
#include "NonPlayer.h"
#include <math.h>

#include <iostream>

using namespace ge;

LinearAimingTrajectory::LinearAimingTrajectory( const Player * const player, double speed ) : m_player(player) , m_speed(speed), m_hasMoved(false) {
}

LinearAimingTrajectory::~LinearAimingTrajectory() {
}

sf::Vector2f LinearAimingTrajectory::movement(unsigned long long elapsed){
    if( ! m_hasMoved ){
        m_hasMoved = true;
        sf::Vector2f distVector = m_player->position() - m_nonPlayer->shape()->getPosition();
        double distVectorNorm = sqrt( distVector.x * distVector.x + distVector.y * distVector.y );
        m_speedVector.x = ( m_speed * distVector.x) / distVectorNorm;
        m_speedVector.y = ( m_speed * distVector.y) / distVectorNorm;
        std::cout << "Speed vector : " << m_speedVector.x << " , " << m_speedVector.y << std::endl;
    }
    
    double elapsedSeconds = elapsed / 1000000.0;
    return sf::Vector2f( m_speedVector.x * elapsedSeconds  , m_speedVector.y * elapsedSeconds  );
    
}

Trajectory * LinearAimingTrajectory::clone() const{
    return new LinearAimingTrajectory( m_player, m_speed );
}
