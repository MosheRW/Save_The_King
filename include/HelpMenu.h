#pragma once
#include "Globals.h"
#include "Button.h"

class HelpMenu
{
public:
	HelpMenu();
	~HelpMenu() {};

	void helper(sf::RenderWindow& window);
private:
	std::vector < std::vector<std::vector<Button>>> m_Menu;
	
	bool firstMenu(sf::RenderWindow& window);
	bool secondMenu(sf::RenderWindow& window, int button1);
	bool thirdMenu(sf::RenderWindow& window, int button1, int button2);
	
	void initMainMenu();
	void initToolsMenu();
	void initTilesMenu();
	void initWindowMenu();
	void initCourseMenu();
	void initSettings(int deg1, bool m = false);
	void m_exit(sf::RenderWindow& window, int button1, int button2, int button3 = 0);
	bool isExit(sf::Vector2f loc);
	
};
