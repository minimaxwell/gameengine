/* 
 * File:   RectangularNonPlayer.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:02
 */

#ifndef RECTANGULARNONPLAYER_H
#define	RECTANGULARNONPLAYER_H

#include "NonPlayer.h"

namespace ge {

    class RectangularNonPlayer : public ::ge::NonPlayer {
    public:

        RectangularNonPlayer( float width, float height, eColor baseColor, int fuzz,Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition, Player * player );
        RectangularNonPlayer( float width, float height, const ge::Color& color,Movement * movement, unsigned long long lifetime, const sf::Vector2f& initPosition, Player * player );

        virtual ~RectangularNonPlayer();

        NonPlayer * clone() const;
        
    private:

        float m_width;
        
        float m_height;
        
    };

}
#endif	/* RECTANGULARNONPLAYER_H */

