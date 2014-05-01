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
    
    std::vector<ge::Color> npColors;
    npColors.push_back( ge::Color::green );
    npColors.push_back( ge::Color::red );
    npColors.push_back( ge::Color::orange );
    
    ge::SynchronizedColorPulse::m_period = 1000000;
    ge::SynchronizedColorPulse::m_next = 1000000;
    ge::SynchronizedColorPulse::m_currentColorIndex = 0;
    ge::SynchronizedColorPulse::m_colors = npColors;
    //ge::Level * level = new ge::Level( new ge::StarBackground( sf::Vector2f( -200.f , 0.f ) , 1024 ) , colors );
    ge::Level * level = new ge::Level( new ge::KillLaKillBackground( 10 ) , colors );
        
    ge::Player * player = new ge::Player( level->playerColorPoll() , sf::Vector2f( ge::Game::parameters.gameWidth / 2 , ge::Game::parameters.gameHeight / 2 ) , 200.f );
    player->shape( new sf::CircleShape( 10 ) );
    
    level->player( player );
    
    ge::Movement * movement = new ge::Movement();
    ge::Transformation * t = new ge::Transformation( 10000000 );
    t->trajectory( new ge::LinearAimingTrajectory( player, 300.f ) );
    t->rotation( new ge::ConstantSpeedRotation( 180.f ) );
    //t->colorEffect( new ge::ColorPulse( colors, 1000000 ) );
    t->colorEffect( new ge::SynchronizedColorPulse(  ) );
    movement->addTransformation( 0, t );
    
    ge::NonPlayer * p =  new ge::RectangularNonPlayer( 10.f , 10.f , ge::eColor::RED        , 30 , new ge::Movement( *movement ), 10000000, sf::Vector2f( 1440 , 100 ) , player );
    ge::NonPlayer * p1 = new ge::RectangularNonPlayer( 12.f , 12.f , ge::eColor::RED       , 30 , new ge::Movement( *movement ), 10000000, sf::Vector2f( 1440 , 200 ) , player );
    ge::NonPlayer * p2 = new ge::RectangularNonPlayer(  9.f ,  9.f , ge::eColor::RED  , 30 , new ge::Movement( *movement ), 10000000, sf::Vector2f( 1440 , 300 ) , player );
    ge::NonPlayer * p3 = new ge::RectangularNonPlayer( 11.f , 11.f , ge::eColor::RED , 30 , new ge::Movement( *movement ), 10000000, sf::Vector2f( 1440 , 400 ) , player );
    ge::NonPlayer * p4 = new ge::RectangularNonPlayer( 16.f , 16.f , ge::eColor::RED      , 30 , new ge::Movement( *movement ), 10000000, sf::Vector2f( 1440 , 450 ) , player );
    ge::NonPlayer * p5 = new ge::RectangularNonPlayer( 10.f , 10.f , ge::eColor::RED        , 30 , new ge::Movement( *movement ), 10000000, sf::Vector2f( 1440 , 500 ) , player );
    ge::NonPlayer * p6 = new ge::RectangularNonPlayer( 12.f , 12.f , ge::eColor::RED      , 30 , new ge::Movement( *movement ), 10000000, sf::Vector2f( 1440 , 600 ) , player );
    ge::NonPlayer * p7 = new ge::RectangularNonPlayer( 10.f , 10.f , ge::eColor::RED         , 30 , new ge::Movement( *movement ), 10000000, sf::Vector2f( 1440 , 700 ) , player );
    ge::NonPlayer * p8 = new ge::RectangularNonPlayer(  8.f ,  8.f , ge::eColor::RED       , 30 , new ge::Movement( *movement ), 10000000, sf::Vector2f( 1440 , 800 ) , player );
    
    level->addSequence( 0 , new ge::SourceSequence( p->clone() , 100000 , -1 ) );
    level->addSequence( 1000000 , new ge::SourceSequence( p1->clone() , 1000000 , -1 ) );
    level->addSequence( 500000 , new ge::SourceSequence( p2->clone() , 200000 , -1 ) );
    level->addSequence( 2000000 , new ge::SourceSequence( p3->clone() , 100000 , -1 ) );
    level->addSequence( 2000000 , new ge::SourceSequence( p4->clone() , 300000 , -1 ) );
    level->addSequence( 2500000 , new ge::SourceSequence( p5->clone() , 300000 , -1 ) );
    level->addSequence( 3000000 , new ge::SourceSequence( p6->clone() , 500000 , -1 ) );
    level->addSequence( 3000000 , new ge::SourceSequence( p7->clone() , 600000 , -1 ) );
    level->addSequence( 3000000 , new ge::SourceSequence( p8->clone() , 400000 , -1 ) );
    level->addSequence( 3500000 , new ge::SourceSequence( p6->clone() , 500000 , 6 ) );
    level->addSequence( 3600000 , new ge::SourceSequence( p->clone() , 1000000 , 12 ) );
    level->addSequence( 3700000 , new ge::SourceSequence( p2->clone() , 400000 , 20 ) );
    level->addSequence( 4000000 , new ge::SourceSequence( p4->clone() , 400000 , 3 ) );
    level->addSequence( 5000000 , new ge::SourceSequence( p5->clone() , 400000 , 8 ) );
    level->addSequence( 5500000 , new ge::SourceSequence( p8->clone() , 1000000 , 15 ) );
    level->addSequence( 6000000 , new ge::SourceSequence( p2->clone() , 700000 , 15 ) );
    level->addSequence( 7000000 , new ge::SourceSequence( p3->clone() , 900000 , 3 ) );
    level->addSequence( 7500000 , new ge::SourceSequence( p5->clone() , 150000 , 6 ) );
    level->addSequence( 8000000 , new ge::SourceSequence( p7->clone() , 200000 , 9 ) );
    level->addSequence( 9000000 , new ge::SourceSequence( p6->clone() , 300000 , 18 ) );
    level->addSequence( 9500000 , new ge::SourceSequence( p4->clone() , 100000 , 10 ) );
    level->addSequence( 10000000 , new ge::SourceSequence( p3->clone() , 200000 , 2 ) );
    level->addSequence( 10000000 , new ge::SourceSequence( p2->clone() , 800000 , 8 ) );
    level->addSequence( 10000000 , new ge::SourceSequence( p->clone() , 1000000 , 9 ) );
    level->addSequence( 11000000 , new ge::SourceSequence( p8->clone() , 1500000 , 15 ) );
    level->addSequence( 12000000 , new ge::SourceSequence( p5->clone() , 1000000 , 3 ) );
    level->addSequence( 13000000 , new ge::SourceSequence( p3->clone() , 500000 , 7 ) );
    level->addSequence( 14000000 , new ge::SourceSequence( p4->clone() , 400000 , 5 ) );
    level->addSequence( 15000000 , new ge::SourceSequence( p7->clone() , 600000 , 8 ) );
    
    ge::Game game( level );
    game.launch();
        
    return 0;
}

