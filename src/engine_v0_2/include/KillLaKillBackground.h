/* 
 * File:   KillLaKillBackground.h
 * Author: maxwell
 *
 * Created on 24 avril 2014, 18:58
 */

#ifndef KILLLAKILLBACKGROUND_H
#define	KILLLAKILLBACKGROUND_H

#include "Background.h"

namespace ge {

    class KillLaKillBackground : public ::ge::Background{
    public:

        KillLaKillBackground( unsigned int nbLines );

        virtual ~KillLaKillBackground();

        void update(unsigned long long elapsed);
        
        void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
        
    private:        

        unsigned int m_nbLines;

        std::vector< sf::RectangleShape * > m_vertices;        
        std::vector< double > m_rotatingSpeeds;
        
    };

}
#endif	/* KILLLAKILLBACKGROUND_H */

