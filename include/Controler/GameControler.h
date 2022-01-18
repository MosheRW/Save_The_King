#pragma once
#include "Data.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TopBar.h"

class GameControler
{
public:
	GameControler(sf::RenderWindow& window, int level = 1);

	
	int theGame(sf::RenderWindow& window);

	int getLevel();

private:

	int m_level = 0;
	Data m_data;
	Direction m_dir = up;
	Value m_tool = king;
	TopBar m_topBar; //UNDONE: make it preaty
	bool m_dwarfFreez = false;
	sf::RectangleShape m_correntTool;

	sf::Sound m_changeTool;
	sf::Sound m_lose;
	sf::Sound m_win;
	sf::Sound m_specialGift;
	

	Globals* globals = &globals->getInstance();
	
	void updater(sf::RenderWindow& window);

	bool isLevelEnds();
	
	void giftHeandeler();
	
	void moveDwarf();
	
	bool move(bool make_a_move);
	
	bool pause(sf::RenderWindow& window);
	
	bool getInput(sf::RenderWindow& window);

	bool getFromUser(bool released);
	
	bool getFromTopBar(sf::Vector2f place);
};

