#include "Throne.h"

Throne::Throne(Location place)
	:Tiles(place)
{
	
	m_showV = throne;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	setLocation(place);

}

