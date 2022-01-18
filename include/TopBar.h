#pragma once

#include "Data.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class TopBar
{
public:
	TopBar(int level = 1, int timer = 0);
	~TopBar() {};
	//IDEA: timer, stoper, name.
	
	void draw(sf::RenderWindow& window);
	//void draw();
	void updateTime();
	void addTime(int sec = 60);
	void remTime(int sec = 60);
	bool timeOver();
	int getTime();

private:
	sf::Time m_tm;
	sf::Clock m_cl;

	//int m_level;
	int m_timerT;
	bool m_isTimer;
	
	std::string m_stoper = "00:00";
	std::string m_timer = "00:00";
	
	std::string m_clock[2];
	Globals* globals = &globals->getInstance();

	sf::Vector2f pos[3];
	sf::Text text[3];
	sf::RectangleShape shapes[3];

	void initPos();
	void initText();
	void initShapes();

	void stoperCalculator();
	void timerCalculator();
	void levelCalaulator(int);
};