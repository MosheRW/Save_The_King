#pragma once
#include "Moveable.h"


class DwarfB : public Moveable
{
public:
	DwarfB(Location place);	
	~DwarfB() {};

	
	bool addTile(Location place) override;
	bool didItDoIt() override;

private:
	void setAttitude() override;
	void doHisThing(Grid& grid, Location place = Location()) override;
};