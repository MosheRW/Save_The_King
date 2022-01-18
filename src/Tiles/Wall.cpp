#include "Wall.h"

Wall::Wall(Location place)
	:Tiles(place)
{
	
	m_showV = wall;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	setLocation(place);

}

