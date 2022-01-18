#pragma once
#include "Moveable.h"


class WarriorB : public Moveable
{
public:
	WarriorB(Location place);
	~WarriorB() {};
	
	bool addTile(Location place) override;
	bool didItDoIt() override;
	
private:
	void setAttitude() override;
	void doHisThing(Grid& grid, Location place = Location()) override;
};