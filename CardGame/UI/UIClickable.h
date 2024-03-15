#pragma once
#include "UIBase.h"
#include "Actions/ClickActions.h"

class UIClickable :public UIBase
{
public:
	UIClickable(olc::PixelGameEngine* pgepointer, ClickActions* clspoint, int(ClickActions::* fpoint)()) : UIBase(pgepointer) { cls = clspoint; fp = fpoint; }; // Func pointer passing method
	bool isHoveringOver();

	virtual bool doClickAction();
protected:
	ClickActions* cls;
	int(ClickActions::*fp)();
};
