/* 
 * File:   Rotation.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:05
 */

#ifndef ROTATION_H
#define	ROTATION_H

namespace ge {

    class NonPlayer;
    class Rotation {
    public:

        Rotation();

        virtual ~Rotation();

        virtual double rotation(unsigned long long elapsed) = 0;
        
        virtual Rotation * clone() const = 0;
        
        void nonPlayer( NonPlayer * nonPlayer );
        
    protected:

        const NonPlayer * m_nonPlayer;
        
    };

}
#endif	/* ROTATION_H */

