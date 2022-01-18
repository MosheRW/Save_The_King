#include "Location.h"

int Location::getX() const
{
	return m_x;
	
}

int Location::getY() const
{
return m_y;
	
}

bool operator==(const Location& right, const Location& left)
{

	if ((right.getX() == left.getX()) &&
		(right.getY() == left.getY()))
		return true;

	return false;
}

bool operator!=(const Location& right, const Location& left)
{
	return !(right == left);
}

std::ostream& operator<<(std::ostream& os, const Location& temp)
{
	os << temp.getX() << ',' << temp.getY();

	return os;
}
