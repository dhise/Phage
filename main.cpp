#include <iostream>
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include <memory>







int main()
{



    // create the window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

    //simple player shape
    sf::RectangleShape player({ 120.f, 50.f });
    player.setFillColor(sf::Color(0, 255, 0));
    player.setPosition({ 200, 150 });



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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            {
                player.move({ 0.f, 1.0f });
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            {
                player.move({ 0.f, -1.0f });
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                player.move({ -1.f, 0.f });
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            {
                player.move({ 1.0f, 0.f });
            }
         
           
        }
        //clear the window with black
        window.clear(sf::Color::Black);
        
        window.draw(player);

        //End the current frame
        window.display();
        
    }
}