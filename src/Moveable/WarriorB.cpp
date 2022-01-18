#include "WarriorB.h"

WarriorB::WarriorB(Location place)
	: Moveable(place)
{
	m_showV = warrior;
	m_showS.setTexture(globals->getTexture(white, m_showV));
	m_showS.setPosition(convertor(place));
	m_doHisThing.setBuffer(globals->getAudio(int(m_showV)));
	setAttitude();
	
}


bool WarriorB::addTile(Location place)
{
	m_arr.push_back(std::unique_ptr<Tiles>(new Warrior(Location(place.getX() * WIDTH, (place.getY() + 1) * WIDTH))));
	return true;
}

bool WarriorB::didItDoIt()
{
	return false;
}



void WarriorB::setAttitude()
{
	attitude[empty] = true;
	attitude[king] = false;
	attitude[mage] = false;
	attitude[warrior] = true;
	attitude[thief] = false;
	attitude[throne] = false;
	attitude[teleporter] = true;
	attitude[key] = true;
	attitude[orc] = true;
	attitude[wall] = false;
	attitude[gate] = false;
	attitude[fire] = false;
	attitude[dwarf] = false;
	attitude[gift] = true;

}

void WarriorB::doHisThing(Grid& grid, Location place)
{
	auto tool = Square(place.getX(), place.getY());

	Square temp[4] = { originalLocation(tool.leftU()) ,
		originalLocation(tool.rightU()),
		originalLocation(tool.leftD()) ,
		originalLocation(tool.rightD()) };


	for (int i = 0; i < 4 ; i++)
		if (grid.get(originalLocation(temp[i].leftU())) == orc) {
			grid.del(orc, originalLocation(temp[i].leftU()));

			grid.set(key, Location(originalLocation(temp[i].leftU()).getX(),
				originalLocation(temp[i].leftU()).getY() - 1));

			m_doHisThing.play();
		}
	
}
