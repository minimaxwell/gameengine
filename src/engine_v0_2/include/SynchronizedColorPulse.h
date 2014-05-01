/* 
 * File:   SynchronizedColorPulse.h
 * Author: maxwell
 *
 * Created on 1 mai 2014, 13:54
 */

#ifndef SYNCHRONIZEDCOLORPULSE_H
#define	SYNCHRONIZEDCOLORPULSE_H
#include "ColorEffect.h"
namespace ge {

    class SynchronizedColorPulse : public ::ge::ColorEffect{
    public:

        SynchronizedColorPulse();

        virtual ~SynchronizedColorPulse();

        ge::Color color(unsigned long long elapsed, bool& changed);
        
        ColorEffect * clone() const;
    
        static unsigned int incIndex();
        
        static unsigned long long m_period;
        static unsigned long long m_next;
        static unsigned int m_currentColorIndex;
        static std::vector<ge::Color> m_colors;
        
    };

}
#endif	/* SYNCHRONIZEDCOLORPULSE_H */

