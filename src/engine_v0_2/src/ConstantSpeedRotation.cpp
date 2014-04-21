/* 
 * File:   ConstantSpeedRotation.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:07
 */

#include "ConstantSpeedRotation.h"

using namespace ge;

ConstantSpeedRotation::ConstantSpeedRotation( double angularSpeed ) : Rotation(), m_angularSpeed(angularSpeed) {
}

ConstantSpeedRotation::~ConstantSpeedRotation() {
}

double ConstantSpeedRotation::rotation(unsigned long long elapsed){
    return 360 * m_angularSpeed * ( elapsed / 1000000.0 );
}
        
Rotation * ConstantSpeedRotation::clone() const{
    return new ConstantSpeedRotation( m_angularSpeed );
}