#pragma once
#include <vector>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Location.h"

const int WIDTH = 40;

const int TOOL_STEP = 5;

const int DWARF_STEP = 6;

enum Value { empty, king, mage, warrior, thief, dwarf, throne, teleporter, key, orc, wall, gate, fire, gift};
enum Audio {block = 0, /*king, mage, warrior, thief,*/lose = 5, openGate = 6,/*teleporter*/ changeTool = 8, specialGift = 9, regularlGift = 10};

enum Direction { up, down, right, left};

enum Color { transperent = 1, red = 2, green = 3, white = 4 };

class Globals
{
public:
    Globals(Globals const&) = delete;
    void operator=(Globals const&) = delete;

    static Globals& getInstance()
    {
        static Globals   instance; // Guaranteed to be destroyed.
                              // Instantiated on first use.
        return instance;
    }


	sf::Texture& getTexture(Color c, Value val);
	std::string getName(Value val) ;
    sf::Font& getFont() ;
    sf::SoundBuffer& getAudio(int i);
private:
	Globals();
	
   std::string names[gift + 1];
   sf::Font font;
   sf::Texture textures[gift + 1]; 
   sf::Texture TopBar[thief];
   sf::Texture greenT[2];

   sf::SoundBuffer audio[regularlGift + 1];
 
    void initNames();
    void initFonts();
    void initTextures();
    void initSound();

};

sf::Vector2f convertor(Location place);
