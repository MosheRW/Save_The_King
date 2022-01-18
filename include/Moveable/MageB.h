#pragma once
#include "Moveable.h"


class MageB : public Moveable
{
public:
	MageB(Location place);
	~MageB() {};

	
	bool addTile(Location place) override;
	bool didItDoIt() override;
	
private:
	void setAttitude() override;
	void doHisThing(Grid& grid, Location place = Location()) override;
	
};