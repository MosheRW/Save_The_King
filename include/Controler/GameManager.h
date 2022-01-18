#pragma once
#include "GameControler.h"
#include "Button.h"
#include "HelpMenu.h"

enum Buttons {headline, startGame, playGame, help, exitGame};


class GameManager
{
public:
	GameManager();
	~GameManager() {};

private:
	int m_level = 1;
	int m_levels;// = read amount of levels
	sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(8 * WIDTH, 11 * WIDTH), "Save The King / Start");
	Globals* globals = &globals->getInstance();
	HelpMenu m_f1;
	Button m_buttons[5];

	Buttons m_button = headline;

	int levelsNum();
	void initButtons();

	
	void start();//UNDONE
	void menu();
	void end(); //UNDONE
	void choose();
	
};
