#include "play.h"

Logos Play::nflLogos = Logos("assets/nfl_logos.png");

Play::Play(string homeTeam_, string awayTeam_, string homeTeamScore_, string awayTeamScore_, string quarter_, string timeRemaining_)
{
	homeTeam = homeTeam_;
	awayTeam = awayTeam_;
	homeTeamScore = homeTeamScore_;
	awayTeamScore = awayTeamScore_;
	quarter = quarter_;
	scoreFont.loadFromFile("assets/football_font.ttf");
	font.loadFromFile("assets/atlanta_book.ttf");
	timeRemaining = timeRemaining_;
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
	quarterText.setString(quarter + "st");
	quarterText.setCharacterSize(100);
	quarterText.setFillColor(sf::Color::White);
	sf::FloatRect quarterRect = quarterText.getLocalBounds();
	quarterText.setOrigin(quarterRect.left + quarterRect.width / 2.0f, quarterRect.top + quarterRect.height / 2.0f);
	quarterText.setPosition(12.0f + nflLogos.adjustedLength * 5.0f, windowSize.y - (nflLogos.adjustedLength * 0.5f + 12.0f));
	window.draw(quarterText);

	sf::Text timeText;
	timeText.setFont(font);
	timeText.setString(timeRemaining);
	timeText.setCharacterSize(100);
	timeText.setFillColor(sf::Color::White);
	sf::FloatRect timeRect = timeText.getLocalBounds();
	timeText.setOrigin(timeRect.left + timeRect.width / 2.0f, timeRect.top + timeRect.height / 2.0f);
	timeText.setPosition(12.0f + nflLogos.adjustedLength * 7.0f, windowSize.y - (nflLogos.adjustedLength * 0.5f + 12.0f));
	window.draw(timeText);

}

int Play::getInfluence() const
{
	return influence;
}