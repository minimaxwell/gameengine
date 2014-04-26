/* 
 * File:   LinearAimingTrajectory.h
 * Author: maxwell
 *
 * Created on 26 avril 2014, 22:18
 */

#ifndef LINEARAIMINGTRAJECTORY_H
#define	LINEARAIMINGTRAJECTORY_H

#include "Trajectory.h"
#include "Player.h"
#include "NonPlayer.h"
namespace ge {

    class LinearAimingTrajectory : public ::ge::Trajectory {
    public:

        LinearAimingTrajectory( const Player * const player, double speed );

        virtual ~LinearAimingTrajectory();

        sf::Vector2f movement(unsigned long long elapsed);
        
        Trajectory * clone() const;
                
    private:

        const Player * m_player;
        
        double m_speed;
        
        bool m_hasMoved;
        
        sf::Vector2f m_speedVector;
    };

}
#endif	/* LINEARAIMINGTRAJECTORY_H */

