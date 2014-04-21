/* 
 * File:   LinearTrajectory.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:05
 */

#include "LinearTrajectory.h"
#include <iostream>
using namespace ge;

LinearTrajectory::LinearTrajectory( const sf::Vector2f& speedVector ) : m_speedVector(speedVector) {
}

LinearTrajectory::~LinearTrajectory() {
}

sf::Vector2f LinearTrajectory::movement(unsigned long long elapsed){
    double elapsedSeconds = elapsed / 1000000.0;
    return sf::Vector2f( m_speedVector.x * elapsedSeconds  , m_speedVector.y * elapsedSeconds  );
}
        
Trajectory * LinearTrajectory::clone() const{
    return new LinearTrajectory( m_speedVector );
}