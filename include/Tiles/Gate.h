#pragma once
#include "Tiles.h"

class Gate: public Tiles
{
public:
	Gate(Location place);
	~Gate() {};

	virtual void heandeler(bool status = false) override;
	void changeImg(Color color) override;
private:

};
