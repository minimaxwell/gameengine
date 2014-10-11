/* 
 * File:   Ray.h
 * Author: maxwell
 *
 * Created on 2 mai 2014, 17:12
 */

#ifndef RAY_H
#define	RAY_H
#include"SFML/Graphics.hpp"
#include "Color.h"

namespace ge {

    
    class Ray {
    public:
        
        Ray( const sf::Vector2f& orig, double angle , double rayWidth, double haloWidth, const ge::Color& color );
        Ray( const sf::Vector2f& orig, const sf::Vector2f& target, double rayWidth, double haloWidth, const ge::Color& color );

        virtual ~Ray();

        void draw( sf::RenderTarget& target, sf::RenderStates states ) const;
        
        void transform( const Transformation * transformation );
        
        void attach( const NonPlayer * nonPlayer );
        void attach( const Player * Player );
        
        
        void follow( const NonPlayer * nonPlayer );
        void follow( const Player * Player );
        
        
    private:

        union AttachementEntity{
            NonPlayer * nonPlayer;
            Player * player;
        };
        
        inline void buildRayVertices();
        
        double m_length;
        double m_rayWidth;
        double m_haloWidth;
        
        ge::Color m_color;
        
        double m_angle;
    
        sf::VertexArray m_vertices;
        
        union AttachementEntity m_attachement;
        union AttachementEntity m_following;
    };

}
#endif	/* RAY_H */

