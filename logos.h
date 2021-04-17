#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
using namespace std;

class Logos
{
	unordered_map<string, sf::Sprite> logoMap;
	sf::Texture logosTexture;
public:
	int length = 195;
	int adjustedLength = 117;
	Logos(string fileName);
	sf::Sprite& getTeamLogo(string teamName);
};