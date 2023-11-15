#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(720, 725), "Hello SFML");

    sf::Clock clock;

    //texture
    sf::Texture texture;
 
    if (!texture.loadFromFile("trafficlightup.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    //3colors
    sf::CircleShape redCirc;

    redCirc.setFillColor(sf::Color::Red);
    redCirc.setRadius(85.f);
    redCirc.setPosition(325.f,90.f);

    sf::CircleShape yellowCirc;
    yellowCirc.setFillColor(sf::Color::Yellow);
    yellowCirc.setRadius(85.f);
    yellowCirc.setPosition(320.f, 300.f);

    sf::CircleShape greenCirc;
    greenCirc.setFillColor(sf::Color::Green);
    greenCirc.setRadius(85.f);
    greenCirc.setPosition(320.f, 515.f);
    
    //main loop

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //logic with changing colors

        float elapsedTime = clock.getElapsedTime().asMilliseconds();

        if (std::fmod(elapsedTime, 16000.0f) < 4000.0f)
        {
            redCirc.setFillColor(sf::Color::Red);
            yellowCirc.setFillColor(sf::Color::Black);
            greenCirc.setFillColor(sf::Color::Black);
        }
        else if (std::fmod(elapsedTime, 16000.0f) < 6000.0f)
        {
            redCirc.setFillColor(sf::Color::Red);
            yellowCirc.setFillColor(sf::Color::Yellow);
            greenCirc.setFillColor(sf::Color::Black);
        }
        else if (std::fmod(elapsedTime, 16000.0f) < 10000.0f)
        {
            redCirc.setFillColor(sf::Color::Black);
            yellowCirc.setFillColor(sf::Color::Black);
            greenCirc.setFillColor(sf::Color::Green);
        }
        else if (std::fmod(elapsedTime, 16000.0f) < 14000.0f)
        {
            redCirc.setFillColor(sf::Color::Black);
            yellowCirc.setFillColor(sf::Color::Black);
            greenCirc.setFillColor((static_cast<int>(elapsedTime) % 1000 < 500) ? sf::Color::Green : sf::Color::Black);
        }
        else
        {
            redCirc.setFillColor(sf::Color::Black);
            yellowCirc.setFillColor(sf::Color::Yellow);
            greenCirc.setFillColor(sf::Color::Black);
        }

        window.draw(sprite);
        window.draw(redCirc);
        window.draw(yellowCirc);
        window.draw(greenCirc);

        window.display();
    }

    return 0;
}








