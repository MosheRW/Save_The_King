#include "Warrior.h"

Warrior::Warrior(Location place)
	:Tiles(place)
{
	
	m_showV = warrior;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	reSetLocation(place);
}
