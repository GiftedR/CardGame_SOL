#pragma once
#include "UIClickable.h"
class UIButton : public UIClickable
{
public:
	UIButton(olc::PixelGameEngine* pgepointer, olc::vi2d pos, olc::vi2d btnsize, ClickActions* clspoint, int(ClickActions::*fpoint)()) : UIClickable(pgepointer, clspoint, fpoint) { position = pos; size = btnsize; };
	void drawSelf() override;
	olc::vi2d getStringCenter(std::string buttontext, olc::vi2d position, olc::vi2d size);
	std::string buttonText = "";
};

