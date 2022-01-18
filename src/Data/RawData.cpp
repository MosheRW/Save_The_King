#include "RawData.h"

RawData::RawData(int level)
	:m_level(level)
{
	if (isFileExist())
		readFile();
	else
		std::cout << "ERROR!\n";
}

RawData::~RawData()
{
	m_file.close();
}

Location RawData::get(Value val, int i) const
{
	return arr[int(val)][i];
}

int RawData::time()
{
	return (arr[int(gift) + 1][0].getX() * 60 + arr[int(gift) + 1][0].getY());
}

int RawData::getLen(Value val) const
{
	return arr[int(val)].size();
}


Value RawData::getValue(Location cell) const
{
	for (int x = int(king); x <= int(gift); x++) {
		auto temLen = arr[x].size();
		for (int i = 0; i < temLen; i++) {
			if (arr[x][i] == cell)
				return Value(x);
		}
	}

	return empty;

}

Value RawData::getValue(int x, int y) const
{
	return getValue(Location(x, y));
}

bool RawData::isFileExist()
{
	std::cout << __func__ << m_name << std::endl;

	m_file = std::fstream(m_name);

	if (!m_file)
		return false;

	return true;
}

void RawData::readFile()
{
	auto digits = std::istringstream();
	auto line = std::string();
	int x, y, z;


	//size:
	std::vector<Location> temp;
	std::getline(m_file, line);

	digits = std::istringstream(line);

	digits >> x;
	digits >> y;
	temp.push_back(Location(x, y));

	arr.push_back(temp);

	temp.clear();

	line.clear();

	//tools and tiles:
	for (int i = int(king); i <= int(gift); i++)
	{
		std::getline(m_file, line);
		digits = std::istringstream(line);

		digits >> z;

		for (int a = 0; a < z; a++)
		{
			digits >> x;
			digits >> y;

			temp.push_back(Location(x, y));
		}

		arr.push_back(temp);

		temp.clear();
		line.clear();
	}
	

	//timer:
	std::getline(m_file, line);
	digits = std::istringstream(line);

	digits >> x;
	digits >> y;

	temp.push_back(Location(x, y));
	arr.push_back(temp);
	
	temp.clear();
	line.clear();


	m_file.close();
}
