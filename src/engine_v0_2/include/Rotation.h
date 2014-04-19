/* 
 * File:   Rotation.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:05
 */

#ifndef ROTATION_H
#define	ROTATION_H

namespace ge {

    class Rotation {
    public:

        Rotation();

        virtual ~Rotation();

        virtual float rotation(float elapsed) = 0;
        
        virtual Rotation * clone() const = 0;
        
    private:

    };

}
#endif	/* ROTATION_H */

