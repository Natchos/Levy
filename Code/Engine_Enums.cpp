#pragma once

/*This is a list of all the functional object types in the engine
* If you need more object types, just enter them here and add appropriate code in the engine
*/
enum Object_Type
{
	Actor,
	Player,
	Obstacle,
};

/* All the states that the engine can be in are entered here.
* More states should not be needed, but if they do enter them here.
*/
enum GameState
{
	Initializing,
	Playing,
	Paused,
	Main_Menu,
	Exiting
};

/* Used for deciding in what order different graphical elements should be drawn.
* Example, UI elements should be drawn last, and background should be drawn first
* Effects can also be drawn on top of actors, and would therefore be HighPrio.
*/
enum GFXDrawPriority
{
	Background = 0,
	LowPrio_Normal = 1,
	HighPrio_Normal = 2,
	UI = 3,
	DoNotDraw = 4
};

/* Used for setting the priority level of a log message, when printing/sending this to the log
* Default to be used is information.
* Normal means problems. Severe means things that could fuck up the computer.
* Crash is a last-ditch effort to give some information when the engine crashes.
*/
enum LogPriority
{
	Routine = 0,
	Information = 1,
	SysInformation = 2,
	Medium = 3,
	Severe = 4,
	Crash = 5
};

/* Used for setting the music state, to select appropriate music/sounds */

enum AudioEnvironment
{
	Normal = 0,
	Calm = 1,
	Battle = 2,
	Death = 3
};