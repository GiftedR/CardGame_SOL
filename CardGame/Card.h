#pragma once
#include <string>
#include "olcPGE.h"

class Card
{
public:
	Card();
	virtual std::string toString();
	virtual void cardAction();
	virtual void getCardTextures();
	virtual int getCardValue();
	virtual void drawSelf(olc::PixelGameEngine* pge);
	virtual void setPosition(int x, int y) { setPosition(olc::vi2d(x, y)); };
	virtual void setPosition(olc::vi2d newpos);
protected:
	int cardValue = 0;
	std::string bgFile = "Assets/PlayingCardBG.png";
	std::unique_ptr<olc::Sprite> bg_Card;
	olc::vf2d position = { 0, 0 };
};

