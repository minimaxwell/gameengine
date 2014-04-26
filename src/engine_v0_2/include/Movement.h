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

    class NonPlayer;
    
    class Movement {
    public:

        Movement();

        Movement(const Movement& orig);

        virtual ~Movement();

        void update( unsigned long long elapsed, sf::Shape* shape );
                
        void addTransformation( unsigned long long departureTimestamp , Transformation * transformation );
        
        void start();
        
        void nonPlayer( NonPlayer * nonPlayer );
        
    private:

        std::multimap<unsigned long long , Transformation *> m_timeline;
        std::vector< Transformation * > m_activeTransformations ;
        
        unsigned long long m_elapsedTime;
        
        bool m_started;
        
        const NonPlayer * m_nonPlayer;
        
    };

}
#endif	/* MOVEMENT_H */

