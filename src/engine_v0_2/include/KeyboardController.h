/* 
 * File:   KeyboardController.h
 * Author: maxwell
 *
 * Created on 20 avril 2014, 20:03
 */

#ifndef KEYBOARDCONTROLLER_H
#define	KEYBOARDCONTROLLER_H

#include "MovementController.h"

namespace ge {

    struct KeyboardConfiguration{
        sf::Keyboard::Key y_neg;
        sf::Keyboard::Key y_pos;
        sf::Keyboard::Key x_neg;
        sf::Keyboard::Key x_pos;
        sf::Keyboard::Key speedUp;
        sf::Keyboard::Key pause;
        sf::Keyboard::Key select;
        sf::Keyboard::Key toggleColor;
        sf::Keyboard::Key use;
    };
    
    class KeyboardController : public ::ge::MovementController {
    public:

        KeyboardController();

        virtual ~KeyboardController();
        
        sf::Vector2f move(float elapsed) const;
            
        KeyboardConfiguration configuration;
        
    private:

    };

}
#endif	/* KEYBOARDCONTROLLER_H */

