#include "Gate.h"

Gate::Gate(Location place)
	:Tiles(place)
{
	
	m_showV = gate;
	
	m_showS.setTexture(globals->getTexture(transperent, m_showV));
	setLocation(place);
	

}

void Gate::heandeler(bool status)
{
	if (status) {
		changeImg(green);
		m_showV = empty;
	}
	else
		m_showV = gate;
}

void Gate::changeImg(Color color)
{
	m_showS.setTexture(globals->getTexture(color, m_showV));
}

