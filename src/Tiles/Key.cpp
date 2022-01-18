#include "Key.h"

Key::Key(Location place)
	:Tiles(place)
{
	
	m_showV = key;
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	setLocation(place);
	

}
