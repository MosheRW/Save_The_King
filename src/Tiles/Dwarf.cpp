#include "Dwarf.h"

Dwarf::Dwarf(Location place)
	: Tiles(place)
{
	
	m_showV = dwarf;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	reSetLocation(m_place);
}
