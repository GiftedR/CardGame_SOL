#pragma once
#include "../olcPGE.h"
class UIBase
{
public:
	UIBase(olc::PixelGameEngine* pgepointer) { pge = pgepointer; };
	virtual void drawSelf() = 0;
protected:
	olc::vi2d size = { 160, 30 };
	olc::vi2d position = { 0,0 };
	olc::PixelGameEngine* pge;
};

