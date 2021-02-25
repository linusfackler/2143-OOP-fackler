#pragma once

#include "Player.h"
#include <SFML/Graphics.hpp>

class Debris: public sf::Drawable
{
    private:
        sf::RectangleShape *rect;
        float x;        // position y
        float y;        // position x
        float d;        // speed
        int width;      // window width
        int height;     // window size
        sf::Vector2f position;

        int sizex;    // Size of rectangle (hor)
        int sizey;    // Size of rectangle (vert)

        /**
         * Description:
         *      Honestly no idea what it does (part 2)
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
            target.draw(*rect, states);
        }

    public:
        Debris(int w, int h, int r, int g, int b, int ch)
        {
            width = w;          // window width
            height = h;         // window height
            x = width + ch;     // x starting position to window width
                                // ch is to make two objects don't start
                                // on the same spot
            y = (rand() % int(height-100));
                                // y starting position to random

            d = -0.2;           // starting speed is 0.2 left (-)

            sizex = (rand() % (width / 4) + 50);
                // size hor. debris random (min = 50; max = width/4)
            sizey = (rand() % (height / 2) + 100);
                // size vert. debris random (min = 100; max = width/2)

            rect = new sf::RectangleShape(sf::Vector2f(sizex, sizey));
                // pointer rect is new Rectangle shaped object
                // with sized sizex & sizey that we just randomly generated

            rect->setFillColor(sf::Color(r, g, b));
                // filler color to passed in rgb

            rect->setPosition(sf::Vector2f(x, y));
                // position to just declared x & y
        }


        /**
         * Description:
         *      Basic OOP get-method. Returns
         *      member variable "sizex" (height of Debris)
         * Params:
         *      No params
         * 
         * Returns:
         *      Int sizex
         */
        int getSizex()
        {
            return sizex;
        }

        /**
         * Description:
         *      Basic OOP get-method. Returns
         *      member variable "sizey" (width of Debris)
         * Params:
         *      No params
         * 
         * Returns:
         *      Int sizey
         */        
        int getSizey()
        {
            return sizey;            
        }


        /**
         * Description:
         *      Changes the speed of the Debris
         *      to passed in float
         * Params:
         *      Float de
         * 
         * Returns:
         *      Void, no return
         */
        void changeSpeed(float de)
        {
            d = de;
        }

        /**
         * Description:
         *      Basic OOP get-method. Returns
         *      member variable "d" (speed of Debris)
         * Params:
         *      No params
         * 
         * Returns:
         *      Int sizex
         */
        float getD()
        {
            float _d = d;
            return _d;
        }
 
        /**
         * Description:
         *      Updates the Debris' position
         * Params:
         *      No params
         * 
         * Returns:
         *      Void, no return
         */
        void update()
        {
            position = rect->getPosition();

            x = position.x + d;
            rect->setPosition(sf::Vector2f(x, y));
        }

        /**
         * Description:
         *      Returns member variable "x" (x value of Debris)
         * Params:
         *      No params
         * 
         * Returns:
         *      Float _x
         */
        float getX()
        {
            position = rect->getPosition();
            float _x = float(position.x);
            return _x;
        }

        /**
         * Description:
         *      Returns member variable "x" (x value of Debris)
         * Params:
         *      No params
         * 
         * Returns:
         *      Float _x
         */
        float getY()
        {
            position = rect->getPosition();
            float _y = float(position.y);
            return _y;
        }

        /**
         * Description:
         *      Returns the bounds of the Debris
         *      to FloatRect rectangle
         *      (to calculate collision later)
         * Params:
         *      No params
         * 
         * Returns:
         *      sf::FloatRect
         */
        sf::FloatRect getBounds()
        {  
            return rect->getGlobalBounds();
        }    
};