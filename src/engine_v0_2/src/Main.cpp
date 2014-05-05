/* 
 * File:   Main.cpp
 * Author: maxwell
 *
 * Created on 19 avril 2014, 16:25
 */

#include <cstdlib>
#include <time.h>
#include "Game.h"
#include "Level.h"
#include "Color.h"
#include "Player.h"
#include "StarBackground.h"
#include "KillLaKillBackground.h"
#include "TimelineSequence.h"
#include "SFML/Graphics.hpp"
#include "LinearTrajectory.h"
#include "LinearAimingTrajectory.h"
#include "RectangularNonPlayer.h"
#include "ConstantSpeedRotation.h"
#include "ConstantSpeedScale.h"
#include "SourceSequence.h"
#include "sfml/SFML-master/include/SFML/System/Vector2.hpp"
#include "ColorPulse.h"
#include "SynchronizedColorPulse.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    
    std::vector<ge::Color> colors;
    colors.push_back( ge::Color::green );
    colors.push_back( ge::Color::red );
    
   
    ge::Level * level = new ge::Level( new ge::KillLaKillBackground( 10 ) , colors );
    ge::Player * player = new ge::Player( level->playerColorPoll() , sf::Vector2f( ge::Game::parameters.gameWidth / 2 , ge::Game::parameters.gameHeight / 2 ) , 200.f );
    player->shape( new sf::CircleShape( 8 ) );
    
    level->player( player );

    

    
    ge::Game game( level );
    game.launch();
        
    return 0;
}

