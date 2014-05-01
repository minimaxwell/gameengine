/* 
 * File:   NonPlayer.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 17:49
 */

#ifndef NONPLAYER_H
#define	NONPLAYER_H

#include "Color.h"
#include "Movement.h"
#include "Player.h"
namespace ge {

    class NonPlayer {
    public:

        NonPlayer( sf::Shape * shape, eColor baseColor, int fuzz, Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition, Player * player );
        NonPlayer( sf::Shape * shape, ge::Color color, Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition, Player * player );

        virtual ~NonPlayer();

        virtual NonPlayer * clone() const = 0;
        
        void update(unsigned long long elapsed);
        
        bool canBeDestroyed() const;
        
        void start();
        
        sf::Shape * shape() const;
        
        void player(  Player *  player );
        
        ge::Color color() const;
        
        void color( const ge::Color& color );
    protected:

        sf::Shape * m_shape;
        
        ge::Color m_color;
        
        int m_fuzz;
        
        Movement * m_movement;
        
        unsigned long long m_lifetime;
        
        unsigned long long m_currTime;
        
        sf::Vector2f m_initPosition;
        
        Player * m_player;
    };

}
#endif	/* NONPLAYER_H */

