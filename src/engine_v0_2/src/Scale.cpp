/* 
 * File:   Scale.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:05
 */

#include "Scale.h"

using namespace ge;

Scale::Scale() {
}


Scale::~Scale() {
}

void Scale::nonPlayer( NonPlayer * nonPlayer ){
    m_nonPlayer = nonPlayer;
}