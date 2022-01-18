#include "Gift.h"

Gift::Gift(Location place)
	:Tiles(place)
{
	
	m_showV = gift;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	setLocation(place);	

}

