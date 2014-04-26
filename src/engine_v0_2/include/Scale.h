/* 
 * File:   Scale.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:05
 */

#ifndef SCALE_H
#define	SCALE_H
#include "SFML/Graphics.hpp"
namespace ge {

    class NonPlayer;
    class Scale {
    public:

        Scale();

        virtual ~Scale();

        virtual sf::Vector2f scale(unsigned long long elapsed) = 0;
        
        virtual Scale * clone() const = 0;
        
        void nonPlayer( NonPlayer * nonPlayer );
        
    protected:

        NonPlayer * m_nonPlayer;
        
    };

}
#endif	/* SCALE_H */

