#include "Debris.h"
#include "Player.h"
#include "Scoring.h"

#include <windows.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    int window_width = 768;         // window width
    int window_height = 768;        // window height

    sf::RenderWindow window(sf::VideoMode(window_width,window_height), "Flappy Bird from wish.com");
    // window gets rendered

    sf::Sprite  spriteBg1;          // creating an SFML sprite variable
    sf::Sprite  spriteBg2;          // for our scrolling backgrounf
    sf::Texture background;         // creating an SFML texture for our background

    sf::Sprite pulp1;               // creating sprite element for game over message
    sf::Sprite pulp2;
    sf::Texture pulp1T;             // creating texture for game over message
    sf::Texture pulp2T;

    sf::Font mario;                 // creating an SFML font variable

    if (!mario.loadFromFile("./fonts/SuperMario256.ttf"))
    {
        std::cout << "Can't load file!" << std::endl;
    }   // if the font can't load, it displays an error message in the console

    if (!pulp1T.loadFromFile("./images/pulp1.png"))
    {
        std::cout << "Error loading texture...(Pulp1)" << std::endl;
    }   // if the texture can't load, it displays an error message in the console

    if (!pulp2T.loadFromFile("./images/pulp2.png"))
    {
        std::cout << "Error loading texture...(Pulp2)" << std::endl;
    }   // if the texture can't load, it displays an error message in the console


    pulp1.setTexture(pulp1T);           // setting texture for game over message
    pulp2.setTexture(pulp2T);

    pulp1.setScale(.4,.4);              // scaling size of texture
    pulp2.setScale(.4,.4);

    pulp1.setPosition(window_width/10, window_height/3);        // setting position
    pulp2.setPosition(window_width/10, window_height/3);        // of texture

    sf::Text scoreText;                 // creating an SFML text variable for score count
    sf::Text gameOver;                  // creating game over text

    gameOver.setFont(mario);            // setting font for game over message
    gameOver.setCharacterSize(50);      // setting char size
    gameOver.setPosition(window_width/7, window_height/2);  // setting position
    gameOver.setString("Game Over noob");  // setting string message

    Scoring scores;                     // creating object "scores" from class "Scoring"

    scoreText.setFont(mario);           // setting the font "mario" to score text
    scoreText.setCharacterSize(50);     // setting char size for score text

    if (background.loadFromFile("./images/scroll_bg.png"))
    {
        spriteBg1.setTexture(background);
        spriteBg1.setPosition(0, 0);
        spriteBg2.setTexture(background);
        spriteBg2.setPosition(0, 0);
    } // if image is loading, texture and positions are set for scrolling bg

    else
        std::cout << "Error loading texture..." << std::endl;
        // if the texture can't load, it displays an error message in the console


    float x1 = 0.0;
    float y1 = 0.0;
    float x2 = 2040.0;
    float y2 = 0.0;
    int bg_flag = 0;

    Player *bird = new Player(window_width, window_height, 50, 255, 255, 0);
        // creating object as pointer "bird" from class "Player"
        // window sizes passed in
        // size of Player is 50, rgb are 255, 255, 0 (yellow)


    Debris **Darray = new Debris *[50];
        // creating array pointer object "Darray" from class "Debris"

    Debris **Zarray = new Debris *[50];
        // second array pointer object "Zarry" (Z for zecond) from class "Debris"

    Debris **Yarray = new Debris *[50];
        // thrid array pointer object "Yarry" (Y for thYrd) from class "Debris"



    int i = 0;      // local counter variables for different Debris
    int z = 1;
    int y = 1;
    int l = 1;

    Darray[i] = new Debris(window_width, window_height, 0, 145, 51, 0);
        // first Debris object gets created before window is opened
        // because the rest are created once the one before goes out
        // of bounds or gets hit
    Zarray[z] = new Debris(window_width, window_height, 0, 145, 51, 1000);

    Yarray[y] = new Debris(window_width, window_height, 0, 145, 51, 10000);


    std::string points;
        // string for our point counter






    while (window.isOpen())
    {
        sf::Event event;
            // SFML Event "event" gets created

        sf::FloatRect rec1 = bird->getBounds();
            // creating Rectangle to size of bounds of Player
        sf::FloatRect rec2 = Darray[i]->getBounds();
            // creating Rectangle to size of bounds of Debris

        sf::FloatRect rec3 = Zarray[z] ->getBounds();

        sf::FloatRect rec4 = Yarray[y] ->getBounds();

        points = "Score : " + std::to_string(scores.getScore());
            // setting string for scoreboard with actual score
        scoreText.setString(points);
            // SMFL text "scoreText" set to string "points"


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();   // if user closes window, window will be closed

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {   
                    case (sf::Keyboard::Up):
                        bird->changePos('u'); break;
                        // if key UP is pressed, function changePos for 'u' exec.

                    case (sf::Keyboard::Down):
                        bird->changePos('d'); break;  
                        // if key DOWN is pressed, function changePos for 'd' exec.

                        // room for more controls in future   

                    default: break; // if different key is pressed, nothing happens
                }
            }                     
        }


        spriteBg1.setPosition(x1, y1);
        spriteBg2.setPosition(x2, y2);
            // positions for background changes constantly
            // so it's moving slowly

        x1 -= .075;
        x2 -= .075;

        if (x1 <= -2040) {
            x1 = 768;
        }

        if (x2 <= -2040) {
            x2 = 768;
        }

        if (rec1.intersects(rec2))
        {         // if 2 floating rectangles (Player & Debris) intersect
            i++;  // counter gets incremented
            Darray[i] = new Debris(window_width, window_height, 0, 145, 51, 0);
                  // next Debris gets created

            scores.minusScore();
                  // Player loses 1 point
        }

        if (rec1.intersects(rec3))
        {         // if 2 floating rectangles (Player & Debris) intersect
            z++;    // counter gets incremented

            Zarray[z] = new Debris(window_width, window_height, 0, 145, 51, 0);
                  // next Debris gets created

            scores.minusScore();
                  // Player loses 1 point
        }

        if (rec1.intersects(rec4))
        {         // if 2 floating rectangles (Player & Debris) intersect
            y++;    // counter gets incremented
            Yarray[y] = new Debris(window_width, window_height, 0, 145, 51, 0);
                  // next Debris gets created

            scores.minusScore();
                  // Player loses 1 point
        }




        if (Darray[i]->getX() <= -(Darray[i]->getSizex()))
        {         // if Debris leaves the window on the left side

            i++;  // counter cets incremented
            Darray[i] = new Debris(window_width, window_height, 0, 145, 51, 0);
                  // next Debris gets created

            scores.plusScore();
                  // Player gains 1 point
        }

        if (Zarray[z]->getX() <= -(Zarray[z]->getSizex()))
        {         // if Debris leaves the window on the left side
            
            z++;  // counter cets incremented

            Zarray[z] = new Debris(window_width, window_height, 0, 145, 51, 0);
                  // next Debris gets created

            scores.plusScore();
                  // Player gains 1 point
        }

        if (Yarray[y]->getX() <= -(Yarray[y]->getSizex()))
        {         // if Debris leaves the window on the left side
            
            y++;  // counter cets incremented

            Yarray[y] = new Debris(window_width, window_height, 0, 145, 51, 0);
                  // next Debris gets created

            scores.plusScore();
                  // Player gains 1 point
        }




        Darray[i]->update();        // Debris positions gets updated constantly
        Zarray[z]->update();
        Yarray[y]->update();
        Zarray[z]->changeSpeed(-0.2f - (i * 0.025));
        Darray[i]->changeSpeed(-0.2f - (i * 0.025));
        Yarray[y]->changeSpeed(-0.2f - (i * 0.025));

        window.clear();             // window gets cleared
        window.draw(spriteBg1);     // moving bg gets drawn
        window.draw(spriteBg2);
        window.draw(scoreText);     // text gets drawn
        window.draw(*Darray[i]);    // Debris number i gets drawn
        window.draw(*Zarray[z]);    // Debris number z gets drawn
        window.draw(*Yarray[y]);    // Debris number y gets drawn
        window.draw(*bird);         // bird (Player) gets drawn
    
        if (scores.getScore() < 0)  // if score hits -1
        {
            window.draw(pulp1);     // message 1 gets drawn
            window.display();       // window displays
            Sleep(1000);            // program waits so player gets humiliated
            window.draw(pulp2);     // message 2 gets drawn
            window.display();       // window displays
            Sleep(1000);            // program waits more so player
                                    // gets even more humiliated

            window.draw(gameOver);  // game over text gets drawn
            window.display();       // window displays
            Sleep(1000);            // at this point the player needs
                                    // a new screen
            window.close();         // window closes since game is over
        }
        window.display();           // window displays and while starts

    }

    return 0;
}
