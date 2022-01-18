#include "Data.h"
#include <memory>

Data::Data(sf::RenderWindow& window, int level)
	: m_data(level), m_level(level)
{
	initSize();

	initWindow(window);
	
	initGrid();
	
	initBorders();

	initButtons();

}

bool Data::isWin()
{
	return m_Tools[0].get()->didItDoIt();
}

bool Data::isGift(Value tool)
{
	
	return m_Tools[int(tool - 1)].get()->isItAGift(tool,m_grid);
}

int Data::tilesAmount(Value tool) const
{
	return m_Tools[int(tool - 1)].get()->getTileSize();
}

bool Data::makeAmove(Direction dir, Value tool, int i)
{	

	int x = int(tool) - 1;
	if (m_Tools[x].get()->makeAMove(dir, m_grid, m_Tools, m_size, i))
		return true;
	
	return false;
}

void Data::draw(sf::RenderWindow& window)
{
	window.draw(m_rightBorder);
	
	m_grid.draw(window);	

	for(int i = 0; i < int(dwarf); i++)
		m_Tools[i].get()->draw(window);

}

int Data::timer()
{
	
	return m_data.time();
}

void Data::delDwarf()
{
	m_Tools[dwarf - 1].get()->doHisThing(m_grid, Location(-1,-1));
}

void Data::addDwarf()
{
	m_Tools[dwarf - 1].get()->addTile(Location(1,1));
}
Location Data::getTile(Value tool, int i)
{
	return m_Tools[int(tool) - 1].get()->getTile(i);
}
/*
sf::Sprite Data::get(Value tool)
{
	return m_Tools[int(tool - 1)].get().
}*/


void Data::initSize()
{
	// added place for the stastus line
	m_size = Location(m_data.get(empty).getX(), m_data.get(empty).getY() + 1); 
	
}

void Data::initWindow(sf::RenderWindow& window)
{
	
	if (m_size.getX() < 11)
		window.create(sf::VideoMode(11 * WIDTH,( m_size.getY() ) * WIDTH),
			"level " + std::to_string(m_level));
	else
		window.create(sf::VideoMode(m_size.getX()  * WIDTH, (m_size.getY()) * WIDTH),
			"level " + std::to_string(m_level));

	
	
}

void Data::initGrid()
{
	for (int i = int(throne) ; i <= int(gift); i++)
	{
		auto size = m_data.getLen(Value(i));

			for(int x = 0; x < size; x++)
				m_grid.set(Value(i), m_data.get(Value(i),x));
	}	
}

void Data::initButtons()
{
	int size;
	int temp;

	m_Tools.push_back(std::unique_ptr<Moveable>(new KingB(Location(0, 0))));
	m_Tools.push_back(std::unique_ptr<Moveable>(new MageB(Location(1, 0))));
	m_Tools.push_back(std::unique_ptr<Moveable>(new WarriorB(Location(2, 0))));
	m_Tools.push_back(std::unique_ptr<Moveable>(new ThiefB(Location(3, 0))));
	m_Tools.push_back(std::unique_ptr<Moveable>(new DwarfB(Location(4,1))));



	for (int i = int(king); i <= int(dwarf); i++) 
	{
		size = m_data.getLen(Value(i));
	
		for (int x = 0; x < size; x++) {
			temp = i - 1;
			if(!m_Tools[temp].get()->addTile(m_data.get(Value(i), x)))
				std::cout << "ERROR!\n";
			std::cout << m_Tools[temp].get()->getTile(x) << std::endl;
		}
	}
}

void Data::initBorders()
{
	m_rightBorder = sf::RectangleShape(sf::Vector2f(10, m_size.getY() * WIDTH));
	m_rightBorder.setPosition(m_size.getX() * WIDTH, WIDTH);
	m_rightBorder.setFillColor(sf::Color::White);
	
}
