#include "Square.h"


Square::Square(Location leftU)
	: m_1((leftU.getX() + 1) * WIDTH, leftU.getY() * WIDTH), m_3(leftU.getX() * WIDTH,( leftU.getY() + 1) * WIDTH)
{
}

Square::Square(int x, int y)
	: m_1(x + WIDTH, y), m_3(x, y + WIDTH)
{
	
}



Square::Square(const Square& other)
	:m_1(other.m_1), m_3(other.m_3)
{
}

Location Square::rightU() const
{
	return m_1;
}

Location Square::rightD() const
{
	return Location(m_1.getX(),m_3.getY());
}

Location Square::leftU() const
{
	return Location(m_3.getX(),m_1.getY());
}

Location Square::leftD() const
{
	return m_3;
}

bool Square::isOverlaps(const Square& other)
{
	if (*this == other)
		return true;

	auto midP = Location(other.leftD().getX() + 1, other.leftD().getY());

	if ((midP.getX() < m_1.getX()) &&
		(midP.getX() > m_3.getX()) &&
		(midP.getY() > m_1.getY()) &&
		(midP.getY() < m_3.getY()))
		return true;
	
	
	midP = Location(other.leftU().getX() + 1, other.leftU().getY());

	if ((midP.getX() < m_1.getX()) &&
		(midP.getX() > m_3.getX()) &&
		(midP.getY() > m_1.getY()) &&
		(midP.getY() < m_3.getY()))
		return true;

	midP = Location(other.leftU().getX(), other.rightU().getY() + 1); // clash when the movment is left

	if ((midP.getX() < m_1.getX()) &&
		(midP.getX() > m_3.getX()) &&
		(midP.getY() > m_1.getY()) &&
		(midP.getY() < m_3.getY()))
		return true;

	midP = Location(other.rightU().getX(), other.leftU().getY() + 1); // clash when the movment is right

	if ((midP.getX() < m_1.getX()) &&
		(midP.getX() > m_3.getX()) &&
		(midP.getY() > m_1.getY()) &&
		(midP.getY() < m_3.getY()))
		return true; 

	//----------------------------------------------------------------

	if ((other.leftD().getX() < m_1.getX()) &&
		(other.leftD().getX() > m_3.getX()) &&
		(other.leftD().getY() > m_1.getY()) &&
		(other.leftD().getY() < m_3.getY()))
		return true;

	if ((other.rightU().getX() < m_1.getX()) &&
		(other.rightU().getX() > m_3.getX()) &&
		(other.rightU().getY() > m_1.getY()) &&
		(other.rightU().getY() < m_3.getY()))
		return true;

	auto temp = Location(other.leftD().getX(), other.rightU().getY());

	if ((temp.getX() < m_1.getX()) &&
		(temp.getX() > m_3.getX()) &&
		(temp.getY() > m_1.getY()) &&
		(temp.getY() < m_3.getY()))
		return true;

	temp = Location(other.rightU().getX(), other.leftD().getY());


	if ((temp.getX() < m_1.getX()) &&
		(temp.getX() > m_3.getX()) &&
		(temp.getY() > m_1.getY()) &&
		(temp.getY() < m_3.getY()))
		return true;

	
	return false;
}

bool Square::isOverlaps(const Square& other) const
{

	if (*this == other)
		return true;

	//IDEA: to add another check point, at the midel of any rib.
	auto midP = Location(other.leftD().getX() + 1, other.leftD().getY()); // clash when the movment is down

	if ((midP.getX() < m_1.getX()) &&
		(midP.getX() > m_3.getX()) &&
		(midP.getY() > m_1.getY()) &&
		(midP.getY() < m_3.getY()))
		return true;


	midP = Location(other.leftU().getX() + 1, other.leftU().getY());// clash when the movment is up

	if ((midP.getX() < m_1.getX()) &&
		(midP.getX() > m_3.getX()) &&
		(midP.getY() > m_1.getY()) &&
		(midP.getY() < m_3.getY()))
		return true;



	midP = Location(other.leftU().getX(), other.rightU().getY() + 1); // clash when the movment is left

	if ((midP.getX() < m_1.getX()) &&
		(midP.getX() > m_3.getX()) &&
		(midP.getY() > m_1.getY()) &&
		(midP.getY() < m_3.getY()))
		return true;

	midP = Location(other.rightU().getX(), other.leftU().getY() + 1); // clash when the movment is right

	if ((midP.getX() < m_1.getX()) &&
		(midP.getX() > m_3.getX()) &&
		(midP.getY() > m_1.getY()) &&
		(midP.getY() < m_3.getY()))
		return true;


	//----------------------------------------------------------------

	if ((other.leftD().getX() < m_1.getX()) &&
		(other.leftD().getX() > m_3.getX()) &&
		(other.leftD().getY() > m_1.getY()) &&
		(other.leftD().getY() < m_3.getY()))
		return true;

	if ((other.rightU().getX() < m_1.getX()) &&
		(other.rightU().getX() > m_3.getX()) &&
		(other.rightU().getY() > m_1.getY()) &&
		(other.rightU().getY() < m_3.getY()))
		return true;

	auto temp = Location(other.leftD().getX(), other.rightU().getY());

	if ((temp.getX() < m_1.getX()) &&
		(temp.getX() > m_3.getX()) &&
		(temp.getY() > m_1.getY()) &&
		(temp.getY() < m_3.getY()))
		return true;

	temp = Location(other.rightU().getX(), other.leftD().getY());


	if ((temp.getX() < m_1.getX()) &&
		(temp.getX() > m_3.getX()) &&
		(temp.getY() > m_1.getY()) &&
		(temp.getY() < m_3.getY()))
		return true;
	
	
	return false;
}

bool operator==(const Square& right, const Square& left)
{
	if ((right.leftD() == left.leftD()) && (right.rightU() == left.rightU()))
		return true;


	return false;
}

std::ostream& operator<<(std::ostream& os, const Square& temp_b)
{
	
		os << "     leftUp: " << temp_b.leftU().getX() << ',' << temp_b.leftU().getY() <<
			"     leftDown: " << temp_b.leftD().getX() << ',' << temp_b.leftD().getY() <<
			"     rightUp: " << temp_b.rightU().getX() << ',' << temp_b.rightU().getY() <<
			"     rightDown: " << temp_b.rightD().getX() << ',' << temp_b.rightD().getY();
		return os;
	
}

bool isOverlaps(const Square& right, const Square& left)
{
	return right.isOverlaps(left);;
}
