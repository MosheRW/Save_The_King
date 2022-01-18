#include "Fire.h"

Fire::Fire(Location place)
	:Tiles(place)
{
	m_showV = fire;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	setLocation(place);
}
