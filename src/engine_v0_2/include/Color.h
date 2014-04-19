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
        Color( eColor baseColor, int fuzz );

        Color(const Color& orig);

        virtual ~Color();

        static sf::Color createColor( eColor baseColor, int fuzz );
        
        eColor baseColor() const { return m_baseColor; }
        sf::Color color() const { return m_color; }
        
        Color& operator=(const Color& c){ m_color = c.m_color ; m_baseColor = c.m_baseColor ; return *this; }
        
        static const Color red;
        static const Color light_green;
        static const Color green;
        static const Color blue;
        static const Color light_blue;
        static const Color yellow;
        static const Color orange;
        static const Color purple;
        static const Color pink;
        static const Color white;
        
    private:


        
        sf::Color m_color;
        
        eColor m_baseColor;
        
    };

}
#endif	/* COLOR_H */

