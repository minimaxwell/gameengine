/* 
 * File:   Movement.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:04
 */

#ifndef MOVEMENT_H
#define	MOVEMENT_H

#include "Transformation.h"
#include <map>

namespace ge {

    class Movement {
    public:

        Movement();

        Movement(const Movement& orig);

        virtual ~Movement();

        sf::Transform movement(float elapsed);
        
        void addTransformation( int timestamp, Transformation * transformation );

        void start() ;
        
    private:

        std::multimap<int, Transformation *> m_timeline;
        
        std::vector<Transformation *> m_currentTransformations;
        
        sf::Clock m_clock;
        
        bool m_started;
        
    };

}
#endif	/* MOVEMENT_H */

