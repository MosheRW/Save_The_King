#include "Teleporter.h"

Teleporter::Teleporter(Location place, Location next)
	:Tiles(place), m_next(Location(next.getX(), next.getY() + 1))
{
	
	m_showV = teleporter;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	setLocation(place);
}

Location Teleporter::getTwin()
{
	return m_next;
}
