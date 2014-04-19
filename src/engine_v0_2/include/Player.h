/* 
 * File:   Player.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 16:47
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "SFML/Graphics.hpp"
#include "Color.h"
#include <vector>

namespace ge {

    class Player {
    public:

        Player( const std::vector<ge::Color>& colorPoll, const sf::Vector2f& initPosition , float baseSpeed);

        virtual ~Player();

        void update( float elapsed );
        
        void toggleColor();
        
        bool collidesWith( const sf::Shape& shape ) const;
        
        const sf::Shape * shape() const;
        
        void shape( sf::Shape * shape );
        
    private:

        sf::Shape * m_shape;
        
        unsigned int m_currentColorIndex;
        
        std::vector<ge::Color> m_colorPoll;
        
        sf::Vector2f m_position;
        
        float m_baseSpeed;
        
    };

}
#endif	/* PLAYER_H */

