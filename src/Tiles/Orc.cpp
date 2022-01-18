#include "Orc.h"

Orc::Orc(Location place)
	:Tiles(place)
{
	
	m_showV = orc;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	setLocation(place);
	
}

