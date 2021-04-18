#include "play.h"

Logos Play::nflLogos = Logos("assets/nfl_logos.png");

Play::Play(string homeTeam_, string awayTeam_, string homeTeamScore_, string awayTeamScore_, string quarter_, string timeRemaining_, string playDescription_, string down_, string ydsToGo_)
{
	homeTeam = homeTeam_;
	awayTeam = awayTeam_;
	homeTeamScore = homeTeamScore_;
	awayTeamScore = awayTeamScore_;
	quarter = quarter_;
	scoreFont.loadFromFile("assets/football_font.ttf");
	font.loadFromFile("assets/atlanta_book.ttf");
	timeRemaining = timeRemaining_;
	playDescription = playDescription_;
	down = down_;
	ydsToGo = ydsToGo_;
}

void Play::draw(sf::RenderWindow& window)
{
	sf::Vector2u windowSize = window.getSize();

	sf::RectangleShape border(sf::Vector2f(4.0f * nflLogos.adjustedLength + 12.0f, nflLogos.adjustedLength));
	border.setFillColor(sf::Color::Black);
	border.setOutlineThickness(12.0f);
	border.setOutlineColor(sf::Color::White);
	border.setPosition(12.0f, windowSize.y - (nflLogos.adjustedLength + 12.0f));
	window.draw(border);
	sf::FloatRect borderRect = border.getLocalBounds();
	border.setOrigin(borderRect.left + borderRect.width / 2.0f, borderRect.top + borderRect.height / 2.0f);
	border.setPosition(windowSize.x / 2.0f, windowSize.y - (borderRect.height / 2.0f));
	window.draw(border);
	border.setPosition(windowSize.x - 250.0f, windowSize.y - (borderRect.height / 2.0f));
	window.draw(border);
	sf::RectangleShape bigBorder(sf::Vector2f(windowSize.x - 24.0f, windowSize.y - 153.0f));
	bigBorder.setPosition(12.0f, 12.0f);
	bigBorder.setFillColor(sf::Color::Black);
	bigBorder.setOutlineThickness(12.0f);
	bigBorder.setOutlineColor(sf::Color::White);
	window.draw(bigBorder);

	sf::Sprite& awayLogo = nflLogos.getTeamLogo(awayTeam);
	awayLogo.setPosition(12.0f, windowSize.y - (nflLogos.adjustedLength + 12.0f));
	window.draw(awayLogo);

	sf::Text awayScore;
	awayScore.setFont(scoreFont);
	awayScore.setString(awayTeamScore);
	awayScore.setCharacterSize(100);
	awayScore.setFillColor(sf::Color::White);
	sf::FloatRect awayScoreRect = awayScore.getLocalBounds();
	awayScore.setOrigin(awayScoreRect.left + awayScoreRect.width / 2.0f, awayScoreRect.top + awayScoreRect.height / 2.0f);
	awayScore.setPosition(12.0f + nflLogos.adjustedLength * 1.5f, windowSize.y - (nflLogos.adjustedLength * 0.5f + 12.0f));
	window.draw(awayScore);

	sf::Sprite& homeLogo = nflLogos.getTeamLogo(homeTeam);
	homeLogo.setPosition(12.0f + nflLogos.adjustedLength * 2, windowSize.y - (nflLogos.adjustedLength + 12.0f));
	window.draw(homeLogo);
	
	sf::Text homeScore;
	homeScore.setFont(scoreFont);
	homeScore.setString(homeTeamScore);
	homeScore.setCharacterSize(100);
	homeScore.setFillColor(sf::Color::White);
	sf::FloatRect homeScoreRect = homeScore.getLocalBounds();
	homeScore.setOrigin(homeScoreRect.left + homeScoreRect.width / 2.0f, homeScoreRect.top + homeScoreRect.height / 2.0f);
	homeScore.setPosition(12.0f + nflLogos.adjustedLength * 3.5f, windowSize.y - (nflLogos.adjustedLength * 0.5f + 12.0f));
	window.draw(homeScore);

	sf::Text quarterText;
	quarterText.setFont(font);
	if (quarter == "1")
	{
		quarterText.setString(quarter + "st " + timeRemaining);
	}
	else if (quarter == "2")
	{
		quarterText.setString(quarter + "nd " + timeRemaining);
	}
	else if (quarter == "3")
	{
		quarterText.setString(quarter + "rd " + timeRemaining);
	}
	else
	{
		quarterText.setString(quarter + "th " + timeRemaining);
	}
	quarterText.setCharacterSize(100);
	quarterText.setFillColor(sf::Color::White);
	sf::FloatRect quarterRect = quarterText.getLocalBounds();
	quarterText.setOrigin(quarterRect.left + quarterRect.width / 2.0f, quarterRect.top + quarterRect.height / 2.0f);
	quarterText.setPosition(windowSize.x / 2.0f, windowSize.y - (nflLogos.adjustedLength * 0.5f + 12.0f));
	window.draw(quarterText);

	sf::Text playDesc;
	playDesc.setFont(font);
	playDesc.setCharacterSize(90);
	playDesc.setFillColor(sf::Color::White);
	int count = 0;
	float spacing = 0.0f;
	string descLine;
	for (int i = 0; i < playDescription.size(); i++)
	{
		if (count > 16 && playDescription[i] == ' ')
		{
			count = 0;
			descLine += playDescription[i];
			playDesc.setString(descLine);
			sf::FloatRect descRect = playDesc.getLocalBounds();
			playDesc.setOrigin(descRect.left + descRect.width / 2.0f, descRect.top + descRect.height / 2.0f);
			playDesc.setPosition(windowSize.x / 2.0f, 140.0f + spacing);
			window.draw(playDesc);
			spacing += 90.0f;
			descLine = "";
		}
		else
		{
			count++;
			descLine += playDescription[i];
		}
	}
	playDesc.setString(descLine);
	sf::FloatRect descRect = playDesc.getLocalBounds();
	playDesc.setOrigin(descRect.left + descRect.width / 2.0f, descRect.top + descRect.height / 2.0f);
	playDesc.setPosition(windowSize.x / 2.0f, 140.0f + spacing);
	window.draw(playDesc);

	if (down != "NA")
	{
		sf::Text downText;
		downText.setFont(font);
		if (down == "1")
		{
			downText.setString(down + "st & " + ydsToGo);
			downText.setFillColor(sf::Color::Yellow);
		}
		else if (down == "2")
		{
			downText.setString(down + "nd" + ydsToGo);
			downText.setFillColor(sf::Color::Yellow);
		}
		else if (down == "3")
		{
			downText.setString(down + "rd" + ydsToGo);
			downText.setFillColor(sf::Color::Yellow);
		}
		else
		{
			downText.setString(down + "th" + ydsToGo);
			downText.setFillColor(sf::Color::Red);
		}
		downText.setCharacterSize(100);
		sf::FloatRect downRect = downText.getLocalBounds();
		downText.setOrigin(downRect.left + downRect.width / 2.0f, downRect.top + downRect.height / 2.0f);
		downText.setPosition(windowSize.x - 250.0f, windowSize.y - (borderRect.height / 2.0f));
		window.draw(downText);
	}
}

int Play::getInfluence() const
{
	return influence;
}