/* 
 * File:   SinusoidalTrajectory.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:06
 */

#ifndef SINUSOIDALTRAJECTORY_H
#define	SINUSOIDALTRAJECTORY_H

#include "Trajectory.h"

namespace ge {

    class SinusoidalTrajectory : public ::ge::Trajectory {
    public:

        SinusoidalTrajectory( double angularSpeed, const sf::Vector2f& baseDirection, double initAngle );

        virtual ~SinusoidalTrajectory();

        sf::Vector2f movement(unsigned long long elapsed);
        
        Trajectory * clone() const;
        
    private:

        double m_angularSpeed;
        sf::Vector2f m_baseDirection;
        double m_initAngle;
        double m_currentAngle;
        
    };

}
#endif	/* SINUSOIDALTRAJECTORY_H */

