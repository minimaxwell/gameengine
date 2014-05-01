/* 
 * File:   ColorPulse.h
 * Author: maxwell
 *
 * Created on 1 mai 2014, 13:15
 */

#ifndef COLORPULSE_H
#define	COLORPULSE_H

#include "ColorEffect.h"

namespace ge {

    class ColorPulse : public ::ge::ColorEffect {
    public:

        ColorPulse( std::vector<ge::Color> colors, unsigned long long period );

        ColorPulse( std::vector<ge::Color> colors, unsigned int currentIndex, unsigned long long currentTime, unsigned long long period, unsigned long long next );
        
        virtual ~ColorPulse();

        ge::Color color(unsigned long long elapsed, bool& changed);
        
        ColorEffect * clone() const;
        
    private:

        inline unsigned int incIndex();
        
        unsigned long long m_period;
        unsigned int m_currentColorIndex;
        unsigned long long m_currentTime;
        unsigned long long m_next;
        
        std::vector<ge::Color> m_colors;
    };

}
#endif	/* COLORPULSE_H */

