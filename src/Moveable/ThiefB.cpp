#include "ThiefB.h"

ThiefB::ThiefB(Location place)
	: Moveable(place)
{
	m_showV = thief;
	m_showS.setTexture(globals->getTexture(white, m_showV));
	m_showS.setPosition(convertor(place));
	m_doHisThing.setBuffer(globals->getAudio(int(m_showV)));
	m_openGate.setBuffer(globals->getAudio(int(openGate)));
	setAttitude();

}


bool ThiefB::addTile(Location place)
{
	m_arr.push_back(std::unique_ptr<Tiles>(new Thief(Location(place.getX() * WIDTH, (place.getY() + 1) * WIDTH))));
	return true;
}

bool ThiefB::didItDoIt()
{
	return m_haveAKey;;
}

void ThiefB::changeImg(Color color)
{

	m_showS.setTexture(globals->getTexture(color, m_showV));

}


void ThiefB::setAttitude()
{
	attitude[empty] = true;
	attitude[king] = false;
	attitude[mage] = false;
	attitude[warrior] = false;
	attitude[thief] = true;
	attitude[throne] = false;
	attitude[teleporter] = true;
	attitude[key] = true;// &m_haveAKey;// = false; //IS IT OK
	attitude[orc] = false;
	attitude[wall] = false;
	attitude[gate] = &m_haveAKey;//PIN = false; 
	attitude[fire] = false;
	attitude[dwarf] = false;
	attitude[gift] = true;

}

void ThiefB::doHisThing(Grid& grid, Location place)
{

	auto tool = Square(place.getX(), place.getY());

	Square temp[4] = { originalLocation(tool.leftU()) ,
		originalLocation(tool.rightU()),
		originalLocation(tool.leftD()) ,
		originalLocation(tool.rightD()) };

	//use the key
	for (int i = 0; i < 4 && m_haveAKey; i++)
		if (grid.get(originalLocation(temp[i].leftU())) == gate) {
			grid.hendeler(gate, originalLocation(temp[i].leftU()), true);
			m_haveAKey = false;

			m_arr[0].get()->changeImg(transperent);
			m_openGate.play();

		}

	//------
	//collect a key
	for (int i = 0; i < 4 && !m_haveAKey; i++)
		if (grid.get(originalLocation(temp[i].leftU())) == key) {
			grid.del(key, originalLocation(temp[i].leftU()));//assingment = delete;}
			m_arr[0].get()->changeImg(green);
			
			m_haveAKey = true;
			m_doHisThing.play();
		}


}
