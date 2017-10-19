#pragma once
#include "Basic_Render_Entity.hpp"



Watch& Basic_Render_Entity::getWatch()
{
	return this->internalTimer;
}

bool Basic_Render_Entity::getVisible()
{
	return this->Visible;
}

void Basic_Render_Entity::setVisible(bool nVal)
{
	this->Visible = nVal;
}

void Basic_Render_Entity::setDeleteFlag(bool nVal)
{
	this->Delete = nVal;
}

GFXDrawPriority Basic_Render_Entity::getDrawPrio()
{
	return this->drawPrio;
}

void Basic_Render_Entity::setDrawPrio(GFXDrawPriority newPriority)
{
	this->drawPrio = newPriority;
}

void Basic_Render_Entity::GFX_Update()
{
	//Empty at this level
}
