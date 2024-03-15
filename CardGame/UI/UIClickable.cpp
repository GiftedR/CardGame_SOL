#include "UIClickable.h"

bool UIClickable::isHoveringOver()
{
	if (pge == nullptr) { return false; }
	olc::vi2d mousePos = pge->GetMousePos();
	return (mousePos.x >= position.x && mousePos.y >= position.y) && (mousePos.x <= position.x + size.x && mousePos.y <= position.y + size.y);
}

bool UIClickable::doClickAction()
{
	return (cls->*fp)();
}