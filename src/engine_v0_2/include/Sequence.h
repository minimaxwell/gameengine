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

        Sequence(const Sequence& orig);

        virtual ~Sequence();

        void start();
        
        bool hasNext() const;
        
        NonPlayer * next();
        
        bool ended() const;
        
        void addNonPlayer( unsigned long long timestamp , NonPlayer * player );
        
    private:

        bool m_started;
        
        unsigned long long m_startingTimestamp;
        
        std::multimap<unsigned long long, NonPlayer * > m_timeline;
        
    };

}
#endif	/* SEQUENCE_H */

