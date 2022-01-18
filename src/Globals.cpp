#include "Globals.h"

sf::Texture& Globals::getTexture(Color c, Value val) //need to check
{

	//return (textures[int(c)][int(val)]);
	switch (c)
	{
	case transperent:
		return textures[int(val)];
		break;
	case red:
		break;
	case green:
		switch (val)
		{
		case gate:
			return greenT[0];
			break;
		case thief:
			return greenT[1];
			break;
		}
		break;
	case white:
		return TopBar[int(val) - 1];
		break;
	default:
		break;
	}
	
	//auto temp = sf::Texture();
	//temp.loadFromFile("Empty.png");
//	return temp;
}

std::string Globals::getName(Value val)
{
	return std::string(names[int(val)]);
}

sf::Font& Globals::getFont()
{
	return font;
}

sf::SoundBuffer& Globals::getAudio(int i)
{
	return audio[i];
}

Globals::Globals()
{
	initNames();
	initFonts();
	initTextures();
	initSound();
}

void Globals::initNames()
{
	names[empty] = "Empty";
	names[king] = "King";
	names[mage] = "Mage";
	names[warrior] = "Warrior";
	names[thief] = "Thief";
	names[dwarf] = "Dwarf";
	names[throne] = "Throne";
	names[teleporter] = "Teleporter";
	names[key] = "Key";
	names[orc] = "Orc";
	names[wall] = "Wall";
	names[gate] = "Gate";
	names[fire] = "Fire";
	names[gift] = "Gift";
}

void Globals::initFonts()
{
	if (!font.loadFromFile("ARIAL.TTF"))
		std::cout << "ERROR!\n";

}

void Globals::initTextures()
{
	std::string ends[]{ ".png", "", "R","G", "B", "W" };

	for (int i = 0; i <= int(gift); i++)
	{
		if (!textures[i].loadFromFile(names[i] + ends[1] + ends[0])) {
			std::cout << "ERROR" << std::endl;
		}
	}


	for (int i = 0; i < thief; i++)
	{
		if (!TopBar[i].loadFromFile(names[i + 1] + ends[5] + ends[0])) {
			std::cout << "ERROR" << std::endl;
		}
	}

	if (!greenT[0].loadFromFile(names[gate] + ends[green] + ends[0])) {
		std::cout << "ERROR" << std::endl;
	}

	if (!greenT[1].loadFromFile(names[thief] + ends[green] + ends[0])) {
		std::cout << "ERROR" << std::endl;
	}
}

void Globals::initSound()
{
	audio[block].loadFromFile("Block.ogg");

	for (int i = int(king); i <= int(thief); i++)
		audio[i].loadFromFile(names[i] + ".ogg");

	audio[changeTool].loadFromFile("changeTool.ogg");
	audio[teleporter].loadFromFile("teleporter.ogg");
	audio[lose].loadFromFile("lose.ogg");
	audio[openGate].loadFromFile("openGate.ogg");
	audio[regularlGift].loadFromFile("regularGift.ogg");
	audio[specialGift].loadFromFile("specialGift.ogg");
}

sf::Vector2f convertor(Location place)
{
	return sf::Vector2f((place.getX()) * WIDTH, (place.getY()) * WIDTH);
}
