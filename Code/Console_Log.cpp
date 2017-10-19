#pragma once
#include "Console_Log.hpp"

Console_Log* Console_Log::Instance()
{
	static Console_Log instance;
	return &instance;
}

bool Console_Log::Initialize()
{
	LogLines.clear();
	Log("Logger initalized and cleaned.", LogPriority::SysInformation);
	return true;
}

void Console_Log::Log(std::string Message, LogPriority Prio, bool Write_To_Console)
{
	std::string Log_Message = std::to_string(Log_Length());
	//If number of line numbers go over 10^4 this function will start functioning erratically(although, we probs got bigger problems at that point...).
	Log_Message.resize(4);
	Log_Message.append(" " + getSysTime());
	//If its long enough for E-Celebs and SJWs, its good enough for system LogLines!
	Message.resize(62);
	Log_Message.append(Message);
	Log_Message.append(std::to_string((int)Prio) + "\n");
	//Output to console if that is wished.
	if(Write_To_Console)
	{
		std::cout << Log_Message;
	}
	//Add the string to the Log_Message
	LogLines.push_back(Log_Message);
}

bool Console_Log::DeleteMessageByLineNumber(int LineNumber)
{
	//If the requested line exists
	if(LineNumber <= LogLines.size())
	{
		LogLines.erase(LogLines.begin() + LineNumber-1);
		return true;
	}
	else
		return false;
}

bool Console_Log::DeletePreviousMessage()
{
	LogLines.pop_back();
	return true;
}

bool Console_Log::DeletePreviousMessagePrio(LogPriority Prio)
{
	//reverse iterator, since the latest LogLines are at the end.
	for(std::vector<std::string>::reverse_iterator iter = LogLines.rbegin(); iter != LogLines.rend(); iter++)
	{
		//Extracts the Priority Level integer and compares it to the priority level.
		int MSG_Prio = (int)iter->substr(iter->size()-1,1).c_str();
		if((LogPriority)MSG_Prio == Prio)
		{
			//Target found, erase and exit
			LogLines.erase(iter.base());
			return true;
		}
	}
	//No message with given priority is currently in the log buffer/message log. Exit with false
	return false;
}

std::string Console_Log::GetMessageByLineNumber(int LineNumber)
{
	return LogLines[LineNumber];
}

std::vector<std::string> Console_Log::GetLogLinesPrio(LogPriority Prio)
{
	//Creates a vector to use to temporarily store the objects we want to return.
	std::vector<std::string> Str_Vec;
	for(std::vector<std::string>::iterator iter = LogLines.begin(); iter != LogLines.end(); iter++)
	{
		//Extracts the Priority Level integer and compares it to the priority level.
		int MSG_Prio = (int)iter->substr(iter->size()-1,1).c_str();
		if((LogPriority)MSG_Prio == Prio)
		{
			Str_Vec.push_back(*iter);
		}
	}
	return Str_Vec;
}

int Console_Log::Log_Length()
{
	return LogLines.size();
}


std::string Console_Log::getSysTime(bool Date)
{
	time_t rawtime;
	struct tm timetrans;
	time(&rawtime);
	localtime_s(&timetrans, &rawtime);
	std::string Timestring;
	char TimeBuffer[32];
	asctime_s(TimeBuffer, 32, &timetrans);
	Timestring = TimeBuffer;
	//Extracts the digits for the actual numbers, so we don't have to reprint the day and year everytime.
	if(!Date)
	{
		Timestring = Timestring.substr(11,8) + "\t";
	}
	Timestring.replace(Timestring.find(':'),1,".");
	Timestring.replace(Timestring.find(':'),1,".");
	Timestring.pop_back();
	Timestring += " ";
	return Timestring;
}

bool Console_Log::Write_Log_File()
{
	std::ofstream FileStream;
	//Create log file, with date/time of creation.
	std::string filename = "Homebrew log " + getSysTime(true) + ".txt";
	FileStream.open(filename);
	if(!FileStream)
	{
		std::cerr<< "Failed creating logfile. Exiting.";
		exit(0);
	}
	for(std::vector<std::string>::iterator iter = LogLines.begin(); iter != LogLines.end(); iter++)
	{
		//Write line to file if the file is still correctly open
		if(FileStream.is_open())
			FileStream << *iter;
	}
	//Close file
	FileStream.close();
	//Mission accomplished, return.
	return true;
}