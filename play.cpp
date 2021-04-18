#include "play.h"

Logos Play::nflLogos = Logos("assets/nfl_logos.png");

Play::	Play(string homeTeam_, string awayTeam_, string homeTeamScore_, string awayTeamScore_, string quarter_, string timeRemaining_, string playDescription_, string down_, string ydsToGo_, 
		string date_, string yardsGained_, string touchdown_, string playType_, string yrdLine_, string sp_, string interception_, string fumble_, string home_WP_Pre_, string home_WP_Post_, string away_WP_Pre_, string away_WP_Post_)
{
	// Assign Display Data
	homeTeam = homeTeam_;
	awayTeam = awayTeam_;
	homeTeamScore = homeTeamScore_;
	awayTeamScore = awayTeamScore_;
	quarter = quarter_;
	//scoreFont.loadFromFile("assets/football_font.ttf");
	//font.loadFromFile("assets/atlanta_book.ttf");
	timeRemaining = timeRemaining_;
	playDescription = playDescription_;
	down = down_;
	ydsToGo = stoi(ydsToGo_);

	// Assign Algo Data
	date = date_;
	yardsGained = stoi(yardsGained_);
	
	if(touchdown_.compare("NA") == 0 || stoi(touchdown_) == 0)
		touchdown = false;
	else
		touchdown = true;
		
	playType = playType_;
	yrdLine = stoi(yrdLine_);
	
	if(sp_.compare("NA") == 0 || stoi(sp_) == 0)
		touchdown = false;
	else
		touchdown = true;
		
	if(interception_.compare("NA") == 0 || stoi(interception_) == 0)
		interception = false;
	else
		interception = true;
		
	if(fumble_.compare("NA") == 0 || stoi(fumble_) == 0)
		fumble = false;
	else
		fumble = true;

	if(home_WP_Pre_.compare("NA") != 0)
		home_WP_Pre =  stof(home_WP_Pre_);
	else
		home_WP_Pre = -1.0;
	if(away_WP_Pre_.compare("NA") != 0)
		away_WP_Pre =  stof(away_WP_Pre_);
	else
		away_WP_Pre = -1.0;
	if(home_WP_Post_.compare("NA") != 0)
		home_WP_Post =  stof(home_WP_Post_);
	else
		home_WP_Pre = -1.0;
	if(away_WP_Post_.compare("NA") != 0)
		away_WP_Post =  stof(away_WP_Post_);
	else
		away_WP_Post = -1.0;

	// Calculate influence
	this->calcInfluence();
	
	// AVL Tree Data
	bf = 0;
	left = nullptr;
	right = nullptr;

	// Debugging
	cout <<playDescription<<endl;
	cout << "Influence: " << influence << endl;
	//cout <<"date: "<<date <<" "<<",yrds gained: "<<yardsGained<<" "<<",touchdown: "<<touchdown<<" "<<",play type: "<<playType<<" "<<",yrd line: "<<yrdLine<<" "<<",sp: "<<sp<<" "<<
	//",interception: "<<interception<<" "<<",fumble: "<<fumble<<" "<<",home pre: "<<home_WP_Pre<<" "<<",home post: "<<home_WP_Post_<<" "<<",away pre: "<<away_WP_Pre<<" "<<",away post: "<<away_WP_Post<<endl;
	//cout << "Play object succesfully created" << endl;
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
			playDesc.setPosition(windowSize.x / 2.0f, 70.0f + spacing);
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
	playDesc.setPosition(windowSize.x / 2.0f, 70.0f + spacing);
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
			downText.setString(down + "nd & " + ydsToGo);
			downText.setFillColor(sf::Color::Yellow);
		}
		else if (down == "3")
		{
			downText.setString(down + "rd & " + ydsToGo);
			downText.setFillColor(sf::Color::Yellow);
		}
		else
		{
			downText.setString(down + "th & " + ydsToGo);
			downText.setFillColor(sf::Color::Red);
		}
		downText.setCharacterSize(100);
		sf::FloatRect downRect = downText.getLocalBounds();
		downText.setOrigin(downRect.left + downRect.width / 2.0f, downRect.top + downRect.height / 2.0f);
		downText.setPosition(windowSize.x - 250.0f, windowSize.y - (borderRect.height / 2.0f));
		window.draw(downText);
	}
}

void Play::calcInfluence() {
	int wpDif = home_WP_Post - home_WP_Pre;
	if(wpDif < 0) wpDif *= -1;
	int timeRem = stoi(timeRemaining);
	if(playType.compare("kickoff") || playType.compare("punt")) {
		influence = 0.4f * (touchdown? 1: 0) + 0.4f * (timeRem < 240? 1 : 0) + 0.5f * wpDif;
	} else if(playType.compare("field_goal")) {
		int fgrange = (yrdLine > 50? yrdLine-50: yrdLine);
		
		if(sp) influence = 0.75*fgrange + 0.5f *(timeRem < 120? 1:0) + 0.5f*wpDif;
		else influence = 0;
			
	} else if(playType.compare("pass") || playType.compare("run")){
		int yards = 0;
		if(interception || fumble) yards = yrdLine;
		else yards = yardsGained;
		
		influence = 0.6f * yards + 0.3f * (timeRem < 180? 1 : 0) + .2f * (timeRem < 360? 1:0) + 0.5f*wpDif + 0.5f * (sp ? 1:0);
	} else {
		influence = 0;
	}
} 

float Play::getInfluence() const
{
	return influence;
}

string Play::getDescription() const {
	return playDescription;
}

// AVL Tree functions

// Calculates height of a subtree (Stepik 5.2)
int Play::treeHeight(Play* root) {
    if(root == nullptr)    // If subtree is empty, return height of 0
        return 0;
    else {
    int right = treeHeight(root->right);    // Recursively get height of right 
    int left = treeHeight(root->left);    // Recursively get height of left
    if(left > right)    // Return the higher one
        return ++left;
    else
        return ++right;
    }
}
// Calculates and sets Play's balance factor using treeHeight helper function
void Play::setBF() {
    int leftHeight = treeHeight(this->left);
    int rightHeight = treeHeight(this->right);
    this->bf = leftHeight - rightHeight;  
}

