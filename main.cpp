#include "logos.h"
#include "play.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

int main()
{
    /*
    ifstream nflData;
    nflData.open("nflData.csv");

    //while (nflData.good())
    //{
    string line;
    getline(nflData, line);

    //while (nflData.good())
    //{

        for (int i = 0; i < 254; i++)
        {
            getline(nflData, line, ',');
            cout << line << endl;
        }
    //}
    */

    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 755, (sf::VideoMode::getDesktopMode().height / 2) - 390);
    window.create(sf::VideoMode(1500, 700), "2009 -2018 Greatest NFL Plays Compilation", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);

    Play first("NYG", "MIA", "49", "0", "1");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color{ 128, 128, 128 });
        first.draw(window);
        window.display();
    }

    return 0;
}