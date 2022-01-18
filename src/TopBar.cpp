#include "TopBar.h"


TopBar::TopBar(int level, int timer)
	: m_timerT(timer)//, m_level(level)
{
	if (timer == 0)
		m_isTimer = false;


	text[0] = sf::Text(m_stoper, globals->getFont());

	if (m_isTimer)
		text[2] = sf::Text(m_timer, globals->getFont());

	levelCalaulator(level);

	initPos();

	initText();
	
	
	initShapes();
	
}


void TopBar::draw(sf::RenderWindow& window)
{
	stoperCalculator();
	text[0].setString(m_stoper);
	window.draw(shapes[0]);
	window.draw(text[0]);

	window.draw(shapes[1]);
	window.draw(text[1]);

	
	if (m_isTimer) {
		timerCalculator();
		text[2].setString(m_timer);
	
		window.draw(shapes[2]);
		window.draw(text[2]);
	}
}

void TopBar::updateTime()
{
	m_tm = m_cl.getElapsedTime();
}

void TopBar::addTime(int sec)
{
	m_timerT += sec;
}

void TopBar::remTime(int sec)
{
	m_timerT -= sec;
}

bool TopBar::timeOver()
{
	if (m_timerT < 0)
		return true;

	return false;
}

int TopBar::getTime()
{
	return m_timerT;
}

void TopBar::stoperCalculator()
{
	int temp = m_tm.asSeconds();

	int watch[2] = { temp / 60, temp % 60 };

	for (int i = 0; i < 2; i++) {

		m_clock[i].clear();
		if (watch[i] < 10)
			m_clock[i] = '0' + std::to_string(watch[i]);
		else
			m_clock[i] = std::to_string(watch[i]);
	}

	m_stoper.clear();
	m_stoper = m_clock[0] + ':' + m_clock[1];

}

void TopBar::levelCalaulator(int level)
{
	//text[1].setString("Level" + std::to_string(level));
	text[1] = sf::Text("Level" + std::to_string(level), globals->getFont());
}

void TopBar::initPos()
{
	pos[0] = sf::Vector2f((4 * WIDTH + 4) + 0, 0);
	pos[1] = sf::Vector2f((4 * WIDTH + 4) + 4 + text[0].getGlobalBounds().width, 0);
	pos[2] = sf::Vector2f((4 * WIDTH + 4) + 8  + text[0].getGlobalBounds().width  + text[1].getGlobalBounds().width, 0);

}

void TopBar::initText()
{
	for (int i = 0; i < 3; i++)
	{
		text[i].setFont(globals->getFont());
		text[i].setColor(sf::Color::Blue);
		text[i].getOutlineColor();
		//text[i].setPosition(pos[i]);
	}

}


void TopBar::initShapes()
{
	for (int i = 0; i < 3; i++)
	{
		shapes[i].setFillColor(sf::Color::White);
		shapes[i].setOutlineColor(sf::Color::Green);
		//shapes[i].setOutlineThickness(4);
		shapes[i].setSize(sf::Vector2f(text[i].getGlobalBounds().width + 2, WIDTH));
		shapes[i].setPosition(pos[i]);
		text[i].setPosition(pos[i]);
	}
}

void TopBar::timerCalculator()
{
	static int prev = 0;

	m_timerT -= (int(m_tm.asSeconds()) - prev);//UNDONE: the amount is not accurate.
	prev = m_tm.asSeconds();


	int watch[2] = { m_timerT / 60, m_timerT % 60 };

	for (int i = 0; i < 2; i++) {

		m_clock[i].clear();
		if (watch[i] < 10)
			m_clock[i] = '0' + std::to_string(watch[i]);
		else
			m_clock[i] = std::to_string(watch[i]);
	}

	m_timer.clear();
	m_timer = m_clock[0] + ':' + m_clock[1];

}