/* 
 * File:   ConstantSpeedScale.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:07
 */

#ifndef CONSTANTSPEEDSCALE_H
#define	CONSTANTSPEEDSCALE_H

#include "Scale.h"

namespace ge {

    class ConstantSpeedScale : ::ge::Scale {
    public:

        ConstantSpeedScale( float expansionSpeed );

        virtual ~ConstantSpeedScale();

        sf::Vector2f scale(float elapsed);
        
        Scale * clone() const;
        
    private:

        float m_expansionSpeed;
        
    };

}
#endif	/* CONSTANTSPEEDSCALE_H */

