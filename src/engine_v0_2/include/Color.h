/* 
 * File:   Color.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 15:47
 */

#ifndef COLOR_H
#define	COLOR_H
#include "SFML/Graphics.hpp"

namespace ge {

    enum eColor{
        RED = 0,
        LIGHT_GREEN,
        GREEN,
        BLUE,
        LIGHT_BLUE,
        YELLOW,
        ORANGE,
        PURPLE,
        PINK,
        WHITE
    };
    
    class Color {
    public:

        Color( const sf::Color color, eColor baseColor );

        Color(const Color& orig);

        virtual ~Color();

    private:

        sf::Color m_color;
        
        eColor m_baseColor;
        
    };

}
#endif	/* COLOR_H */

