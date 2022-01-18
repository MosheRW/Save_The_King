#pragma once
#include <iostream>

class Location
{
public:
	Location(int x = 0, int y = 0) : m_x(x), m_y(y) {}
	
	 //int getX();
	 //int getY();
	
	int getX() const;
	int getY() const;
	
private:
	int m_x = 0;
	int m_y = 0;
};

bool operator==(const Location&, const Location&);
bool operator!=(const Location&, const Location&);

std::ostream& operator<<(std::ostream& os, const Location& temp);