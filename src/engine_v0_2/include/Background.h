/* 
 * File:   Background.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:03
 */

#ifndef BACKGROUND_H
#define	BACKGROUND_H

#include "SFML/Graphics.hpp"

namespace ge {

    class Background : public sf::Drawable, public sf::Transformable {
    public:

        Background();
        
        virtual ~Background();

        virtual void update(float elapsed) = 0;
        
        virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const = 0;
        
    private:

    };

}
#endif	/* BACKGROUND_H */

