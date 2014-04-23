/* 
 * File:   Sequence.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:03
 */

#ifndef SEQUENCE_H
#define	SEQUENCE_H

#include<map>
#include"NonPlayer.h"

namespace ge {

    class Sequence {
    public:

        Sequence();
        
        virtual ~Sequence();

        virtual void update(unsigned long long elapsed) = 0;
        
        void draw( sf::RenderTarget * target ) const;
        
        void start();
        
        virtual bool ended() const = 0;
        
        virtual void addEntity( unsigned long long startingTimestamp,  NonPlayer * entity ) = 0;
        
        virtual Sequence * clone() const = 0;
        
    protected:

        std::vector< NonPlayer * > m_activeEntities;
        
        unsigned long long m_elapsedTime;
        
        bool m_started;
    };

}
#endif	/* SEQUENCE_H */

