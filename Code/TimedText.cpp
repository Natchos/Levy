#pragma once
#include <string>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include "Watch.hpp"


struct TimedText : public sf::Text, Watch
{
	TimedText() : sf::Text()
	{
	};
	TimedText(sf::String& string, const sf::Font& font, unsigned int characterSize = 15) : sf::Text(string,font,characterSize)
	{
	};
	TimedText(std::string& string, const sf::Font& font, unsigned int characterSize = 15) : sf::Text(string,font,characterSize)
	{
	};
	TimedText(const TimedText&) : sf::Text()
	{
	};
	TimedText(sf::Text& text) : sf::Text()
	{
	};
	sf::Text* getBase()
	{
		return (sf::Text*)this;
	}
};