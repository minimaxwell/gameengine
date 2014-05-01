/* 
 * File:   ColorEffect.h
 * Author: maxwell
 *
 * Created on 1 mai 2014, 11:37
 */

#ifndef COLOREFFECT_H
#define	COLOREFFECT_H
#include "Color.h"
namespace ge {
    class NonPlayer;
    class ColorEffect {
    public:

        ColorEffect();

        virtual ~ColorEffect();
        
        virtual ge::Color color(unsigned long long elapsed, bool& changed) = 0;
        
        virtual ColorEffect * clone() const = 0;
        
        void nonPlayer( NonPlayer * nonPlayer );
        
    private:
        
        const NonPlayer * m_nonPlayer;
    };

}
#endif	/* COLOREFFECT_H */

