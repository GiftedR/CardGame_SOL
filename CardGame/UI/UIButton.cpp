#include "UIButton.h"

void UIButton::drawSelf()
{
	pge->FillRect(position, size, olc::Pixel(64, 16, 16));
	pge->DrawString(getStringCenter(buttonText, position, size), buttonText);
}

olc::vi2d UIButton::getStringCenter(std::string buttontext, olc::vi2d position, olc::vi2d size)
{
	return (position + (size / 2.f)) - (pge->GetTextSize(buttonText) / 2.f);
}

