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
#include "Player.h"

namespace ge {

    class Level {
    public:

        Level( Background * background, std::vector<ge::Color> playerColorPoll );

        Level(const Level& orig);

        virtual ~Level();

        void addSequence( unsigned long long timestamp, Sequence * sequence );
                
        bool hasEnded() const;
        
        void start();
        
        std::vector<ge::Color> playerColorPoll() const { return m_playerColorPoll; }
        
        Background * m_background;

        void draw( sf::RenderTarget * target ) const;
        
        void update( unsigned long long elapsed );
        
        Player * player();
        
        void player( Player * player );
        
    private:

        
        std::multimap<unsigned long long, Sequence *> m_timeline;
        
        std::vector< Sequence * > m_activeSequences;
        
        std::vector<ge::Color> m_playerColorPoll;
        
        unsigned long long m_elapsedTime;
        
        bool m_started;
        
        Player * m_player;
        
    };

}
#endif	/* LEVEL_H */

