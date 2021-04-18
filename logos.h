#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
using namespace std;

//Container class for the picture of each teams logo
class Logos
{
	//Each team's logo is stored in an unordered map
	unordered_map<string, sf::Sprite> logoMap;
	sf::Texture logosTexture;
public:
	//Pixel length of each logo
	int length = 195;
	//Adjusted pixel length of each logo after resizing
	int adjustedLength = 117;
	Logos(string fileName);
	sf::Sprite& getTeamLogo(string teamName);
};