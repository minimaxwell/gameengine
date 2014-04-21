/* 
 * File:   StarBackground.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:04
 */

#ifndef STARBACKGROUND_H
#define	STARBACKGROUND_H

#include "Background.h"

#include <vector>

namespace ge {

    class StarBackground : public ::ge::Background {
    public:

        StarBackground( const sf::Vector2f& baseSpeed, unsigned int nbElements );

        virtual ~StarBackground();

        void update(unsigned long long elapsed);
        
        void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
        
        void baseSpeed( const sf::Vector2f& baseSpeed );
        
    private:

        sf::Vector2f m_baseSpeed;
        unsigned int m_nbElements;
        std::vector<int> m_depths;
        
        sf::VertexArray m_vertices;
    };

}
#endif	/* STARBACKGROUND_H */

