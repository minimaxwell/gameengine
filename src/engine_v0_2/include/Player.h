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
#include "MovementController.h"
#include <vector>

namespace ge {

    class Player {
    public:

        Player( const std::vector<ge::Color>& colorPoll, const sf::Vector2f& initPosition , double baseSpeed);

        virtual ~Player();

        void update( unsigned long long elapsed );
        
        void toggleColor();
        
        bool collidesWith( const sf::Shape& shape ) const;
        
        const sf::Shape * shape() const;
        
        void shape( sf::Shape * shape );
        
        void movementController( MovementController * movementController );
        
        MovementController * movementController() const;
        
        sf::Vector2f position() const {return m_position;}
    private:

        sf::Shape * m_shape;
        
        unsigned int m_currentColorIndex;
        
        std::vector<ge::Color> m_colorPoll;
        
        sf::Vector2f m_position;
        
        double m_baseSpeed;
        
        MovementController * m_movementController;
        
    };

}
#endif	/* PLAYER_H */

