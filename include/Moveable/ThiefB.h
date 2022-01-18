#pragma once
#include "Moveable.h"


class ThiefB : public Moveable
{
public:
	ThiefB(Location place);
	~ThiefB() {};

	bool addTile(Location place);
	bool didItDoIt() override;
	
	void changeImg(Color color) override;
private:
	void setAttitude() override;
	bool m_haveAKey = false;
	sf::Sound m_openGate;
	void doHisThing(Grid& grid, Location place = Location()) override ;
};