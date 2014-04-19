/* 
 * File:   ConstantSpeedRotation.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:07
 */

#include "ConstantSpeedRotation.h"

using namespace ge;

ConstantSpeedRotation::ConstantSpeedRotation( float angularSpeed ) : Rotation(), m_angularSpeed(angularSpeed) {
}

ConstantSpeedRotation::~ConstantSpeedRotation() {
}

float ConstantSpeedRotation::rotation(float elapsed){
    return 360 * m_angularSpeed * elapsed;
}
        
Rotation * ConstantSpeedRotation::clone() const{
    return new ConstantSpeedRotation( m_angularSpeed );
}