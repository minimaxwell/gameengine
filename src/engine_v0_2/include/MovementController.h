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
        
        virtual sf::Event::EventType handledEvent() const = 0;
        
        virtual bool pauseEvent(const sf::Event& event) const = 0;
        
        virtual bool useEvent(const sf::Event& event) const = 0;
        
        virtual bool selectEvent(const sf::Event& event) const = 0;
        
        virtual bool toggleColor(const sf::Event& event) const = 0;
        
        
    private:
        
    };

}
#endif	/* MOVEMENTCONTROLLER_H */

