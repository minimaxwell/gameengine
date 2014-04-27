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

    class ConstantSpeedScale : public ::ge::Scale {
    public:

        ConstantSpeedScale( double expansionSpeed );

        virtual ~ConstantSpeedScale();

        sf::Vector2f scale(unsigned long long elapsed);
        
        Scale * clone() const;
        
    private:

        double m_expansionSpeed;
        
    };

}
#endif	/* CONSTANTSPEEDSCALE_H */

