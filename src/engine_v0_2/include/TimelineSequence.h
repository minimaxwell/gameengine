/* 
 * File:   TimelineSequence.h
 * Author: maxwell
 *
 * Created on 23 avril 2014, 22:34
 */

#ifndef TIMELINESEQUENCE_H
#define	TIMELINESEQUENCE_H

#include "Sequence.h"

namespace ge {

    class TimelineSequence : public ::ge::Sequence{
    public:

        TimelineSequence();

        virtual ~TimelineSequence();

        virtual void update(unsigned long long elapsed);
        
        virtual bool ended() const;
        
        virtual void addEntity( unsigned long long startingTimestamp,  NonPlayer * entity );
        
        virtual Sequence * clone() const;
        
    private:

        std::multimap< unsigned long long , NonPlayer *> m_timeline;
    };

}
#endif	/* TIMELINESEQUENCE_H */

