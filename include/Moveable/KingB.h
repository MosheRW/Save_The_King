#pragma once
#include "Moveable.h"


class KingB : public Moveable
{
public:
	KingB(Location place);
	~KingB() {};


	bool addTile(Location place) override;
	bool didItDoIt() override;

private:
	bool m_isWin = false;
	void setAttitude() override;
	void doHisThing(Grid& grid, Location place = Location()) override;
};