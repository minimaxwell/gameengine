/* 
 * File:   ConstantSpeedScale.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:07
 */

#include "ConstantSpeedScale.h"

using namespace ge;

ConstantSpeedScale::ConstantSpeedScale( float expansionSpeed ) : Scale(), m_expansionSpeed( expansionSpeed ) {
}

ConstantSpeedScale::~ConstantSpeedScale() {
}

sf::Vector2f ConstantSpeedScale::scale(float elapsed){
    return sf::Vector2f( m_expansionSpeed * ( 1.f +elapsed ) , m_expansionSpeed * ( 1.f + elapsed ) );
}

Scale * ConstantSpeedScale::clone() const{
    return new ConstantSpeedScale( m_expansionSpeed );
}