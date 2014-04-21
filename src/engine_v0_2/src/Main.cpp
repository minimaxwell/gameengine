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
    colors.push_back( ge::Color::green );
    colors.push_back( ge::Color::purple );
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
    
    ge::Movement * complexMovement = new ge::Movement();
    
    
    ge::Transformation * t2 = new ge::Transformation( 2 );
    t2->trajectory( new ge::LinearTrajectory( sf::Vector2f( -200.f, 0.f ) ) );
    
    ge::Transformation * t3 = new ge::Transformation( 3 );
    t3->trajectory( new ge::LinearTrajectory( sf::Vector2f( 0.f , 200.f ) ) );
    
    ge::Transformation * t4 = new ge::Transformation( 10 );
    t4->trajectory( new ge::LinearTrajectory( sf::Vector2f( -200.f, 0.f ) ) );
    
    complexMovement->addTransformation( 0 , t2 );
    complexMovement->addTransformation( 1000 , t3 );
    complexMovement->addTransformation( 4000 , t4 );
    
    ge::NonPlayer * p2 = new ge::RectangularNonPlayer( 10.f , 10.f , ge::eColor::ORANGE , 10 , complexMovement, 15, sf::Vector2f( 1440 , 200 )  );

    ge::Sequence * s2 = new ge::Sequence();
    
    s2->addNonPlayer(0 ,p2 );
    s2->addNonPlayer(200 ,p2->clone() );
    s2->addNonPlayer(400 ,p2->clone() );
    s2->addNonPlayer(600 ,p2->clone() );
    s2->addNonPlayer(800 ,p2->clone() );
    
    level->addSequence(500.f, s2);
    level->addSequence(5000.f, new ge::Sequence( *s2 ));
    
    ge::Game game( level );
    game.launch();
        
    return 0;
}

