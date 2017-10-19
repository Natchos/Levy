#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "TimedText.cpp"
#include "Console_Log.hpp"
#include "2FloatVector.hpp"

//An onsreen/inwindow console log. Display a customizable amount of lines(default 10 lines) of text. Messages auto-expire after customizable amount of seconds and are deleted
//after the max amount is filled.

class ScreenLog
{
private:

	//Max amount of lines that can be displayed. Overflowing messages deletes the oldest message.
	int Max_Lines;
	
	//Font. Set in ctor
	sf::Font LogFont;

	//Message lifetime in milliseconds
	float Lifetime;

	Vector2D WindowDimensions;
public:
	bool Initialize(float lifetime = 10000, int max_Lines = 10, Vector2D Wndsize = Vector2D(840,600));

	//Singleton design
	static ScreenLog* Instance();

	//Title says it all. Rearranges the On-screen positions of the text objects aswell.
	void AddMessage(std::string msg);

	//Change if windows resolution/size is changed.
	void setWindowSize();

	//The actual text messages
	std::vector<TimedText> Lines;

	//Update. Takes care of deletion and moving the objects
	void Update();

	//Called by the GraphicsManager. Sends the text objects to be rendered by the graphics manager.
	std::vector<sf::Text*> SendListToRender();
};