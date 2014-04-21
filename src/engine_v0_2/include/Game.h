/* 
 * File:   Game.h
 * Author: maxwell
 *
 * Created on 19 avril 2014, 17:43
 */

#ifndef GAME_H
#define	GAME_H
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "NonPlayer.h"
#include "Level.h"
#include <string>

namespace ge {

    struct GameParameters{
        unsigned int gameWidth;
        unsigned int gameHeight;
        std::string gameTitle;
        unsigned int joystick;
    };
    
    class Game {
    public:

        Game( Level * level );

        virtual ~Game();

        void render() const;
        
        void update(unsigned long long elapsed);
        
        void launch();
        
        void loop();
        
        static GameParameters parameters;
        
        static unsigned long long currentTimestamp;
        
        
    private:

        Player * m_player;
        
        bool m_playing;
        
        sf::RenderWindow * m_window;
        
        std::vector<NonPlayer *> m_entities;
        
        Level * m_level;
        
        std::vector<Sequence *> m_activeSequences;
        
        unsigned long long m_currentTimestamp;
        
    };

}
#endif	/* GAME_H */

