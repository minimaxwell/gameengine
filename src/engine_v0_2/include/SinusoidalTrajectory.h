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

        SinusoidalTrajectory( float angularSpeed, const sf::Vector2f& baseDirection, float initAngle );

        virtual ~SinusoidalTrajectory();

        sf::Vector2f movement(float elapsed);
        
        Trajectory * clone() const;
        
    private:

        float m_angularSpeed;
        sf::Vector2f m_baseDirection;
        float m_initAngle;
        float m_currentAngle;
        
    };

}
#endif	/* SINUSOIDALTRAJECTORY_H */

