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
#include "KillLaKillBackground.h"
#include "TimelineSequence.h"
#include "SFML/Graphics.hpp"
#include "LinearTrajectory.h"
#include "RectangularNonPlayer.h"
#include "SourceSequence.h"

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
    
    //ge::Level * level = new ge::Level( new ge::StarBackground( sf::Vector2f( -200.f , 0.f ) , 1024 ) , colors );
    ge::Level * level = new ge::Level( new ge::KillLaKillBackground( 9 ) , colors );
    
    ge::Movement * movement = new ge::Movement();
    ge::Transformation * t = new ge::Transformation( 10000000 );
    t->trajectory( new ge::LinearTrajectory( sf::Vector2f( -400.f, 0.f ) ) );
    
    movement->addTransformation( 0, t );
    
    ge::NonPlayer * p = new ge::RectangularNonPlayer( 10.f , 10.f , ge::eColor::BLUE , 10 , movement, 10000000, sf::Vector2f( 1440 , 450 )  );
    
    ge::Sequence * s = new ge::TimelineSequence();
    
    for(int i = 0 ; i < 10 ; i++){
        s->addEntity( i * 200000 , p->clone() );
    }
    
    level->addSequence( 0 , s );
    level->addSequence( 5000000 ,s->clone() );
    
    ge::Movement * complexMovement = new ge::Movement();
    
    
    ge::Transformation * t2 = new ge::Transformation( 2000000 );
    t2->trajectory( new ge::LinearTrajectory( sf::Vector2f( -200.f, 0.f ) ) );
    
    ge::Transformation * t3 = new ge::Transformation( 3000000 );
    t3->trajectory( new ge::LinearTrajectory( sf::Vector2f( 0.f , 200.f ) ) );
    
    ge::Transformation * t4 = new ge::Transformation( 10000000 );
    t4->trajectory( new ge::LinearTrajectory( sf::Vector2f( -200.f, 0.f ) ) );
    
    complexMovement->addTransformation( 0 , t2 );
    complexMovement->addTransformation( 1000000 , t3 );
    complexMovement->addTransformation( 4000000 , t4 );
    
    ge::NonPlayer * p2 = new ge::RectangularNonPlayer( 10.f , 10.f , ge::eColor::ORANGE , 10 , complexMovement, 15000000, sf::Vector2f( 1440 , 200 )  );

    ge::Sequence * s2 = new ge::TimelineSequence();
    
    s2->addEntity(0 ,p2 );
    s2->addEntity(200000 ,p2->clone() );
    s2->addEntity(400000 ,p2->clone() );
    s2->addEntity(600000 ,p2->clone() );
    s2->addEntity(800000 ,p2->clone() );
    
    level->addSequence(0, s2);
    level->addSequence(5000000, s2->clone());
    
    ge::NonPlayer * p3 = new ge::RectangularNonPlayer( 10.f , 10.f , ge::eColor::PINK , 10 , new ge::Movement( *complexMovement ), 15000000, sf::Vector2f( 1440 , 250 )  );
    
    ge::SourceSequence * s3 = new ge::SourceSequence( p3 , 100000 , -1 );
    
    level->addSequence( 1000000 , s3 );
    ge::Game game( level );
    game.launch();
        
    return 0;
}

