#include <iostream>
#include <SFML/Graphics.hpp>
#include <typeinfo>








int main()
{



    // create the window
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

    // simple player shape
    sf::RectangleShape player({ 120.f, 50.f });
    player.setFillColor(sf::Color(0, 255, 0));
    player.setPosition({ 400, 500 });
    
    // get local mouse position relative to window
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    // prepare a font 
    sf::Font font;
    //Load the font from file if fails it closes game
    if (!font.openFromFile("WAD/fonts/player/BabyCell.ttf"))
    {
        std::cout << "**************Failed to load player font closing game*********************";
        return -1;
    }
    
    //Create clock object
    sf::Clock clock;
    
    //Time text will be displayed
    const float displayTime{ 3.0f };

    //Create a text object
    sf::Text text(font);
    const std::string isHungry{ "Hungry..." };
    const std::string blankState{ "" };
    bool isTextVisible{ false };
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(player.getPosition().x + 10.f, player.getPosition().y - 30.f));


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
      

            //Debugging
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                mousePosition = sf::Mouse::getPosition(window);
                std::cout << "x: " << mousePosition.x << "y: " << mousePosition.y << std::endl;
                std::cout << clock.getElapsedTime().asSeconds() << std::endl;
            }
            //Press S to display status text
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !isTextVisible)
            {

                text.setString(isHungry);
                clock.restart();
                isTextVisible = true;
                

            }

                //if 3 seconds has passed then clear the status text
            if (isTextVisible && clock.getElapsedTime().asSeconds() > displayTime)
            {
                    text.setString(blankState);
                    isTextVisible = false;
            }
           
        }
        //clear the window with black
        window.clear(sf::Color::Black);
        
        window.draw(player);
        window.draw(text);

        //End the current frame
        window.display();
        
    }
}










/*
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
      */