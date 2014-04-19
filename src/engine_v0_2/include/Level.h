/* 
 * File:   Level.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 18:03
 */

#ifndef LEVEL_H
#define	LEVEL_H

#include "Sequence.h"
#include "Background.h"
#include "Color.h"

namespace ge {

    class Level {
    public:

        Level( Background * background, std::vector<ge::Color> playerColorPoll );

        Level(const Level& orig);

        virtual ~Level();

        void addSequence( int timestamp, Sequence * sequence );
        
        Sequence * next();
        
        bool hasNext() const;
        
        bool hasEnded() const;
        
        void start();
        
        std::vector<ge::Color> playerColorPoll() const { return m_playerColorPoll; }
        
        Background * m_background;

        
    private:

        
        std::multimap<int, Sequence *> m_timeline;
        
        std::vector<ge::Color> m_playerColorPoll;
        
        bool m_started;
        
        sf::Clock m_clock;
    };

}
#endif	/* LEVEL_H */

