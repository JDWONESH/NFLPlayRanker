#pragma once
#include <iostream>
#include <string>
#include "logos.h"

using namespace std;

//Contains all relevant play data needed for the influence algorithm and for the visualization 
class Play
{
	static Logos nflLogos;
	/*
	bool playoffs;
	bool offensiveHighlight;
	string qb;
	string rusher;
	string receiver;
	string defenderOne;
	string defenderTwo;
	int yrdLine;
	int week;
	float winProbChange;*/
	sf::Font font;
	sf::Font scoreFont;
	string homeTeam;
	string awayTeam;
	string homeTeamScore;
	string awayTeamScore;
	string quarter;
	string timeRemaining;
	string playDescription;
	string down;
	string ydsToGo;
	int influence;
public:
	//Constructor
	Play(string homeTeam_, string awayTeam_, string homeTeamScore_, string awayTeamScore_, string quarter_, string timeRemaining_, string playDescription_, string down_, string yrdsToGo_);
	//Draws play data to the screen
	void draw(sf::RenderWindow& window);
	//Returns the influence of the play
	int getInfluence() const;
};