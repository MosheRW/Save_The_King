#pragma once
#include <iostream>
#include "Location.h"
#include "Globals.h"

class Square
{
public:
	Square(Location  leftU = Location());//for tiles square
	Square(int x = 0, int y = 0);//for tools square.


	Square(const Square&);
	
	
	Location rightU() const;
	Location rightD() const;
	Location leftU() const;
	Location leftD() const;


	bool isOverlaps(const Square& other);//return 'true' if the squars are overlaping
	bool isOverlaps(const Square& other) const;//return 'true' if the squars are overlaping

private:
	Location m_1;
	Location m_3;
	
};

bool operator==(const Square& right, const Square& left);

std::ostream& operator<<(std::ostream& os, const Square& temp_b);

bool isOverlaps(const Square& right, const Square& left);