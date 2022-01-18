#include "Moveable.h"
//#include "Square.h"

Moveable::Moveable(Location place)
	:Organ(place)
{
	m_notOK.setBuffer(globals->getAudio(block));
	m_giftS.setBuffer(globals->getAudio(regularlGift));
	m_teleporter.setBuffer(globals->getAudio(teleporter));
	
}

Moveable::~Moveable()
{

}

void Moveable::draw(sf::RenderWindow& window)
{
	window.draw(m_showS);

	auto size = m_arr.size();

	for (int i = 0; i < size; i++)
		m_arr[i].get()->draw(window);

}

Value Moveable::getShowV()
{
	return m_showV;
}

sf::Sprite Moveable::getShowS()
{
	return m_showS;
}

Location Moveable::getTile(int num)
{
	return m_arr[num].get()->m_place;
}

int Moveable::getTileSize()
{
	return m_arr.size();
}

bool Moveable::isOK(Square corners[], Grid& grid, std::vector<std::unique_ptr<Moveable>>& tools, Location size )
{
	//impotant: the len and hight need to be calculate by the size VARRUABLE < - solved
	
	
	//is outside the borders:
	if (corners[0].leftD().getX() < 0 || corners[0].rightD().getX() > size.getX() * WIDTH ||
		corners[0].leftU().getY() < WIDTH || corners[0].leftD().getY() > size.getY() * WIDTH) {
		//sound of blockes route.
		if (m_showV != dwarf)
			m_notOK.play();
		return false;
	}

	//is not on top of forbiden tile:
	if ((attitude[int(grid.get(originalLocation(corners[1].leftU())))] && //tiles
		attitude[int(grid.get(originalLocation(corners[2].leftU())))]) &&// tiles
		(attitude[int(get(corners[0].leftU(), tools))])) {//Tools

		return true;
	}

	//sound of blockes route.
	if (m_showV != dwarf)
		m_notOK.play();

	return false;
}

bool Moveable::makeAMove(Direction dir, Grid& grid, std::vector<std::unique_ptr<Moveable>>& tools, Location size, int i)
{
	auto corners = getCorners(dir, newPlace(dir, m_arr[i].get()->getLocation()));
	
	auto isTele = teleHeandler(corners, dir, grid);
	
	if (isOK(corners, grid, tools, size)) {

		m_arr[i].get()->reSetLocation(corners[0].leftU());
		doHisThing(grid, corners[0].leftU());
		giftHeandler(corners, grid);
		teleSound(isTele);
		return true;
	}

	return false;
}

bool Moveable::isItAGift(Value tool, Grid& grid)
{
	if (m_gift) {

		m_gift = false;
		return true;
	}

	return false;
}

Location Moveable::newPlace(Direction dir, Location place)
{

	switch (dir)
	{
	case up:
		return Location(place.getX(), place.getY() - 1);
		break;
	case down:
		return Location(place.getX(), place.getY() + 1);
		break;
	case right:
		return Location(place.getX() + 1, place.getY());
		break;
	case left:
		return Location(place.getX() - 1, place.getY());
		break;
	}

}

Value Moveable::get(Location place, std::vector<std::unique_ptr<Moveable>>& tools)
{
	
	for (int i = int(king); i <= int(dwarf); i++)
	{
		if (i == int(m_showV))
			continue;

		auto temp = tools[i - 1].get()->getTileSize();// .size();

		for (int x = 0; x < temp; x++)
		{
			if (isOverlaps(Square(tools[i - 1].get()->getTile(x).getX(), tools[i - 1].get()->getTile(x).getY()),
				Square(place.getX(), place.getY()))) {
				return Value(i);
			}

		}
	}


	return empty;
}

Square* Moveable::getCorners(Direction dir, Location place)
{

	static Square corners[3] = { (0,0),(place), (place) };

	corners[0] = Square(place.getX(), place.getY());



	switch (dir)
	{
	case up:
		corners[1] = Square(originalLocation(corners[0].leftU()));
		corners[2] = Square(originalLocation(corners[0].rightU()));
		break;
	case down:
		corners[1] = Square(originalLocation(corners[0].leftD()));
		corners[2] = Square(originalLocation(corners[0].rightD()));
		break;
	case right:
		corners[1] = Square(originalLocation(corners[0].rightU()));
		corners[2] = Square(originalLocation(corners[0].rightD()));
		break;
	case left:
		corners[1] = Square(originalLocation(corners[0].leftU()));
		corners[2] = Square(originalLocation(corners[0].leftD()));
		break;
	}


	return corners;
}

bool Moveable::teleHeandler(Square corners[], Direction dir, Grid& grid)
{

	if (m_showV == dwarf || m_showV == mage)
		return false;

	if (grid.get(originalLocation(corners[1].leftU())) == teleporter) {
		corners[0] = newPlace(dir, grid.jump(originalLocation(corners[1].leftU())));
		return true;
	}


	else if (grid.get(originalLocation(corners[2].leftU())) == teleporter) {
		corners[0] = newPlace(dir, grid.jump(originalLocation(corners[2].leftU())));
		return true;
	}

	return false;
}

void Moveable::teleSound(bool isTele)
{
	if (isTele)
		m_teleporter.play();
}

void Moveable::giftHeandler(Square corners[], Grid& grid)
{
	if (m_showV == dwarf)
		return;

	for (int i = 1; i < 3; i++) {

		if (grid.get(originalLocation(corners[i].leftU())) == gift) {
			grid.del(gift, originalLocation(corners[i].leftU()));
			m_giftS.play();
			m_gift = true;
			return;
		}
	}
}

Location originalLocation(const Location& place)
{
	int x = place.getX() / WIDTH;
	int y = place.getY() / WIDTH;

	return Location(x, y);
}

Location convertLocation(const Location& place)
{
	std::cout << __func__ << std::endl;

	int x = place.getX() * WIDTH;
	int y = place.getY() * WIDTH;

	return Location(x, y);
}
