
#include "..\include\Tiles\Tiles.h"

Tiles::Tiles(Location place)
//	: Organ(place) {}
	: Organ(Location(place.getX(), place.getY() + 1)) {}

Tiles::~Tiles()
{
}

void Tiles::draw(sf::RenderWindow& window)
{
	/*static bool m = true;
	
	if (m) {
		auto temp = m_showS.getPosition();
		m_showS.setPosition(temp.x, temp.y + WIDTH);
		m = false;
	}*/

	window.draw(m_showS);
	
}

void Tiles::setLocation(Location place)
{
	m_showS.setPosition(sf::Vector2f(m_place.getX() * (WIDTH), m_place.getY() * WIDTH));
}

void Tiles::reSetLocation(Location place)
{
	m_place = place;
	m_showS.setPosition(sf::Vector2f(m_place.getX(), m_place.getY()));

}

void Tiles::reSetButtomLocation(Location place)
{
	setLocation(place);
	m_showS.setPosition(sf::Vector2f(m_place.getX(), m_place.getY()));
}

Location Tiles::getLocation()
{
	return m_place;
}

Location Tiles::getConvertedLocation()
{
	return m_convertedPlace;
}

Location Tiles::getToolLocation()
{
	
	return Location(m_place.getX() * WIDTH, m_place.getY() * WIDTH);
}

Value Tiles::getShowV()
{
	
	return m_showV;
}

sf::Sprite Tiles::getShowS()
{
	return m_showS;
}

Location Tiles::getTwin()
{
	return Location();
}
