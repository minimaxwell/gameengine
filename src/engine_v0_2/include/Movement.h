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

        void movement(unsigned long long elapsed , sf::Shape * shape );
        
        void addTransformation( unsigned long long timestamp, Transformation * transformation );

        void start() ;
        
    private:

        std::multimap<unsigned long long, Transformation *> m_timeline;
        
        std::vector<Transformation *> m_currentTransformations;
        
        unsigned long long m_startingTime;
        
        bool m_started;
        
    };

}
#endif	/* MOVEMENT_H */

