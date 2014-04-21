/* 
 * File:   LinearTrajectory.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:05
 */

#ifndef LINEARTRAJECTORY_H
#define	LINEARTRAJECTORY_H

#include "Trajectory.h"

namespace ge {

    class LinearTrajectory : public ::ge::Trajectory {
    public:

        LinearTrajectory( const sf::Vector2f& speedVector ) ;

        virtual ~LinearTrajectory();

        sf::Vector2f movement(unsigned long long elapsed);
        
        Trajectory * clone() const;
        
    private:

        sf::Vector2f m_speedVector;
        
    };

}
#endif	/* LINEARTRAJECTORY_H */

