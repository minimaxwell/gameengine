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
        float rotation;
        sf::Vector2f scale;
    };
    
    class Transformation {
    public:

        Transformation( float lifetime );

        Transformation(const Transformation& orig);

        virtual ~Transformation();

        TransformationComponent transform(float elapsed);
        
        void start();
        
        bool hasEnded() const;
        
        void trajectory( Trajectory * trajectory );
        void rotation( Rotation * rotation );
        void scale( Scale * scale);
        
    private:

        Trajectory * m_trajectory;
        Rotation * m_rotation;
        Scale * m_scale;
        
        float m_lifetime;
        sf::Clock m_clock;
        
        bool m_started;
        
    };

}
#endif	/* TRANSFORMATION_H */

