/* 
 * File:   ConstantSpeedScale.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:07
 */

#include "ConstantSpeedScale.h"

using namespace ge;

ConstantSpeedScale::ConstantSpeedScale( double expansionSpeed ) : Scale(), m_expansionSpeed( expansionSpeed ) {
}

ConstantSpeedScale::~ConstantSpeedScale() {
}

sf::Vector2f ConstantSpeedScale::scale(unsigned long long elapsed){
    double elapsedSeconds = elapsed / 1000000.0;
    return sf::Vector2f( 1.f + ( m_expansionSpeed * elapsedSeconds ) ,  1.f +( m_expansionSpeed * elapsedSeconds ) );
}

Scale * ConstantSpeedScale::clone() const{
    return new ConstantSpeedScale( m_expansionSpeed );
}