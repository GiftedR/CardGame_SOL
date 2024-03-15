#pragma once
#include "deck.h"
class Hand : public Deck
{
protected:
	int handScores[2] = {0, 0}; //Score with Aces as 1, Score with aces as 11
	olc::vi2d handPos = { 0, 0 };
	olc::vi2d cardOffset = { 0, 50 };
public:
	void updateHand();
	Hand(bool isEmpty = true);
	int getTotal();
	void renderDeck(olc::PixelGameEngine* pge, bool rendervertical = true) override;
	void setHandRenderPos(int x, int y) { setHandRenderPos(olc::vi2d(x, y)); };
	void setHandRenderPos(olc::vi2d newpos) { handPos = newpos; };
	bool formatOffset(bool rendervertical);
};

