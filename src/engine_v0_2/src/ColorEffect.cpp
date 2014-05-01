/* 
 * File:   ColorEffect.cpp
 * Author: maxwell
 * 
 * Created on 1 mai 2014, 11:37
 */

#include "ColorEffect.h"

using namespace ge;

ColorEffect::ColorEffect() {
}

ColorEffect::~ColorEffect() {
}

void ColorEffect::nonPlayer( NonPlayer * nonPlayer ){
    m_nonPlayer = nonPlayer;
}
