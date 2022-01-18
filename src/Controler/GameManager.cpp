#include "GameManager.h"

GameManager::GameManager()
	:m_levels(levelsNum())
{
	initButtons();
	start();	

	while (m_level <= m_levels)
	{
		
		auto game = GameControler(m_window, m_level);
		m_level = game.theGame(m_window);

		if (m_level <= m_levels)
			menu();
		else
			break;
	}

	end();
	
	
}

int GameManager::levelsNum()
{
	auto file = std::fstream("Levels.txt");

	if (!file)
		std::cerr << "ERROR!\n";

	auto line = std::string();
	std::getline(file, line);
	auto digits = std::istringstream(line);
	int num;

	digits >> num;
	std::cout << num << std::endl;

	file.close();

	return num;
	
}

void GameManager::initButtons()
{

		m_buttons[headline].setText("Level Nu. " + std::to_string(m_level));
		m_buttons[startGame].setText("Start New Game");
		m_buttons[playGame].setText("Play");
		m_buttons[help].setText("Help");
		m_buttons[exitGame].setText("Exit");

		m_buttons[0].setPlace(sf::Vector2f(((8 * WIDTH) - m_buttons[0].getDim().x) / 2, 100));

	for (int i = 1; i < 5; i++)
		//m_buttons[i].setPlace(sf::Vector2f(75, 100 + 50 * i));
	m_buttons[i].setPlace(sf::Vector2f(((8 * WIDTH) - m_buttons[i].getDim().x) / 2, 100 + 50 * i));
}

void GameManager::menu()
{

	m_window.create(sf::VideoMode(8 * WIDTH, 11 * WIDTH), "save The King / menu:");
	m_window.clear(sf::Color(58,63,59));

	m_buttons[headline].setText("Level Nu. " + std::to_string(m_level));

	while (m_window.isOpen()) {
		while (m_window.isOpen()) {

			m_window.clear(sf::Color(58,63,59));
			
			for (int i = 0; i < 5; i++)
				m_buttons[i].draw(m_window);

			m_window.display();

			if (auto event = sf::Event{}; m_window.waitEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					m_window.close();
					break;

				case sf::Event::MouseButtonReleased:
					auto temp = m_window.mapPixelToCoords(
						{ event.mouseButton.x, event.mouseButton.y });
					
					for (int i = 0; i < 5; i++) 
						if (m_buttons[i].isPushed(temp)) {
							m_button = Buttons(i);
							break;
						}
					break;
				}
			}

			choose();

		}

	}
}

void GameManager::end()
{
	m_window.create(sf::VideoMode(11 * WIDTH, 11 * WIDTH), "END:");
	
	Button end[2];
	end[0].setText("You Won!");
	end[1].setText("to Exit press SPACE");

	end[0].setPlace(sf::Vector2f(75, 75));
	end[1].setPlace(sf::Vector2f(end[0].getPose().x, end[0].getPose().y + end[0].getDim().y + 5));

	while (m_window.isOpen()) {

		for (int i = ((m_level == m_levels + 2) ? 1 : 0); i < 2; i++)
			end[i].draw(m_window);
	
		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || event.Closed)
				m_window.close();

	}


}

void GameManager::choose()
{
	switch (m_button)
	{
	case headline:
		break;
	case startGame:
		m_level = 1;
		m_button = headline;
		m_window.close();
		break;
	case playGame:
		m_button = headline;
		m_window.close();
		break;
	case help:
		m_f1.helper(m_window);
		m_button = headline;
		return menu();
		m_window.close();
		break;
	case exitGame:
		m_level = m_levels + 2;
		m_window.close();
		break;
	}

}

void GameManager::start()
{
	
	auto start = Button("Welcom to\n"
		"'Save The King'");

	auto conti = Button("to continue, press Space.");

	start.setPlace(sf::Vector2f(((8 * WIDTH) - start.getDim().x) / 2, 50));
	conti.setPlace(sf::Vector2f(((8 * WIDTH) - start.getDim().x) / 2, (11 * WIDTH) - 2 * conti.getDim().y));
	
	conti.setSize(20);

	while (m_window.isOpen())
	{
		m_window.clear(sf::Color(58, 63, 59));
		start.draw(m_window);
		conti.draw(m_window);

		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				break;
			if (event.Closed)
				m_window.close();
		}
	}
	
	menu();
}
