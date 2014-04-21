/* 
 * File:   SinusoidalTrajectory.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:06
 */

#include "SinusoidalTrajectory.h"
#include<cmath>
using namespace ge;

SinusoidalTrajectory::SinusoidalTrajectory( double angularSpeed, const sf::Vector2f& baseDirection, double initAngle ) : 
                                            m_angularSpeed(angularSpeed), m_baseDirection(baseDirection), m_initAngle(initAngle), m_currentAngle(initAngle){
}

SinusoidalTrajectory::~SinusoidalTrajectory() {
}

sf::Vector2f SinusoidalTrajectory::movement(unsigned long long elapsed){
    double alpha = m_angularSpeed * ( elapsed / 1000000.0 );
    
    sf::Vector2f result( m_baseDirection.x * (cos( 3.1415926f * ( (m_currentAngle + alpha) / 180 ) )  - cos(  3.1415926f * ( m_currentAngle / 180 ) ) ),-m_baseDirection.y * ( cos( 3.1415926f * ( (m_currentAngle + alpha) / 180 ) )  - cos(  3.1415926f * ( m_currentAngle / 180 ) ) ) );

    m_currentAngle += alpha;
    
    return result;
}
        
Trajectory * SinusoidalTrajectory::clone() const{
    return new SinusoidalTrajectory( m_angularSpeed , m_baseDirection, m_initAngle );
}