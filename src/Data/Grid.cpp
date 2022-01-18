#include "Grid.h"


Grid::Grid()
{
	//for(int i = int(throne); i <= int(gift); i++)
	for (int i = 0; i <= int(gift); i++)
		m_arr.push_back(std::vector<std::unique_ptr<Tiles>>());
}

void Grid::set(Value val, Location place)
{	
	switch (val)
	{
	case empty:
		break;
	case king:
		break;
	case mage:
		break;
	case warrior:
		break;
	case thief:
		break;
	case dwarf:
		break;
	case throne:
		m_arr[int(val)].push_back(std::unique_ptr<Tiles>(new Throne(place)));
		break;
	case teleporter:
		initTelrpotrer(place);
		break;
	case key:
		m_arr[int(val)].push_back(std::unique_ptr<Tiles>(new Key(place)));
		break;
	case orc:
		m_arr[int(val)].push_back(std::unique_ptr<Tiles>(new Orc(place)));
		break;
	case wall:
		m_arr[int(val)].push_back(std::unique_ptr<Tiles>(new Wall(place)));
		break;
	case gate:
		m_arr[int(val)].push_back(std::unique_ptr<Tiles>(new Gate(place)));
		break;
	case fire:
		m_arr[int(val)].push_back(std::unique_ptr<Tiles>(new Fire(place)));
		break;
	case gift:
		m_arr[int(val)].push_back(std::unique_ptr<Tiles>(new Gift(place)));
		break;
	}
}

Value Grid::get(Location place)
{

	for (int i = int(throne); i <= int(gift); i++)
	{
		auto temp = m_arr[i].size();
		for (int x = 0; x < temp; x++)
		{
			if ((isOverlaps(m_arr[i][x].get()->m_place, place))) {
				return m_arr[i][x].get()->getShowV();
			}
		}
	}

	return empty;
}


void Grid::hendeler(Value val, Location place, bool stastus)
{
	auto size = m_arr[val].size();
	int i;

	for (i = 0; i < size; i++)
	{
		if (m_arr[val][i].get()->getLocation() == place) {
			m_arr[val][i].get()->heandeler(stastus);
			break;
		}
			
	}
	
}

void Grid::del(Location place)
{
	for (int i = int(throne); i <= int(gift); i++)
	{
		del(Value(i), place);
	}
}

void Grid::del(Value val, Location place)
{
	auto size = m_arr[val].size();
	int i;

	for (i = 0; i < size; i++)
	{
		if (m_arr[val][i].get()->getLocation() == place)
			break;
	}

	m_arr[val].erase(m_arr[val].begin() + i);

}

void Grid::draw(sf::RenderWindow& window)
{
	for (int i = int(throne); i <= int(gift); i++)
	{
		auto temp = m_arr[i].size();

		for (int x = 0; x < temp; x++)
		{
			m_arr[i][x].get()->draw(window);
		}
	}
}

Location Grid::jump(Location place)
{
	static auto len = m_arr[teleporter].size();

	for(int i = 0; i < len; i++)
		if(place == m_arr[teleporter][i].get()->getLocation())
			return  m_arr[teleporter][i].get()->getTwin();

	return place;
}

void Grid::initTelrpotrer(Location place)
{
	static bool i = false;
	static Location prev;
	if (!i) {
		m_arr[int(teleporter)].push_back(std::unique_ptr<Tiles>(new Teleporter(place)));
		i = true;
		prev = place;
	}
	else {
		m_arr[int(teleporter)].push_back(std::unique_ptr<Tiles>(new Teleporter(place, prev)));
		m_arr[int(teleporter)][m_arr[int(teleporter)].size() - 2].reset(new Teleporter(prev,place));
		i = false;
	}
}
