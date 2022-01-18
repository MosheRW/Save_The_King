#include "Mage.h"

Mage::Mage(Location place)
	:Tiles(place)
{
	
	m_showV = mage;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	reSetLocation(place);

}
