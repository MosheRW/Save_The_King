#pragma once
#include "classes.h"
#include "Square.h"
#include <memory>

class Grid
{
public:
	Grid();
	~Grid() {};

	void set(Value val, Location place);
	Value get(Location place);

	void hendeler(Value val, Location place, bool stastus = false);
	void del(Location place) ;
	void del(Value val, Location place);

	void draw(sf::RenderWindow& window);
	Location jump(Location place);
private:
	std::vector<std::vector<std::unique_ptr<Tiles>>> m_arr;
	void initTelrpotrer(Location place); 
};
