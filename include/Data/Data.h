#pragma once
#include <memory>
#include "RawData.h"
#include "classes.h"
#include "Moveable.h"
#include "KingB.h"
#include "MageB.h"
#include "WarriorB.h"
#include "ThiefB.h"
#include "DwarfB.h"


class Data
{
public:
	Data( sf::RenderWindow& window, int level = 1);
	~Data() {};

	bool isWin();
	bool isGift(Value tool);

	int tilesAmount(Value tool) const;
	bool makeAmove(Direction dir, Value tool, int i = 0);
	void draw(sf::RenderWindow& window);

	int timer();
	
	void delDwarf();
	void addDwarf();

	Location getTile(Value tool, int i = 0);

	
private:

	void initSize();
	void initWindow(sf::RenderWindow& window); //UNDONE
	void initGrid();
	void initButtons();	
	void initBorders();
	
	int m_level;
	RawData m_data;
	Grid m_grid;
	Location m_size;
	
	std::vector<std::unique_ptr<Moveable>> m_Tools; //vector of buttons.
	
	sf::RectangleShape m_rightBorder;
	
};
 