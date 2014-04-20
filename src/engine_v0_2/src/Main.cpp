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
#include "StarBackground.h"

#include "SFML/Graphics.hpp"
#include "LinearTrajectory.h"
#include "RectangularNonPlayer.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    
    std::vector<ge::Color> colors;
    colors.push_back( ge::Color::light_green );
    colors.push_back( ge::Color::pink );
    colors.push_back( ge::Color::yellow );
    
    ge::Level * level = new ge::Level( new ge::StarBackground( sf::Vector2f( -200.f , 0.f ) , 1024 ) , colors );
    
    ge::Movement * movement = new ge::Movement();
    ge::Transformation * t = new ge::Transformation( 1000 );
    t->trajectory( new ge::LinearTrajectory( sf::Vector2f( -400.f, 0.f ) ) );
    
    movement->addTransformation( 10.f, t );
    
    ge::NonPlayer * p = new ge::RectangularNonPlayer( 10.f , 10.f , ge::eColor::BLUE , 10 , movement, 10, sf::Vector2f( 1440 , 450 )  );
    
    ge::Sequence * s = new ge::Sequence();
    
    for(int i = 0 ; i < 10 ; i++){
        s->addNonPlayer( i * 200.f , p->clone() );
    }
    
    level->addSequence( 10.f , s );
    level->addSequence( 5000.f , new ge::Sequence(*s) );
    
    ge::Game game( level );
    game.launch();
        
    return 0;
}

