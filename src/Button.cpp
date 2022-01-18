#include "..\include\Button.h"

Button::Button(std::string str)
	: m_text(str,globals->getFont())	
{
	setLettColor(sf::Color::Blue);
	setShapeColor(sf::Color::Yellow);
	setShpeSize();
	setShpePose();	
}

void Button::setText(std::string str)
{
	m_text.setString(str);
	setShpeSize();
	setShpePose();
}

void Button::setPlace(sf::Vector2f pos)
{
	m_text.setPosition(pos);
	setShpePose();

}

void Button::setSize(int size)
{
	m_text.setCharacterSize(size);
	setShpeSize();
	setShpePose();
}

void Button::setLettColor(sf::Color color)
{
	m_text.setColor(color);
}

void Button::setShapeColor(sf::Color color)
{
	m_shape.setFillColor(color);
}

void Button::setShapeOutlineColor(sf::Color color)
{
	m_shape.setOutlineColor(color);
}

void Button::setShapeOutlineThickness(int size)
{
	m_shape.setOutlineThickness(size);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
	window.draw(m_text);
}

bool Button::isPushed(sf::Vector2f pos)
{
	return(m_shape.getGlobalBounds().contains(pos));
}

sf::Vector2f Button::getPose()
{
	return m_shape.getPosition();
}

sf::Vector2f Button::getDim()
{
	return m_shape.getSize();
}

void Button::setShpeSize()
{
	m_shape.setSize(sf::Vector2f(m_text.getLocalBounds().width + 4, m_text.getLocalBounds().height + 5));
}

void Button::setShpePose()
{
	m_shape.setPosition(m_text.getPosition().x, m_text.getPosition().y + 5);

}
