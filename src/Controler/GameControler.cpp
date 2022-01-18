#include "GameControler.h"

GameControler::GameControler(sf::RenderWindow& window, int level)
	:m_level(level), m_data(window, m_level), m_topBar(level, m_data.timer())
{

	window.setFramerateLimit(60);
	srand(time(0));

	m_changeTool.setBuffer(globals->getAudio(changeTool));
	m_lose.setBuffer(globals->getAudio(lose));
	m_win.setBuffer(globals->getAudio(king));
	m_specialGift.setBuffer(globals->getAudio(specialGift));

	m_correntTool.setSize(sf::Vector2f(38, 38));
	m_correntTool.setFillColor(sf::Color::Transparent);
	m_correntTool.setPosition(m_data.getTile(m_tool).getX() + 2, m_data.getTile(m_tool).getY() + 2);
	m_correntTool.setOutlineColor(sf::Color::Blue);
	m_correntTool.setOutlineThickness(3);
}

int GameControler::getLevel()
{
	return m_level;
}

int GameControler::theGame(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		updater(window);

		move(getInput(window));

		moveDwarf();

		giftHeandeler();

		if (isLevelEnds())
			window.close();
	}

	return m_level;
}

void GameControler::updater(sf::RenderWindow& window)
{
	m_topBar.updateTime();
	//window.clear(sf::Color(58,63,59));
	window.clear(sf::Color(58,63,59));

	m_correntTool.setPosition(m_data.getTile(m_tool).getX() + 2, m_data.getTile(m_tool).getY());

	m_topBar.draw(window);
	m_data.draw(window);

	window.draw(m_correntTool);
	window.display();
}

bool GameControler::isLevelEnds()
{

	if (m_topBar.timeOver()) {
		m_lose.play();
		return true;
	}
	else if (m_data.isWin()) {
		m_win.play();
		m_level++;
		return true;
	}

	return false;
}

void GameControler::giftHeandeler()
{
	int temp;
	if (m_data.isGift(m_tool)) {

		switch (rand() % (m_data.timer() > 0 ? 7 : 5))
		{
		case 0:
			std::cout << "make a sound\n";
			m_specialGift.play();
			//make a sound.
			break;
		case 1:
			std::cout << "remove dwarts\n";
			m_data.delDwarf();
			//remove dwarfs.
			break;
		case 2:
			std::cout << "frize dwarts\n";
			m_dwarfFreez = true;
			//frize dwarfs for sum amount of time.
			break;
		case 3:
			std::cout << "add dwarts\n";
			m_data.addDwarf();
			//add dwrfs.
			break;
		case 4:
			std::cout << "remove all dwarts\n";
			temp = m_data.tilesAmount(dwarf);
			for (int i = 0; i < temp; i++)
				m_data.delDwarf();
			break;
		case 5:
			std::cout << "add time\n";
			m_topBar.addTime();
			break;
		case 6:
			std::cout << "remove time\n";
			m_topBar.remTime();
			break;
		}
	}
}

void GameControler::moveDwarf()
{
	int amount = m_data.tilesAmount(dwarf);

	static	std::vector<Direction> diri;

	static int z = 0;

	static int i = 0;

	if (m_dwarfFreez)
	{
		if (i < 360) {
			i++;

			return;
		}

		i = 0;
		m_dwarfFreez = false;
	}



	for (; z < amount; z++)
		diri.push_back(Direction(rand() % 4));

	for (int i = 0; i < amount; i++) {

		for (int x = 0; x < DWARF_STEP; x++)
		{
			if (!m_data.makeAmove(diri[i], dwarf, i))
				diri[i] = Direction(rand() % 4);
		}

	}
}

bool GameControler::move(bool make_a_move)
{

	for (int z = 0; z < TOOL_STEP && make_a_move && (m_data.makeAmove(m_dir, m_tool)); z++) { ; }

	return false;
}

bool GameControler::pause(sf::RenderWindow& window)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		
		while (true) {
			
			if (auto event = sf::Event{};  window.waitEvent(event))
			{
		
				if (event.type == sf::Event::KeyPressed) {
					
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
						return true;
				}
			}
		}

	}

	return false;
}

bool GameControler::getInput(sf::RenderWindow& window)
{
	if (auto event = sf::Event{}; window.pollEvent(event)) {

		switch (event.type) {
		case sf::Event::Closed:
			window.close();

		case sf::Event::KeyPressed:
			if (pause(window))
				return getInput(window);
			return getFromUser(true);
			break;

		case sf::Event::MouseButtonReleased:
			return getFromTopBar(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
			break;

		}
	}

	return false;

}

bool GameControler::getFromUser(bool released)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
		m_dir = up;
		return  true;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
		m_dir = down;
		return  true;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
		m_dir = right;
		return  true;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
		m_dir = left;
		return  true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && released)
	{
		if (m_tool < thief)
			m_tool = Value(m_tool + 1);
		else
			m_tool = king;

		m_changeTool.play();

	}


	return false;
}

bool GameControler::getFromTopBar(sf::Vector2f place)
{
	auto d = Square(place.x, place.y);


	for (int i = 0; i < 4; i++)
	{
		auto temp = Square(Location(i, 0));

		if (d.isOverlaps(temp)) {

			m_tool = Value(i + 1);

			m_changeTool.play();

			break;
		}

	}

	return false;

}
