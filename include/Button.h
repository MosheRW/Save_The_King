#pragma once
#include "classes.h"
#include "Globals.h"


#include "SFML/Graphics.hpp"

class Button
{
public:
	Button(std::string str = "Lj,Lnothing");

	void setText(std::string str);
	void setPlace(sf::Vector2f pos);
	void setSize(int size);
	void setLettColor(sf::Color);
	void setShapeColor(sf::Color);
	void setShapeOutlineColor(sf::Color);
	void setShapeOutlineThickness(int size);
	void draw(sf::RenderWindow& window);

	bool isPushed(sf::Vector2f pos);
	sf::Vector2f getPose();
	sf::Vector2f getDim();
private:
	Globals* globals = &globals->getInstance();
	
	sf::Text m_text;
	sf::RectangleShape m_shape;

	void setShpeSize();
	void setShpePose();

};