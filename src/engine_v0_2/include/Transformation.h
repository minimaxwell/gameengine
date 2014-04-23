/* 
 * File:   Transformation.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:04
 */

#ifndef TRANSFORMATION_H
#define	TRANSFORMATION_H

#include"Trajectory.h"
#include"Rotation.h"
#include"Scale.h"

namespace ge {

    struct TransformationComponent{
        sf::Vector2f translation;
        double rotation;
        sf::Vector2f scale;
    };
    
    class Transformation {
    public:

        Transformation( unsigned long long lifetime );

        Transformation(const Transformation& orig);

        virtual ~Transformation();

        TransformationComponent transform(unsigned long long elapsed);
        
        void start();
        
        bool hasEnded() const;
        
        void trajectory( Trajectory * trajectory );
        void rotation( Rotation * rotation );
        void scale( Scale * scale);
        
        unsigned long long lifetime() const;
    private:

        Trajectory * m_trajectory;
        Rotation * m_rotation;
        Scale * m_scale;
        
        unsigned long long m_lifetime;
        bool m_started;
        bool m_ended;
      
        unsigned long long m_aliveTime;
        
    };

}
#endif	/* TRANSFORMATION_H */

