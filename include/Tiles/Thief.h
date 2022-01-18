#pragma once
#include "Tiles.h"

class Thief: public Tiles
{
public:
	Thief(Location place);
	~Thief() {};

	void changeImg(Color color) override;
private:

};
