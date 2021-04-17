#include "Logos.h"
#include <iostream>

Logos::Logos(string filename)
{
	if (!logosTexture.loadFromFile(filename))
	{
		std::cout << "Unable to open" << std::endl;
	}
	else
	{
		logoMap["ARI"].setTexture(logosTexture);
		logoMap["ARI"].setTextureRect(sf::IntRect(0, 0, length, length));
		logoMap["ARI"].setScale(0.6f, 0.6f);
		logoMap["JAC"].setTexture(logosTexture);
		logoMap["JAC"].setTextureRect(sf::IntRect(length, 0, length, length));
		logoMap["JAC"].setScale(0.6f, 0.6f);
		logoMap["NE"].setTexture(logosTexture);
		logoMap["NE"].setTextureRect(sf::IntRect(2 * length, 0, length, length));
		logoMap["NE"].setScale(0.6f, 0.6f);
		logoMap["NO"].setTexture(logosTexture);
		logoMap["NO"].setTextureRect(sf::IntRect(4 * length, 0, length, length));
		logoMap["NO"].setScale(0.6f, 0.6f);
		logoMap["CLE"].setTexture(logosTexture);
		logoMap["CLE"].setTextureRect(sf::IntRect(5 * length, 0, length, length));
		logoMap["CLE"].setScale(0.6f, 0.6f);
		logoMap["DEN"].setTexture(logosTexture);
		logoMap["DEN"].setTextureRect(sf::IntRect(6 * length, 0, length, length));
		logoMap["DEN"].setScale(0.6f, 0.6f);
		logoMap["SEA"].setTexture(logosTexture);
		logoMap["SEA"].setTextureRect(sf::IntRect(0, length, length, length));
		logoMap["SEA"].setScale(0.6f, 0.6f);
		logoMap["BAL"].setTexture(logosTexture);
		logoMap["BAL"].setTextureRect(sf::IntRect(length, length, length, length));
		logoMap["BAL"].setScale(0.6f, 0.6f);
		logoMap["WAS"].setTexture(logosTexture);
		logoMap["WAS"].setTextureRect(sf::IntRect(2 * length, length, length, length));
		logoMap["WAS"].setScale(0.6f, 0.6f);
		logoMap["NYG"].setTexture(logosTexture);
		logoMap["NYG"].setTextureRect(sf::IntRect(3 * length, length, length, length));
		logoMap["NYG"].setScale(0.6f, 0.6f);
		logoMap["CAR"].setTexture(logosTexture);
		logoMap["CAR"].setTextureRect(sf::IntRect(4 * length, length, length, length));
		logoMap["CAR"].setScale(0.6f, 0.6f);
		logoMap["NYJ"].setTexture(logosTexture);
		logoMap["NYJ"].setTextureRect(sf::IntRect(5 * length, length, length, length));
		logoMap["NYJ"].setScale(0.6f, 0.6f);
		logoMap["HOU"].setTexture(logosTexture);
		logoMap["HOU"].setTextureRect(sf::IntRect(6 * length, length, length, length));
		logoMap["HOU"].setScale(0.6f, 0.6f);
		logoMap["PHI"].setTexture(logosTexture);
		logoMap["PHI"].setTextureRect(sf::IntRect(length, 2 * length, length, length));
		logoMap["PHI"].setScale(0.6f, 0.6f);
		logoMap["CHI"].setTexture(logosTexture);
		logoMap["CHI"].setTextureRect(sf::IntRect(2 * length, 2 * length, length, length));
		logoMap["CHI"].setScale(0.6f, 0.6f);
		logoMap["OAK"].setTexture(logosTexture);
		logoMap["OAK"].setTextureRect(sf::IntRect(3 * length, 2 * length, length, length));
		logoMap["OAK"].setScale(0.6f, 0.6f);
		logoMap["ATL"].setTexture(logosTexture);
		logoMap["ATL"].setTextureRect(sf::IntRect(4 * length, 2 * length, length, length));
		logoMap["ATL"].setScale(0.6f, 0.6f);
		logoMap["PIT"].setTexture(logosTexture);
		logoMap["PIT"].setTextureRect(sf::IntRect(5 * length, 2 * length, length, length));
		logoMap["PIT"].setScale(0.6f, 0.6f);
		logoMap["DET"].setTexture(logosTexture);
		logoMap["DET"].setTextureRect(sf::IntRect(6 * length, 2 * length, length, length));
		logoMap["DET"].setScale(0.6f, 0.6f);
		logoMap["STL"].setTexture(logosTexture);
		logoMap["STL"].setTextureRect(sf::IntRect(0, 3 * length, length, length));
		logoMap["STL"].setScale(0.6f, 0.6f);
		logoMap["SF"].setTexture(logosTexture);
		logoMap["SF"].setTextureRect(sf::IntRect(length, 3 * length, length, length));
		logoMap["SF"].setScale(0.6f, 0.6f);
		logoMap["DAL"].setTexture(logosTexture);
		logoMap["DAL"].setTextureRect(sf::IntRect(2 * length, 3 * length, length, length));
		logoMap["DAL"].setScale(0.6f, 0.6f);
		logoMap["IND"].setTexture(logosTexture);
		logoMap["IND"].setTextureRect(sf::IntRect(4 * length, 3 * length, length, length));
		logoMap["IND"].setScale(0.6f, 0.6f);
		logoMap["MIA"].setTexture(logosTexture);
		logoMap["MIA"].setTextureRect(sf::IntRect(5 * length, 3 * length, length, length));
		logoMap["MIA"].setScale(0.6f, 0.6f);
		logoMap["KC"].setTexture(logosTexture);
		logoMap["KC"].setTextureRect(sf::IntRect(6 * length, 3 * length, length, length));
		logoMap["KC"].setScale(0.6f, 0.6f);
		logoMap["CIN"].setTexture(logosTexture);
		logoMap["CIN"].setTextureRect(sf::IntRect(0, 4 * length, length, length));
		logoMap["CIN"].setScale(0.6f, 0.6f);
		logoMap["TEN"].setTexture(logosTexture);
		logoMap["TEN"].setTextureRect(sf::IntRect(length, 4 * length, length, length));
		logoMap["TEN"].setScale(0.6f, 0.6f);
		logoMap["GB"].setTexture(logosTexture);
		logoMap["GB"].setTextureRect(sf::IntRect(2 * length, 4 * length, length, length));
		logoMap["GB"].setScale(0.6f, 0.6f);
		logoMap["BUF"].setTexture(logosTexture);
		logoMap["BUF"].setTextureRect(sf::IntRect(3 * length, 4 * length, length, length));
		logoMap["BUF"].setScale(0.6f, 0.6f);
		logoMap["TB"].setTexture(logosTexture);
		logoMap["TB"].setTextureRect(sf::IntRect(4 * length, 4 * length, length, length));
		logoMap["TB"].setScale(0.6f, 0.6f);
		logoMap["MIN"].setTexture(logosTexture);
		logoMap["MIN"].setTextureRect(sf::IntRect(5 * length, 4 * length, length, length));
		logoMap["MIN"].setScale(0.6f, 0.6f);
		logoMap["SD"].setTexture(logosTexture);
		logoMap["SD"].setTextureRect(sf::IntRect(6 * length, 4 * length, length, length));
		logoMap["SD"].setScale(0.6f, 0.6f);
	}
}

sf::Sprite& Logos::getTeamLogo(string teamName)
{
	if (teamName == "JAX")
	{
		teamName = "JAC";
	}
	else if (teamName == "LA")
	{
		teamName = "STL";
	}
	else if (teamName == "LAC")
	{
		teamName = "SD";
	}
	return logoMap[teamName];
}