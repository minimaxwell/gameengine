/* 
 * File:   LinearTrajectory.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:05
 */

#include "LinearTrajectory.h"

using namespace ge;

LinearTrajectory::LinearTrajectory( const sf::Vector2f& speedVector ) : m_speedVector(speedVector) {
}

LinearTrajectory::~LinearTrajectory() {
}

sf::Vector2f LinearTrajectory::movement(float elapsed){
    return sf::Vector2f( m_speedVector.x * elapsed  , m_speedVector.y * elapsed  );
}
        
Trajectory * LinearTrajectory::clone() const{
    return new LinearTrajectory( m_speedVector );
}