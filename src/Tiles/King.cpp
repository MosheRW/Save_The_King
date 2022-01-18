#include "King.h"

King::King(Location place)
	: Tiles(place)
{
	
	m_showV = king;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	reSetLocation(place);

}
