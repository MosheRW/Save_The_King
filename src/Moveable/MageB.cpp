#include "MageB.h"

MageB::MageB(Location place)
	: Moveable(place)
{
	m_showV = mage;
	m_showS.setTexture(globals->getTexture(white, m_showV));
	m_showS.setPosition(convertor(place));
	m_doHisThing.setBuffer(globals->getAudio(int(m_showV)));
	setAttitude();
}


bool MageB::addTile(Location place)
{
	m_arr.push_back(std::unique_ptr<Tiles> (new Mage(Location(place.getX() * WIDTH, (place.getY() + 1) * WIDTH))));
	return true;
}

bool MageB::didItDoIt()
{
	return false;
}


void MageB::setAttitude()
{
	attitude[empty] = true;
	attitude[king] = false;
	attitude[mage] = true;
	attitude[warrior] = false;
	attitude[thief] = false;
	attitude[throne] = false;
	attitude[teleporter] = true;
	attitude[key] = true;
	attitude[orc] = false;
	attitude[wall] = false;
	attitude[gate] = false;
	attitude[fire] = true;
	attitude[dwarf] = false;
	attitude[gift] = true;

}

void MageB::doHisThing(Grid& grid, Location place)
{

	auto tool = Square(place.getX(), place.getY());

	Square temp[4] = { originalLocation(tool.leftU()) ,
		originalLocation(tool.rightU()),
		originalLocation(tool.leftD()) ,
		originalLocation(tool.rightD()) };


	for (int i = 0; i < 4; i++)
	{
		if (grid.get(originalLocation(temp[i].leftU())) == fire) {
			grid.del(fire, originalLocation(temp[i].leftU()));
			m_doHisThing.play();
		}
	}
}