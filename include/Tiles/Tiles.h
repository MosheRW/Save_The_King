#pragma once
#include "Organ.h"

class Tiles: public Organ
{
public:
	
	Tiles(Location place);
	virtual ~Tiles() = 0;
	
	void draw(sf::RenderWindow& window) override;

	void setLocation(Location place);//reset Tile location, and initials.
	void reSetLocation(Location place);//reset m_place.
	void reSetButtomLocation(Location place);//reset Tools Tiles location.
	Location getLocation();
	Location getConvertedLocation();
	Location getToolLocation();

	virtual Value getShowV() override;
	virtual sf::Sprite getShowS() override;

	virtual Location getTwin();
	
protected:
	
	
};
