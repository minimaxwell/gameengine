/* 
 * File:   ColorPulse.cpp
 * Author: maxwell
 * 
 * Created on 1 mai 2014, 13:15
 */

#include "ColorPulse.h"
#include "Background.h"

using namespace ge;

ColorPulse::ColorPulse( std::vector<ge::Color> colors, unsigned long long period ) : m_period(period), m_currentColorIndex(0), m_currentTime(0), m_next(period), m_colors(colors){
}

ColorPulse::ColorPulse( std::vector<ge::Color> colors, unsigned int currentIndex, unsigned long long currentTime, unsigned long long period, unsigned long long next ) : 
                        m_period( period ), m_currentColorIndex(currentIndex), m_currentTime(currentTime), m_next(next), m_colors(colors){
    
}

ColorPulse::~ColorPulse() {
}

unsigned int ColorPulse::incIndex(){
    m_currentColorIndex = m_currentColorIndex + 1 == m_colors.size() ? 0 : m_currentColorIndex + 1;
    return m_currentColorIndex;
}

ge::Color ColorPulse::color(unsigned long long elapsed, bool& changed){
    changed = false;
    while( m_currentTime + elapsed >= m_next  ){
        changed = true;
        incIndex();
        m_next += m_period;
    }
    m_currentTime += elapsed;
    return m_colors[ m_currentColorIndex ];
}

ColorEffect * ColorPulse::clone() const{
    return new ColorPulse( m_colors, m_currentColorIndex, m_currentTime, m_period, m_next );
}