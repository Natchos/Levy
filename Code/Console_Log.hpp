#pragma once
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "Engine_Enums.cpp"

//This class provides a log for various messages sent from the engine. 
//Each entry/line is given a prio level(default is information) and a string aswell as a timestamp.
//The string is copied to three places: Printed to the console(enables a user to check things without interrupting a session), copied to the memory of this class in a vector
// and finally, upon exit the vector of messages is written to a log-file in text format.
class Console_Log
{
public:

	//Initalization. Doesn't do much, just sets up the vector
	bool Initialize();

	//The basic function of this class. If the last parameter is set to false, no message will be written to the console, but there will still be an entry for the
	//log file. Useful for routine messages, or debug information which is irrelevant while the engine is running.
	void Log(std::string Message, LogPriority Prio = LogPriority::Information, bool Write_To_Console = true);

	//Returns current amount of entries which are going to be write to the log file(Length of Messages).
	int Log_Length();

	//The title really says it all.
	std::string GetMessageByLineNumber(int LineNumber);
	
	//Once again, the title really says it all.
	bool DeleteMessageByLineNumber(int LineNumber);

	//Deletes the most recently entered Message.
	bool DeletePreviousMessage();

	//This deletes the most recently entered Message of the given Priority.
	bool DeletePreviousMessagePrio(LogPriority Prio);

	//Returns ALL messages of a certain Priority level, in the form of an vector of strings. The line number is appended to the string.
	std::vector<std::string> GetLogLinesPrio(LogPriority Prio);

	//Creates the actual log file
	bool Write_Log_File();

	//Adds a message
	void AddMessage(std::string  Msg);

	//Singleton design
	static Console_Log* Instance();

private:

	//Log info
	std::vector<std::string> LogLines;

	//Returns the local time in a nice format. Internal use only.
	std::string getSysTime(bool Date = false);
};