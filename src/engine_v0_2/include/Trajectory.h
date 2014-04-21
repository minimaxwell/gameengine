/* 
 * File:   Trajectory.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:05
 */

#ifndef TRAJECTORY_H
#define	TRAJECTORY_H

#include "SFML/Graphics.hpp"

namespace ge {

    class Trajectory {
    public:

        Trajectory();

        virtual ~Trajectory();

        virtual sf::Vector2f movement(unsigned long long elapsed) = 0;
        
        virtual Trajectory * clone() const = 0;
        
    private:

    };

}
#endif	/* TRAJECTORY_H */

