/* 
 * File:   Rotation.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:05
 */

#include "Rotation.h"

using namespace ge;

Rotation::Rotation() {
}

Rotation::~Rotation() {
}

void Rotation::nonPlayer( NonPlayer * nonPlayer ){
    m_nonPlayer = nonPlayer;
}