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
#include <string>

namespace ge {

    struct GameParameters{
        unsigned int gameHeight;
        unsigned int gameWidth;
        std::string gameTitle;
        unsigned int joystick;
    };
    
    class Game {
    public:

        Game();

        Game(const Game& orig);

        virtual ~Game();

        void render() const;
        
        void update(float elapsed);
        
        void launch();
        
        void loop();
        
        static GameParameters parameters;
        
    private:

        Player * m_player;
        
        bool m_playing;
        
        sf::RenderWindow * m_window;
        
        std::vector<NonPlayer *> m_entities;
        
    };

}
#endif	/* GAME_H */
