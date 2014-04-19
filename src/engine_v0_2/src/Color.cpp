/* 
 * File:   Color.cpp
 * Author: maxwell
 * 
 * Created on 19 avril 2014, 15:47
 */

#include "Color.h"
#include <cstdlib>

using namespace ge;

const Color Color::red           ( sf::Color( 255, 0  , 0   ) , RED );
const Color Color::light_green   ( sf::Color( 153, 255, 153 ) , LIGHT_GREEN );
const Color Color::green         ( sf::Color( 0  , 255, 0   ) , GREEN );
const Color Color::blue          ( sf::Color( 0  , 0  , 255 ) , BLUE );
const Color Color::light_blue    ( sf::Color( 153, 255, 255 ) , LIGHT_BLUE );
const Color Color::yellow        ( sf::Color( 255, 255, 51  ) , YELLOW );
const Color Color::orange        ( sf::Color( 255, 128, 0   ) , ORANGE );
const Color Color::purple        ( sf::Color( 153, 0  , 153 ) , PURPLE );
const Color Color::pink          ( sf::Color( 255, 102, 178 ) , PINK );
const Color Color::white         ( sf::Color( 255, 255, 255 ) , WHITE );

Color::Color( const sf::Color color, eColor baseColor ) : m_color(color), m_baseColor(baseColor) {
}

Color::Color( eColor baseColor, int fuzz ) : m_color( createColor( baseColor, fuzz ) ) , m_baseColor(baseColor) {
    
}

Color::Color(const Color& orig) : m_color(orig.m_color), m_baseColor(orig.m_baseColor) {
}

Color::~Color() {
}

sf::Color Color::createColor( eColor baseColor, int fuzz ){
    
    sf::Color c;
    
    switch( baseColor ){
        case RED            : c = Color::red.m_color;         break;
        case LIGHT_GREEN    : c = Color::light_green.m_color; break;
        case GREEN          : c = Color::green.m_color;       break;
        case BLUE           : c = Color::blue.m_color;        break;
        case LIGHT_BLUE     : c = Color::light_blue.m_color;  break;
        case YELLOW         : c = Color::yellow.m_color;      break;
        case ORANGE         : c = Color::orange.m_color;      break;
        case PURPLE         : c = Color::purple.m_color;      break;
        case PINK           : c = Color::pink.m_color;        break;
        case WHITE          : c = Color::white.m_color;       break;
    }
    
    if( fuzz > 0 ){
        
        int rand_r = rand() % ( (2 * fuzz) + 1 );
        int rand_g = rand() % ( (2 * fuzz) + 1 );
        int rand_b = rand() % ( (2 * fuzz) + 1 );
        
        int r = c.r + ( rand_r - fuzz );
        int g = c.g + ( rand_g - fuzz );
        int b = c.b + ( rand_b - fuzz );
        
        
        c.r = r < 0 ? -r : ( r > 255 ? 510 - r : r );
        c.g = g < 0 ? -g : ( g > 255 ? 510 - g : g );
        c.b = b < 0 ? -b : ( b > 255 ? 510 - b : b );
        
    }
    
    return  c;
}
