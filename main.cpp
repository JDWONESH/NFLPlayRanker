#include "logos.h"
#include "play.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <queue>

//Used to define the comparison operator for the priority queue of Play pointers
struct InfluenceComparison
{
    //Uses the member variable influence for the comparison
    bool operator()(const Play* lhs, const Play* rhs)
    {
        return lhs->getInfluence() < rhs->getInfluence();
    }
};

int main()
{
    //Will be used to rank the plays according to the influence member variable
    /*priority_queue<Play*, vector<Play*>,InfluenceComparison> playRanks;

    //Loading the data from the file and constructing the plays
    ifstream nflData;
    nflData.open("nflData.csv");

    string line;
    getline(nflData, line);

    while (nflData.good())
    {

        for (int i = 0; i < 254; i++)
        {
            getline(nflData, line, ',');
            switch (i)
            {

            }
        }
        //Each play is pushed onto the priority queue so they are ranked
        //Play* play = new Play();
        //playRanks.push(play);
    }*/

    //Creating the window to display the compilation on
    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 755, (sf::VideoMode::getDesktopMode().height / 2) - 390);
    window.create(sf::VideoMode(1500, 700), "2009 -2018 Greatest NFL Plays Compilation", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);

    //Testing a play
    Play first("NYG", "MIA", "49", "0", "1", "15:00");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        //Public function of play to draw its play data onto the screen
        first.draw(window);
        window.display();
    }

    return 0;
}