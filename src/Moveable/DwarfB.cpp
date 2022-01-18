#include "DwarfB.h"

DwarfB::DwarfB(Location place)
	: Moveable(place)
{
	m_showV = dwarf;
	
	setAttitude();
}


bool DwarfB::addTile(Location place)
{
	m_arr.push_back(std::unique_ptr<Tiles>
		(new Dwarf(Location(place.getX() * WIDTH, (place.getY() + 1) * WIDTH))));
	
	return true;
}

bool DwarfB::didItDoIt()
{
	return false;
}



void DwarfB::setAttitude()
{
	attitude[empty] = true;
	attitude[king] = false;
	attitude[mage] = false;
	attitude[warrior] = false;
	attitude[thief] = false;
	attitude[throne] = false;
	attitude[teleporter] = false;
	attitude[key] = false;
	attitude[orc] = false;
	attitude[wall] = false;
	attitude[gate] = false;
	attitude[fire] = false;
	attitude[dwarf] = true;
	attitude[gift] = true;

}

void DwarfB::doHisThing(Grid& grid, Location place)
{

	if(place.getX() == -1)
		m_arr.erase(m_arr.begin());
	
}
