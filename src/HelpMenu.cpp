#include "HelpMenu.h"

HelpMenu::HelpMenu()
{
	initMainMenu();
	initToolsMenu();
	initTilesMenu();
	initWindowMenu();
	initCourseMenu();
}

void HelpMenu::helper(sf::RenderWindow& window)
{
	window.create(sf::VideoMode(11 * WIDTH, 11 * WIDTH), " menu:");

	while (firstMenu(window));

}

bool HelpMenu::firstMenu(sf::RenderWindow& window)
{
	window.clear(sf::Color(58, 63, 59));
	window.setTitle("first menu");

	for (int i = 0; i < 5; i++)
		m_Menu[0][0][i].draw(window);

	m_exit(window, 0, 4);

	window.display();

	//-----

	if (auto event = sf::Event{}; window.waitEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			return false;//window.close();
			break;
		case sf::Event::MouseButtonReleased:
			for (int i = 1; i < 5; i++)
			{
				if (m_Menu[0][0][i].isPushed(
					window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }))) {
					while (secondMenu(window, i));
					break;
				}

				if (isExit(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					return false;

			}
		}
	}

	return true;


}

bool HelpMenu::secondMenu(sf::RenderWindow& window, int button)
{
	window.clear(sf::Color(58, 63, 59));
	window.setTitle("second menu");

	for (int i = 0; i < m_Menu[button][0].size(); i++)
		m_Menu[button][0][i].draw(window);

	m_exit(window, button, m_Menu[button][0].size() - 1);

	window.display();

	//-----

	if (auto event = sf::Event{}; window.waitEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			return false;//window.close();
			break;
		case sf::Event::MouseButtonReleased:
			for (int i = 0; i < m_Menu[button][0].size(); i++)
			{
				if (m_Menu[button][0][i].isPushed(
					window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }))) {
					while (thirdMenu(window, button, i));
					//return false;
					break;
				}
				if (isExit(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					return false;

			}
		}
	}
	return true;
}

bool HelpMenu::thirdMenu(sf::RenderWindow& window, int button1, int button2)
{
	window.clear(sf::Color(58, 63, 59));
	window.setTitle("third menu");


	m_Menu[button1][1][button2].draw(window);
	m_exit(window, button1, button2, 1);

	window.display();

	//-----

	if (auto event = sf::Event{}; window.waitEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			return false;//window.close();
			break;

		case sf::Event::MouseButtonReleased:
			if (isExit(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
				return false;
			break;
		}
	}

	return true;
}

void HelpMenu::initMainMenu()
{
	m_Menu.push_back((std::vector<std::vector<Button>>()));
	m_Menu[0].push_back(std::vector<Button>());

	//-----

	m_Menu[0][0].push_back(Button("     Welcome to 'Save the King'\n"
		"The Purpose of the game is to lead\n"
		"        the king to his throne."));
	m_Menu[0][0][0].setShapeColor(sf::Color::Transparent);
	m_Menu[0][0][0].setSize(25);

	m_Menu[0][0].push_back(Button("You can use the four tools: king, Mage, warrior\n"
		"and thief. Each has strengths and weaknesses.\n"
		"To read more about the game tools:"));

	m_Menu[0][0].push_back(Button("There are different objects on the game board\n"
		"and they have different features.\n"
		"To read more about the types of objects:"));

	m_Menu[0][0].push_back(Button("To read more about the Game window:"));

	m_Menu[0][0].push_back(Button("To read more about the games course's:"));

	m_Menu[0][0].push_back(Button("Exit"));

	//-----


	for (int i = 1; i < m_Menu[0][0].size(); i++) {
		m_Menu[0][0][i].setShapeOutlineThickness(2);
		m_Menu[0][0][i].setSize(20);
	}

	initSettings(0);

	m_Menu[0][0][5].setSize(25);


}

void HelpMenu::initToolsMenu()
{
	m_Menu.push_back((std::vector<std::vector<Button>>()));
	m_Menu[m_Menu.size() - 1].push_back(std::vector<Button>());

	//-----

	m_Menu[m_Menu.size() - 1][0].push_back(Button("King"));
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Mage"));
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Warrior"));
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Thief"));

	m_Menu[m_Menu.size() - 1][0][0].setPlace(sf::Vector2f(75, 75));

	//-----

	m_Menu[m_Menu.size() - 1].push_back(std::vector<Button>());

	m_Menu[m_Menu.size() - 1][1].push_back(Button("King is The main game character.\n"
		"He has no privilege except the ability\n"
		"to sit on the throne."));
	m_Menu[m_Menu.size() - 1][1].push_back(Button("The Mage cannot use teleporters,\nbut can put out a fire."));
	m_Menu[m_Menu.size() - 1][1].push_back(Button("The warrior defeats the orcs. "));
	m_Menu[m_Menu.size() - 1][1].push_back(Button("The thief can collect and hold keys\n"
		"(one at a time), and use them to\n"
		"open the gates of the kingdom.\n"
		"When the thief holds the key,\n"
		"there is an indication\n"
		"of on his board character."));

	initSettings(m_Menu.size() - 1, true);

}

void HelpMenu::initTilesMenu()
{
	m_Menu.push_back((std::vector<std::vector<Button>>()));
	m_Menu[m_Menu.size() - 1].push_back(std::vector<Button>());

	//-----

	m_Menu[m_Menu.size() - 1][0].push_back(Button("Throne"));//1
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Teleporters"));//2
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Key"));//3
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Orc"));//4
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Walll"));//5
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Gate"));//6
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Fire"));//7
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Gift"));//8
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Dwarf"));//9

	m_Menu[m_Menu.size() - 1][0][0].setPlace(sf::Vector2f(75, 25));

	//-----

	m_Menu[m_Menu.size() - 1].push_back(std::vector<Button>());

	//1
	m_Menu[m_Menu.size() - 1][1].push_back(Button("Only the king can sit on it,\n"
		"and sitting on it will lead to the end of the Leve.\n"));
	//2
	m_Menu[m_Menu.size() - 1][1].push_back(Button("Allow skipping between different places\n"
		"on the board, which a magician\n"
		"(and dwarf) cannot use."));
	//3
	m_Menu[m_Menu.size() - 1][1].push_back(Button("Any character can step on them,\n"
		"but only the thief can collect them."));
	//4
	m_Menu[m_Menu.size() - 1][1].push_back(Button("No figure can step on him, except the warrior,\n"
		"who will defeat him.\n" "When Ork dies,"
		"a key falls out of his pocket."));
	//5
	m_Menu[m_Menu.size() - 1][1].push_back(Button("No character can pass through it."));

	//6
	m_Menu[m_Menu.size() - 1][1].push_back(Button("No character can pass through it,\n"
		"unless the thief opens it\n"
		"using a key he has collected."));

	//7
	m_Menu[m_Menu.size() - 1][1].push_back(Button("No character can pass through it (Ouch)\n"
		"except the Mage, who is able to turn it off."));

	//8
	m_Menu[m_Menu.size() - 1][1].push_back(Button("Every game character who steps on a gift\n"
		"- opens it.\n"
		"(Disclaimer: Sometimes the gifts, are not what\n"
		"you have wanted)."));

	//9
	m_Menu[m_Menu.size() - 1][1].push_back(Button("A figure wandering around the board,\n"
		"no figure can step on it and vice versa.\n"
		"(But he can not open gifts, of course)."));

	//-----


	initSettings(m_Menu.size() - 1, true);

}

void HelpMenu::initWindowMenu()
{
	m_Menu.push_back((std::vector<std::vector<Button>>()));
	m_Menu[m_Menu.size() - 1].push_back(std::vector<Button>());

	//-----

	m_Menu[m_Menu.size() - 1][0].push_back(Button("Top Bar:"));


	//-----

	m_Menu[m_Menu.size() - 1].push_back(std::vector<Button>());

	m_Menu[m_Menu.size() - 1][1].push_back(Button("At the top of the Game Panel,\n"
		"the game tools icons will appear,\n"
		"clicking on them will select the game tool.\n"
		"Also, the stage number will appear,\n"
		"a stopwatch from the beginning,\n"
		"and if time is limited, a timer as well."));


	//-----
	initSettings(m_Menu.size() - 1, true);
}

void HelpMenu::initCourseMenu()
{
	m_Menu.push_back((std::vector<std::vector<Button>>()));
	m_Menu[m_Menu.size() - 1].push_back(std::vector<Button>());

	//-----

	m_Menu[m_Menu.size() - 1][0].push_back(Button("Switching between characters:"));
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Movement"));
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Pause"));
	m_Menu[m_Menu.size() - 1][0].push_back(Button("Exit"));

	//-----

	m_Menu[m_Menu.size() - 1].push_back(std::vector<Button>());

	m_Menu[m_Menu.size() - 1][1].push_back(Button("The user can switch between characters by\n"
		"clicking on their icons at the top of the board,\n"
		"or by pressing 'P'."));
	m_Menu[m_Menu.size() - 1][1].push_back(Button("Using the arrows on the keyboard.\n"
		"(The regular ones, or the ones on the NumPad)."));
	m_Menu[m_Menu.size() - 1][1].push_back(Button("You can pause the game at any time,\n"
		"using the 'Space' key.\n"
		"it also continue the game."));
	m_Menu[m_Menu.size() - 1][1].push_back(Button("You can exit the game at any time,\n"
		"by clicking on closing the stage window,\n"
		"then closing the menu."));

	//-----
	initSettings(m_Menu.size() - 1, true);
}

void HelpMenu::initSettings(int deg1, bool m)
{

	for (int i = 0; i < m_Menu[deg1][0].size(); i++)
	{
		if (i != 0)
			m_Menu[deg1][0][i].setPlace(sf::Vector2f(m_Menu[deg1][0][i - 1].getPose().x,
				m_Menu[deg1][0][i - 1].getPose().y + m_Menu[deg1][0][i - 1].getDim().y + 5));

		m_Menu[deg1][0][i].setShapeColor(sf::Color::Transparent);
		m_Menu[deg1][0][i].setShapeOutlineColor(sf::Color::Blue);

		if (m) {
			m_Menu[deg1][1][i].setPlace(sf::Vector2f(5, 75));
			m_Menu[deg1][1][i].setSize(20);
			m_Menu[deg1][1][i].setShapeColor(sf::Color::Transparent);
		}

	}
}

void HelpMenu::m_exit(sf::RenderWindow& window, int button1, int button2, int button3)
{
	m_Menu[0][0][5].setPlace(sf::Vector2f(m_Menu[button1][button3][button2].getPose().x,
		m_Menu[button1][button3][button2].getPose().y + m_Menu[button1][button3][button2].getDim().y + 5));

	m_Menu[0][0][5].draw(window);
}

bool HelpMenu::isExit(sf::Vector2f loc)
{
	if (m_Menu[0][0][5].isPushed(loc))
		return true;

	return false;
}
