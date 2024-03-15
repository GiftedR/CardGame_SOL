#include "deck.h"

Deck::Deck(bool isEmpty)
{
	if (isEmpty) { return; }
	populateDeck();
	shuffleDeck();
}

void Deck::populateDeck()
{
	for (int si = 0; si < 4; si++) { // Outer Loop - Suit
		string suitName = "HUH?";

		switch (si)
		{
		case 0:
			suitName = "Clubs";
			break;
		case 1:
			suitName = "Diamonds";
			break;
		case 2:
			suitName = "Hearts";
			break;
		case 3:
			suitName = "Spades";
			break;
		default:
			break;
		}

		for (int ri = 1; ri <= 13; ri++) { // Inner Loop - Rank
			string rankName = "WAIT?";
			switch (ri)
			{
			case 1:
				rankName = "Ace";
				break;
			case 11:
				rankName = "Jack";
				break;
			case 12:
				rankName = "Queen";
				break;
			case 13:
				rankName = "King";
				break;
			default:
				rankName = to_string(ri);
				break;
			}

			deckItems.push_back(new PlayingCard(rankName, suitName));
		}
	}
}

void Deck::emptyDeck()
{
	for (Card* c : deckItems) {
		delete c;
	}
	deckItems.clear();
}

void Deck::shuffleDeck()
{
	auto rng = default_random_engine();
	rng.seed(time(NULL));
	shuffle(deckItems.begin(), deckItems.end(), rng);
}

Card* Deck::drawCard()
{
	Card* backCard;
	backCard = deckItems.back();
	deckItems.pop_back();
	return backCard;
}

void Deck::resetDeck(bool shouldshuffle)
{
	emptyDeck();
	populateDeck();
	if (shouldshuffle) { shuffleDeck(); }
}

void Deck::addCard(Card* incomingcard)
{
	deckItems.push_back(incomingcard);
}

void Deck::addPlayingCard(string rank, string suit)
{
	deckItems.push_back(new PlayingCard(rank, suit));
}

void Deck::renderDeck(olc::PixelGameEngine* pge, bool rendervertical)
{
	for (Card* c : deckItems) {
		c->drawSelf(pge);
	}
}

void Deck::printContents()
{
	for (Card* c : deckItems) {
		cout << c->toString() << endl;
	}
}
