#include "KingB.h"

KingB::KingB(Location place)
	: Moveable(place)
{
	m_showV = king;
	m_showS.setTexture(globals->getTexture(white, m_showV));
	m_showS.setPosition(convertor(place));
	m_doHisThing.setBuffer(globals->getAudio(int(m_showV)));
	setAttitude();
	
}


bool KingB::addTile(Location place)
{
	m_arr.push_back(std::unique_ptr<Tiles> (new King(Location(place.getX() * WIDTH, (place.getY() + 1) * WIDTH))));

	return true;
}

bool KingB::didItDoIt()
{
	return m_isWin;
}

void KingB::setAttitude()
{
	attitude[empty] = true;
	attitude[king] = true;
	attitude[mage] = false;
	attitude[warrior] = false;
	attitude[thief] = false;
	attitude[throne] = true;
	attitude[teleporter] = true;
	attitude[key] = true;
	attitude[orc] = false;
	attitude[wall] = false;
	attitude[gate] = false;
	attitude[fire] = false;
	attitude[dwarf] = false;
	attitude[gift] = true;

}

void KingB::doHisThing(Grid& grid, Location place)
{

	auto tool = Square(place.getX(),place.getY());
	
	Square temp[4] = { originalLocation(tool.leftU()) ,
		originalLocation(tool.rightU()),
		originalLocation(tool.leftD()) ,
		originalLocation(tool.rightD()) };

	for (int i = 0; i < 4; i++)
	{
		if (grid.get(originalLocation(temp[i].leftU())) == throne) {
			m_isWin = true;
			m_doHisThing.play();
		}
			
	}
		
}
