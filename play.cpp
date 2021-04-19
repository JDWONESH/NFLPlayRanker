#include "play.h"

Logos Play::nflLogos = Logos("assets/nfl_logos.png");

Play::	Play(string homeTeam_, string awayTeam_, string homeTeamScore_, string awayTeamScore_, string quarter_, string timeRemaining_, string playDescription_, string down_, string ydsToGo_, 
		string date_, string yardsGained_, string touchdown_, string playType_, string yrdLine_, string sp_, string interception_, string fumble_, string home_WP_Pre_, string home_WP_Post_, string away_WP_Pre_, string away_WP_Post_, string textTimeRemaining_, string teamWithBall_)
{
	// Assign Display Data
	homeTeam = homeTeam_;
	awayTeam = awayTeam_;
	teamWithBall = teamWithBall_;
	homeTeamScore = homeTeamScore_;
	awayTeamScore = awayTeamScore_;
	quarter = quarter_;
	textTimeRemaining = textTimeRemaining_;
	timeRemaining = timeRemaining_;
	playDescription = playDescription_;
	down = down_;
	ydsToGo = ydsToGo_;

	// Assign Algo Data
	date = date_;
	if(yardsGained_.compare("NA") == 0)
		yardsGained = 0;
	else
		yardsGained = stoi(yardsGained_);
	
	if(touchdown_.compare("NA") == 0 || stoi(touchdown_) == 0)
		touchdown = false;
	else
		touchdown = true;
		
	playType = playType_;
	
	if(yrdLine_.compare("NA") == 0)
		yrdLine = 0;
	else
		yrdLine = stoi(yrdLine_);
	
	if(sp_.compare("NA") == 0 || stoi(sp_) == 0)
		sp = false;
	else
		sp = true;
		
	if(interception_.compare("NA") == 0 || stoi(interception_) == 0)
		interception = false;
	else
		interception = true;
		
	if(fumble_.compare("NA") == 0 || stoi(fumble_) == 0)
		fumble = false;
	else
		fumble = true;

	if(away_WP_Pre_.compare("NA") != 0 && away_WP_Post_.compare("NA") != 0) {
		away_WP_Pre =  stof(away_WP_Pre_);
		away_WP_Post = stof(away_WP_Post_);
	}
	else {
		away_WP_Pre = 0.0;
		away_WP_Post = 0.0;
	}
	
	if(home_WP_Pre_.compare("NA") != 0 && home_WP_Post_.compare("NA") != 0) {
		home_WP_Pre =  stof(home_WP_Pre_);
		home_WP_Post = stof(home_WP_Post_);
	}
	else {
		home_WP_Pre = 0.0;
		home_WP_Post = 0.0;
	}

	// Calculate influence
	this->calcInfluence();
	
	// AVL Tree Data
	bf = 0;
	left = nullptr;
	right = nullptr;

	// Debugging
	//cout <<playDescription<<endl;
	//cout << "Influence: " << influence << endl;
	//cout <<"date: "<<date <<" "<<",yrds gained: "<<yardsGained<<" "<<",touchdown: "<<touchdown<<" "<<",play type: "<<playType<<" "<<",yrd line: "<<yrdLine<<" "<<",sp: "<<sp<<" "<<
	//",interception: "<<interception<<" "<<",fumble: "<<fumble<<" "<<",home pre: "<<home_WP_Pre<<" "<<",home post: "<<home_WP_Post_<<" "<<",away pre: "<<away_WP_Pre<<" "<<",away post: "<<away_WP_Post<<endl;
	//cout << "Play object succesfully created" << endl;
}

//Draws all the play data to the window
void Play::draw(sf::RenderWindow& window)
{
	//Keeps track of window size
	sf::Vector2u windowSize = window.getSize();

	//Used for the border around the score
	sf::RectangleShape border(sf::Vector2f(4.0f * nflLogos.adjustedLength + 48.0f, nflLogos.adjustedLength));
	border.setFillColor(sf::Color::Black);
	border.setOutlineThickness(12.0f);
	border.setOutlineColor(sf::Color::White);
	border.setPosition(12.0f, windowSize.y - (nflLogos.adjustedLength + 12.0f));
	window.draw(border);

	//Used for the border around the time
	sf::RectangleShape timeBorder(sf::Vector2f(4.0f * nflLogos.adjustedLength - 24.0f, nflLogos.adjustedLength));
	sf::FloatRect borderRect = timeBorder.getLocalBounds();
	timeBorder.setOrigin(borderRect.left + borderRect.width / 2.0f, borderRect.top + borderRect.height / 2.0f);
	timeBorder.setPosition(windowSize.x / 2.0f, windowSize.y - ((borderRect.height / 2.0f) + 12.0f));
	timeBorder.setFillColor(sf::Color::Black);
	timeBorder.setOutlineThickness(12.0f);
	timeBorder.setOutlineColor(sf::Color::White);
	window.draw(timeBorder);

	//Used for the border around the down and distance
	border.setPosition(windowSize.x - 524.0f, windowSize.y - (borderRect.height + 12.0f));
	border.setSize(sf::Vector2f(4.0f * nflLogos.adjustedLength + 44.0f, nflLogos.adjustedLength));
	window.draw(border);

	//Used for the big border around the screen
	sf::RectangleShape bigBorder(sf::Vector2f(windowSize.x - 24.0f, windowSize.y - 153.0f));
	bigBorder.setPosition(12.0f, 12.0f);
	bigBorder.setFillColor(sf::Color::Black);
	bigBorder.setOutlineThickness(12.0f);
	bigBorder.setOutlineColor(sf::Color::White);
	window.draw(bigBorder);

	//Outlines in gold the team with the ball
	sf::RectangleShape ball(sf::Vector2f(12.0f + (2.0f * nflLogos.adjustedLength), nflLogos.adjustedLength));
	ball.setFillColor(sf::Color::Black);
	ball.setOutlineThickness(12.0f);
	ball.setOutlineColor(sf::Color{255, 215, 0});
	if (teamWithBall == awayTeam)
	{
		ball.setPosition(12.0f, windowSize.y - (nflLogos.adjustedLength + 12.0f));
	}
	else
	{
		ball.setPosition(36.0f + (2.0f * nflLogos.adjustedLength), windowSize.y - (nflLogos.adjustedLength + 12.0f));
	}
	window.draw(ball);

	//Away team's logo
	sf::Sprite& awayLogo = nflLogos.getTeamLogo(awayTeam);
	awayLogo.setPosition(12.0f, windowSize.y - (nflLogos.adjustedLength + 12.0f));
	window.draw(awayLogo);

	//Away team's score
	sf::Text awayScore;
	awayScore.setFont(nflLogos.scoreFont);
	awayScore.setString(awayTeamScore);
	awayScore.setCharacterSize(100);
	awayScore.setFillColor(sf::Color::White);
	sf::FloatRect awayScoreRect = awayScore.getLocalBounds();
	awayScore.setOrigin(awayScoreRect.left + awayScoreRect.width / 2.0f, awayScoreRect.top + awayScoreRect.height / 2.0f);
	awayScore.setPosition(12.0f + nflLogos.adjustedLength * 1.5f, windowSize.y - (nflLogos.adjustedLength * 0.5f + 12.0f));
	window.draw(awayScore);

	//Home team's logo
	sf::Sprite& homeLogo = nflLogos.getTeamLogo(homeTeam);
	homeLogo.setPosition(36.0f + nflLogos.adjustedLength * 2.0f, windowSize.y - (nflLogos.adjustedLength + 12.0f));
	window.draw(homeLogo);

	//Home team's score
	sf::Text homeScore;
	homeScore.setFont(nflLogos.scoreFont);
	homeScore.setString(homeTeamScore);
	homeScore.setCharacterSize(100);
	homeScore.setFillColor(sf::Color::White);
	sf::FloatRect homeScoreRect = homeScore.getLocalBounds();
	homeScore.setOrigin(homeScoreRect.left + homeScoreRect.width / 2.0f, homeScoreRect.top + homeScoreRect.height / 2.0f);
	homeScore.setPosition(36.0f + nflLogos.adjustedLength * 3.5f, windowSize.y - (nflLogos.adjustedLength * 0.5f + 12.0f));
	window.draw(homeScore);

	//The quarter and time remaining
	sf::Text quarterText;
	quarterText.setFont(nflLogos.font);
	if (quarter == "1")
	{
		quarterText.setString(quarter + "st " + textTimeRemaining);
	}
	else if (quarter == "2")
	{
		quarterText.setString(quarter + "nd " + textTimeRemaining);
	}
	else if (quarter == "3")
	{
		quarterText.setString(quarter + "rd " + textTimeRemaining);
	}
	else
	{
		quarterText.setString(quarter + "th " + textTimeRemaining);
	}
	if (textTimeRemaining.size() > 6)
	{
		quarterText.setCharacterSize(80);
	}
	else
	{
		quarterText.setCharacterSize(100);
	}
	quarterText.setFillColor(sf::Color::White);
	sf::FloatRect quarterRect = quarterText.getLocalBounds();
	quarterText.setOrigin(quarterRect.left + quarterRect.width / 2.0f, quarterRect.top + quarterRect.height / 2.0f);
	quarterText.setPosition(windowSize.x / 2.0f, windowSize.y - (nflLogos.adjustedLength * 0.5f + 12.0f));
	window.draw(quarterText);

	//The play description
	sf::Text playDesc;
	playDesc.setFont(nflLogos.font);
	int large = 0;
	if (playDescription.size() > 120)
	{
		if (playDescription.size() > 240)
		{
			playDesc.setCharacterSize(40);
			large = 24;
		}
		else
		{
			playDesc.setCharacterSize(60);
			large = 12;
		}
	}
	else
	{
		playDesc.setCharacterSize(90);
	}
	playDesc.setFillColor(sf::Color::White);
	int count = 0;
	float spacing = 0.0f;
	string descLine;
	for (int i = 0; i < playDescription.size(); i++)
	{
		if ((count > 16 + large) && (playDescription[i] == ' '))
		{
			count = 0;
			descLine += playDescription[i];
			playDesc.setString(descLine);
			sf::FloatRect descRect = playDesc.getLocalBounds();
			playDesc.setOrigin(descRect.left + descRect.width / 2.0f, descRect.top + descRect.height / 2.0f);
			playDesc.setPosition(windowSize.x / 2.0f, 70.0f + spacing);
			window.draw(playDesc);
			spacing += 90.0f - (2.0f * large);
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

	//The down and distance
	if (down != "NA")
	{
		sf::Text downText;
		downText.setFont(nflLogos.font);
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
		downText.setPosition(windowSize.x - 270.0f, windowSize.y - ((borderRect.height / 2.0f) + 12.0f));
		window.draw(downText);
	}
}

//Algorithm to calculate the influence value for each play
void Play::calcInfluence() {
	float wpDif = home_WP_Post - home_WP_Pre;
	if(wpDif < 0) wpDif *= -1.0f;
	
	int timeRem = 0;
	if(timeRemaining.compare("NA") != 0) {
		timeRem = stoi(timeRemaining);
		//cout << stoi(timeRemaining)<< endl;
	}
	
	
	if(playType.compare("kickoff") == 0 || playType.compare("punt") == 0) {
		influence = (touchdown? 0.4f: 0.0f) + (timeRem < 120? 0.4f : 0.0f) + (timeRem < 60? 0.4f : 0.0f) + 0.5f*wpDif;
	} else if(playType.compare("field_goal") == 0) {
		int fgrange = (yrdLine > 50? yrdLine-50: yrdLine);
		
		if(sp) influence = 0.75f * (fgrange/50.0f) + (timeRem < 120? 0.5f : 0.0f) + 0.5f*wpDif;
		else influence = 0;
			
	} else if(playType.compare("pass")  == 0 || playType.compare("run") == 0){
		int yards = 0;
		if(interception || fumble) yards = yrdLine;
		else yards = yardsGained;
		
		influence = 0.006f * yards + (timeRem < 180? 0.3f : 0.0f) + (timeRem < 360? 0.2f : 0.0f) + 0.5f*wpDif + 0.5f * (sp ? 1:0);
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

