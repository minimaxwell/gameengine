/* 
 * File:   NonPlayer.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 17:49
 */

#ifndef NONPLAYER_H
#define	NONPLAYER_H

#include "Movement.h"
#include "Color.h"

namespace ge {

    class NonPlayer {
    public:

        NonPlayer( sf::Shape * shape, eColor baseColor, int fuzz, Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition );
        NonPlayer( sf::Shape * shape, ge::Color color, Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition );

        virtual ~NonPlayer();

        virtual NonPlayer * clone() const = 0;
        
        void update(unsigned long long elapsed);
        
        bool canBeDestroyed() const;
        
        void start();
        
        sf::Shape * shape() const;
        
    protected:

        sf::Shape * m_shape;
        
        ge::Color m_color;
        
        Movement * m_movement;
        
        unsigned long long m_lifetime;
        
        unsigned long long m_currTime;
        
        sf::Vector2f m_initPosition;
        
    };

}
#endif	/* NONPLAYER_H */

