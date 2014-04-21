/* 
 * File:   JoystickController.h
 * Author: maxwell
 *
 * Created on 20 avril 2014, 21:07
 */

#ifndef JOYSTICKCONTROLLER_H
#define	JOYSTICKCONTROLLER_H

#include "MovementController.h"

namespace ge {

    struct JoystickConfiguration{
        sf::Joystick::Axis x_axis;
        sf::Joystick::Axis y_axis;
        sf::Joystick::Axis speedUp;
        unsigned int speedUp_button;
        unsigned int pause;
        unsigned int select;
        unsigned int toggleColor;
        unsigned int use;
    };
    
    static const unsigned int NO_JOYSTICK = 9;
    
    static const JoystickConfiguration XBOX360_CONTROLLER_CONFIGURATION = { 
        sf::Joystick::X,
        sf::Joystick::Y,
        sf::Joystick::Z,
        0,0,0,0,0
    };
    
    class JoystickController : public ::ge::MovementController {
    public:

        JoystickController( unsigned int joystick );

        virtual ~JoystickController();
        
        sf::Vector2f move(unsigned long long elapsed) const;
        
        sf::Event::EventType handledEvent() const { return sf::Event::EventType::JoystickButtonPressed; }
        
        bool pauseEvent(const sf::Event& event) const;
        
        bool useEvent(const sf::Event& event) const;
        
        bool selectEvent(const sf::Event& event) const;
        
        bool toggleColor(const sf::Event& event) const;
        
        JoystickConfiguration configuration;
        
        float threshold;
        
    private:

        unsigned int m_joystick;
    };

}
#endif	/* JOYSTICKCONTROLLER_H */

