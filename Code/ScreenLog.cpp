#pragma once

#include "ScreenLog.hpp"

ScreenLog* ScreenLog::Instance()
{
	static ScreenLog instance;
	return &instance;
}

bool ScreenLog::Initialize(float lifetime, int max_Lines, Vector2D Wndsize)
{
	this->Max_Lines = max_Lines;
	this->Lifetime = lifetime;
	this->WindowDimensions = Wndsize;
	if(!this->LogFont.loadFromFile("Fonts/arial.ttf"))
		return false;
	return true;
}

void ScreenLog::AddMessage(std::string msg)
{
	TimedText LogMsg(sf::String(msg), LogFont);
	LogMsg.setColor(sf::Color(255,0,0,255));
	LogMsg.reset();
	Lines.resize(Lines.size() + 1);
	Lines.back() = LogMsg;
	for(int i = 0; i < Lines.size(); i++)
	{
		Lines[i].setPosition(10, (10 + 40 * i));
	}
}

void ScreenLog::Update()
{
	if(Lines.size() > 0)
	{
		if(Lines.front().getElapsedTime() > sf::milliseconds(Lifetime) || Lines.size() > Max_Lines)
		{
			Lines.erase(Lines.begin());
		}
		for(int i = 0; i < Lines.size(); i++)
		{
			Lines[i].setPosition(10, (10 + 40 * i));
		}
	}
}