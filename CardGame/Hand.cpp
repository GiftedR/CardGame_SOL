#include "Hand.h"

void Hand::updateHand()
{
	for (int i = 0; i < deckItems.size(); i++) {
		deckItems[i]->setPosition(handPos.x + (i * cardOffset.x), handPos.y + (i * cardOffset.y));
	}
}

Hand::Hand(bool isEmpty) : Deck(isEmpty) { formatOffset(true); }

int Hand::getTotal()
{
	handScores[0] = 0;
	handScores[1] = 0;
	for (Card* c : deckItems) {
		if (c->getCardValue() != (1 || 11)) {
			handScores[0] += c->getCardValue();
			handScores[1] += c->getCardValue();
		}
		else {
			handScores[0] += 1;
			handScores[1] += 11;
		}
	}
	if (handScores[1] > 21) {
		return handScores[0];
	}
	return handScores[1];
}

void Hand::renderDeck(olc::PixelGameEngine* pge, bool rendervertical)
{
	for (int i = 0; i < deckItems.size(); i++) {
		deckItems[i]->drawSelf(pge);
	}
	pge->DrawString(handPos + olc::vi2d(0, -10), to_string(getTotal()), olc::WHITE);
}

bool Hand::formatOffset(bool rendervertical)
{
	bool updateCard = false;

	if (rendervertical && cardOffset != olc::vi2d(0, 50)) {
		cardOffset = { 0, 50 };
		updateCard = true;
	}
	else if (!rendervertical && cardOffset != olc::vi2d(42, 0)) {
		cardOffset = { 42, 0 };
		updateCard = true;
	}
	else {
		return false;
	}

	if (updateCard) {
		updateHand();
	}
	return true;
}
