#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Location.h"
#include "Globals.h"

class Organ
{
public:
	Organ(Location place) : m_place(place), m_convertedPlace(place.getX() * WIDTH, place.getY() * WIDTH) {};
	virtual ~Organ() {};

	virtual Value getShowV() = 0;
	virtual sf::Sprite getShowS() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	
	Globals* globals = &globals->getInstance();
	Location m_place;
	Location m_convertedPlace;
	Value m_showV;
	sf::Sprite m_showS;

	virtual void heandeler(bool status = false) {};
	virtual void changeImg(Color color) {};
protected:
};
