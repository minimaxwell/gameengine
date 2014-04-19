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
    ge::Game game( level );
    game.launch();
        
    return 0;
}

