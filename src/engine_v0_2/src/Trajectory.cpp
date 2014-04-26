/* 
 * File:   Trajectory.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 18:05
 */

#include "Trajectory.h"

using namespace ge;

Trajectory::Trajectory() {
}

Trajectory::~Trajectory() {
}

void Trajectory::nonPlayer( NonPlayer * nonPlayer ){
    m_nonPlayer = nonPlayer;
}