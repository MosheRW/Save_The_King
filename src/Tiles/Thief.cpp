#include "Thief.h"

Thief::Thief(Location place)
	: Tiles(place)
{
	
	m_showV = thief;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	reSetLocation(place);
}

void Thief::changeImg(Color color)
{
	m_showS.setTexture(globals->getTexture(color, m_showV));
}
