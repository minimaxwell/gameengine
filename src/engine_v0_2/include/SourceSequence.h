/* 
 * File:   SourceSequence.h
 * Author: maxwell
 *
 * Created on 24 avril 2014, 23:12
 */

#ifndef SOURCESEQUENCE_H
#define	SOURCESEQUENCE_H

#include "Sequence.h"

namespace ge{

    class SourceSequence : public ::ge::Sequence {
    public:

        SourceSequence( NonPlayer * baseNonPlayer , unsigned long long delay , long nbElements);

        virtual ~SourceSequence();
        
        void update(unsigned long long elapsed) ;
        
        bool ended() const ;
        
        void addEntity( unsigned long long startingTimestamp,  NonPlayer * entity ) ;
        
        Sequence * clone() const ;
        
    private:

        long m_nbElements;
        long m_createdElements;
        
        unsigned long long m_nextElement;
        unsigned long long m_delay;
        
        NonPlayer * m_baseNonPlayer;
        
    };

}
#endif	/* SOURCESEQUENCE_H */

