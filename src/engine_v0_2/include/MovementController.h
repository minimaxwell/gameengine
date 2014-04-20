/* 
 * File:   MovementController.h
 * Author: maxwell
 *
 * Created on 20 avril 2014, 20:00
 */

#ifndef MOVEMENTCONTROLLER_H
#define	MOVEMENTCONTROLLER_H
#include "SFML/Graphics.hpp"
namespace ge {

    class MovementController {
    public:

        MovementController();

        virtual ~MovementController();

        virtual sf::Vector2f move(float elapsed) const = 0;
        
    private:
        
    };

}
#endif	/* MOVEMENTCONTROLLER_H */

