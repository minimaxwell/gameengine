/* 
 * File:   SynchronizedColorPulse.cpp
 * Author: maxwell
 * 
 * Created on 1 mai 2014, 13:54
 */

#include "SynchronizedColorPulse.h"
#include "Game.h"
#include<iostream>
using namespace ge;

SynchronizedColorPulse::SynchronizedColorPulse() {
}

SynchronizedColorPulse::~SynchronizedColorPulse() {
}

unsigned long long SynchronizedColorPulse::m_period = 0;
unsigned long long SynchronizedColorPulse::m_next = 0;
unsigned int SynchronizedColorPulse::m_currentColorIndex = 0;
std::vector<ge::Color> SynchronizedColorPulse::m_colors;

unsigned int SynchronizedColorPulse::incIndex(){
    m_currentColorIndex = m_currentColorIndex + 1 == m_colors.size() ? 0 : m_currentColorIndex + 1;
    return m_currentColorIndex;
}


ge::Color SynchronizedColorPulse::color(unsigned long long elapsed, bool& changed){
    (void)elapsed; // unused
    
    
    while( Game::currentTimestamp >= m_next ){
        std::cout << "stuck " << m_next << " " << Game::currentTimestamp << std::endl;
        incIndex();
        m_next += m_period;
    }
    
    changed = true;
    return m_colors[ m_currentColorIndex ];
}
 

ColorEffect * SynchronizedColorPulse::clone() const{
    return new SynchronizedColorPulse();
}