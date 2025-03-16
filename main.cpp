#include <iostream>
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <memory>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
            {
                // close window when Q is pressed
                window.close();
            }
           
        }
        //clear the window with black
        window.clear(sf::Color::Black);
        
        //window.draw();

        //End the current frame
        window.display();
        
    }
}