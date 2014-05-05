/* 
 * File:   Ray.cpp
 * Author: maxwell
 * 
 * Created on 2 mai 2014, 17:12
 */

#include "Ray.h"
#include <math.h>

using namespace ge;

Ray::Ray( const sf::Vector2f& orig, double angle ,
          double rayWidth,
          double haloWidth, 
          const ge::Color& color ) :
          
         m_rayWidth( rayWidth ) , 
         m_haloWidth( haloWidth ) , 
         m_color( color ) , 
         m_angle( angle ){
    
    
    
}

Ray::Ray( const sf::Vector2f& orig, 
          const sf::Vector2f& target, 
          double rayWidth, 
          double haloWidth, 
          const ge::Color& color ) : 
          
          m_rayWidth( rayWidth ),
          m_haloWidth( haloWidth ),
          m_color( color ){
    
    // we compute the angle
    m_angle = atan( ( target.y - orig.y ) / ( target.x - orig.x ) );
    
}

Ray::~Ray() {
}

