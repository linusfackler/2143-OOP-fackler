#pragma once

#include <SFML/Graphics.hpp>
#include "Debris.h"

class Player: public sf::Drawable
{
    private:
        sf::CircleShape *circle;
        float x;            // starting x
        float y;            // starting y
        int width;          // window width
        int height;         // window height
        int size;           // size of Player
        sf::Vector2f position;  // 2D Vector who can hold x & y value


        /**
         * Description:
         *      Honestly no idea what it does
         *      Is a constant
         * Params:
         *      sf::RenderTarget address
         *      sf::RenderStates states
         * 
         * Returns:
         *      Void, no return
         */
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const 
        {
            target.draw(*circle, states);
        }

    public:
        Player(int w, int h, int _size, int r, int g, int b)
        {       // default constructor
            width = w;      // window width
            height = h;     // window height
            x = 0;          // starting x
            y = height / 2; // starting y
            size = _size;   // size

            circle = new sf::CircleShape(size); 
                // new circle with size "size"

            circle->setFillColor(sf::Color(r, g, b));
                // set color for circle

            circle->setRadius(size);
                // set radius to "size"

            circle->setPointCount(100);
                // set PointCount to 100

            circle->setPosition(sf::Vector2f(x, y));
                // set position of circle to x & y value (row 39&40)                
        }


        /**
         * Description:
         *      Changes position of Player depending on key pressed
         *      Up -> up 50 pixels
         *      Down -> down 50 pixels
         * Params:
         *      Character "dir"
         * 
         * Returns:
         *      Void, no return
         */
        void changePos(char dir)
        {
            position = circle->getPosition();

            if (dir == 'u')
            {
                if (position.y < size) // if the distance to the border
                {                      // is less than 50, just puts to 0
                    circle->setPosition(sf::Vector2f(position.x, 0));
                    // even if y - 50 is less than 0, it puts it to 0
                    // so it's not half out of the window                    
                }

                else
                {
                    circle->setPosition(sf::Vector2f(position.x, position.y - 50));
                }
            }

            
            else if (dir == 'd')
                if (position.y > height - size*3)
                {                                 
                    circle->setPosition(sf::Vector2f(position.x, height - size*2));                    
                }       // incase it moves halfway out of the window
                else    // it still puts it right on the edge, so can't cheat ;)
                {
                    circle->setPosition(sf::Vector2f(position.x, position.y + 50));
                }
        }

        /**
         * Description:
         *      Returns Bounds to a rectangle
         * Params:
         *      No params
         * 
         * Returns:
         *      sf::FloatRect -> rectangle with
         *          size of the bounds of the circle
         */
        sf::FloatRect getBounds()
        {
            return circle->getGlobalBounds();
        }
};