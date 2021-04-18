#include "logos.h"
#include "play.h"
#include "tree.h"
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

// Reads in data from file and constructs plays
void load() 
{
    //Will be used to rank the plays according to the influence member variable
    priority_queue<Play*, vector<Play*>,InfluenceComparison> playRanksHeap;
    //AVLTree tree;

    //Loading the data from the file and constructing the plays
    ifstream nflData;
    nflData.open("nflData.csv");

    //Disregard first line
    string line;
    getline(nflData, line);

    unordered_map<int, string> vals;    // Holds each play's values
    // For checking if on description
    bool onDesc = true; 
    string temp; 
    int count = 0;
    //while(nflData.good())
    for(int i = 0; i < 10000; i++)  // Adjust this loop to alter how many plays to create
    {
        for (int j = 0; j < 254; j++)
        {
            onDesc = false;
            // Handle description section
            if(j ==24) {
                onDesc = true;
                getline(nflData, line, ',');
                vals[j] = line;
                getline(nflData, line, ',');
                while(onDesc) {
                    // Check for invalid characters after comma
                    if(line[0] == ' '||line[0] == '1'||line[0]=='2'||line[0]=='3'||line[0]=='4'||line[0]=='5'||line[0]=='6'||line[0]=='7'||line[0]=='8'||line[0]=='9'||line[0]=='0'||
                        line[0]=='S'||line[0]=='T'||line[0]=='D'||line[0]=='"'||line[0]=='Y') {
                        vals.at(vals.size()-1) += line;
                        getline(nflData, line, ',');
                    } else {
                        onDesc = false;
                    }
                }
            } 
            else if(j == 25) {
                vals[j] = line;
            }
            // Else, record value
            else {
                getline(nflData, line, ',');
                if(j == 0 && count != 0) {
                    // Handle invalid characters for gameID
                    while(line.at(0) == '\n' || line.at(0)== '0' || line.at(0) == 'N' || line.at(0) == 'A') {
                        line.erase(line.begin());
                    }
                }
                vals[j] = line;
            }
        }
        //Create play objects
        Play* play = new Play(vals[2], vals[3], vals[50], vals[51], vals[17], vals[12], vals[24], vals[18], vals[22], 
	                vals[9], vals[26], vals[144], vals[25], vals[8], vals[16], vals[119], vals[137], vals[89], vals[92], vals[90], vals[93]);
        // Push into min heap
        //playRanksHeap.push(play);
        //Push into avl tree
        //tree.insert(play);

        //cout << count << ": " << vals[9] << endl;  // Debug: vals[i] corresponds with the value in column i starting at i = 0
        count++;
        vals.clear();
    }
    //cout << tree.printInorder(tree.getRoot(), "");
}

int main()
{
    //Load data
    load();

    //Creating the window to display the compilation on
    sf::RenderWindow window;
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 755, (sf::VideoMode::getDesktopMode().height / 2) - 390);
    window.create(sf::VideoMode(1500, 700), "2009 -2018 Greatest NFL Plays Compilation", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);
    window.setKeyRepeatEnabled(true);

    //Testing a play
    //Play first("NYG", "MIA", "49", "0", "1", "15:00");

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
        //first.draw(window);
        window.display();
    }

    return 0;
}