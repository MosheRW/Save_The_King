#pragma once
#include "Tiles.h"

class Teleporter : public Tiles
{
public:
	Teleporter(Location place, Location next = Location());
	~Teleporter() {};

	Location getTwin() override;
	
private:
	Location m_next; 
	
};
