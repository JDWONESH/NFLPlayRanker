#pragma once
#include <iostream>
#include <string>
#include "logos.h"

using namespace std;

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
	int down;
	int yrdsToGo;
	string timeSecs;
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
public:
	Play(string homeTeam_, string awayTeam_, string homeTeamScore_, string awayTeamScore_, string quarter_);
	void draw(sf::RenderWindow& window);
};