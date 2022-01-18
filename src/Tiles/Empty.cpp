#include "Empty.h"

Empty::Empty(Location place)
	:Tiles(place)
{
	m_showV = empty;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	setLocation(place);
}
