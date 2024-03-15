#pragma once
#include <string>
#include <random>
#include <vector>
#include "Card.h"
#include "Cards/PlayingCard.h"

using namespace std;
class Deck
{
public:
	Deck(bool isEmpty = false);

	void populateDeck();
	void emptyDeck();
	void shuffleDeck();
	Card* drawCard();
	void resetDeck(bool shouldshuffle = false);

	void addCard(Card* incomingcard);
	void addPlayingCard(string rank, string suit);
	virtual void renderDeck(olc::PixelGameEngine* pge, bool rendervertical = true);
	void printContents();
protected:
	vector<Card*> deckItems;
};

