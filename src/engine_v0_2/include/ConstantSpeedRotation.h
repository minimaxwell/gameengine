/* 
 * File:   ConstantSpeedRotation.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:07
 */

#ifndef CONSTANTSPEEDROTATION_H
#define	CONSTANTSPEEDROTATION_H

#include "Rotation.h"

namespace ge {

    class ConstantSpeedRotation : public ::ge::Rotation {
    public:

        ConstantSpeedRotation( double angularSpeed );

        virtual ~ConstantSpeedRotation();

        double rotation(unsigned long long elapsed);
        
        Rotation * clone() const;
        
    private:

        double m_angularSpeed;
        
    };

}
#endif	/* CONSTANTSPEEDROTATION_H */

