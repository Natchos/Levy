#pragma once
#include <SFML\Graphics.hpp>
#include "Watch.hpp"
#include "2FloatVector.hpp"
#include "Engine_Enums.cpp"
//A very basic graphical entity.
//Should essentially be used for single-framed objects such as static rocks, backgrounds etc.
//Since it does inherit from SFMLs Sprite class it already contain a lot of functionality(scale, position, color mixing, origin etc), if needed.
class Basic_Render_Entity : public sf::Sprite
{
public:

	//Passing by ref allows you to modify the watch as needed through internal functions.
	Watch& getWatch();
	//Allows you to check/set visibility of the object.
	bool getVisible();
	void setVisible(bool newVisible);
	//Allows you to flag for deletion
	void setDeleteFlag(bool nVal = true);
	//Get and set Draw Prio
	GFXDrawPriority getDrawPrio();
	void setDrawPrio(GFXDrawPriority newPriority);

	//Always called, if this object is visible. Overrides are allowed.
	virtual void GFX_Update();
protected:
	//Used for timing functions, or when a deriavative might need it for animating and such.
	Watch internalTimer;
	//If this is set to false, the entity will not be rendered.
	bool Visible;
	//The drawing priority of this object. Prio goes from Low(Background) to High(UI). Prio determines what will be layered on top.
	GFXDrawPriority drawPrio;
	//Flag for deletion
	bool Delete;
	
};