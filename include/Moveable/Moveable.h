#pragma once
#include "Organ.h"
#include "Grid.h"
#include "classes.h"
#include "Square.h"



class Moveable : public Organ
{
public:
	Moveable(Location place);
	virtual ~Moveable() = 0 ;

	void draw(sf::RenderWindow& window) override;

	Value getShowV() override;
	sf::Sprite getShowS() override;

	Location getTile(int num);//read the tiles.
	int getTileSize();
	virtual bool addTile(Location place) =0;

	bool isOK(Square corners[], Grid& grid, std::vector<std::unique_ptr<Moveable>>& tools, Location size);
	bool makeAMove(Direction dir, Grid& grid, std::vector<std::unique_ptr<Moveable>>& tools, Location size, int i = 0);

	virtual void doHisThing(Grid& grid, Location place = Location()) = 0;

	virtual bool didItDoIt() = 0;
	bool isItAGift(Value tool, Grid& grid);
	

protected:
	


	virtual void setAttitude() = 0;

	Location newPlace(Direction dir, Location place);

	std::vector<std::unique_ptr<Tiles>>  m_arr;

	bool attitude[int(gift)+1];
	bool m_gift = false;
	sf::Sound m_doHisThing;
	sf::Sound m_notOK;
	sf::Sound m_giftS;
	sf::Sound m_teleporter;

	Value get(Location place, std::vector<std::unique_ptr<Moveable>>& tools);

	Square* getCorners(Direction dir, Location place);
	
	

private:
	bool teleHeandler(Square corners[], Direction dir, Grid& grid);
	void giftHeandler(Square corners[], Grid& grid);
	void teleSound(bool isTele);
	
};

Location originalLocation(const Location& place);
Location convertLocation(const Location& place);