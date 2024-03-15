#pragma once
#include <iostream>
#include "../../Hand.h"

// Used for the one off button actions -1 is Loss, 0 is continue, 1 is player 1 Win, 2 is Dealer Win
class ClickActions {
public:
	ClickActions(Hand* plyhand, Hand* dealhand, Deck* maindeck) { playerHand = plyhand; dealerHand = dealhand; mainDeck = maindeck; };

	int testButtonConnection() {
		std::cout << "The callable worked!\n";
		return 0;
	}

	int hitPlayerCard() {
		playerHand->addCard(mainDeck->drawCard());
		playerHand->updateHand();
		return checkWinCondition();
	}

	int stayPlayerCard() {
		while (dealerHand->getTotal() < 17) {
			dealerHand->addCard(mainDeck->drawCard());
		}
		dealerHand->updateHand();
		return checkWinCondition();
	}

	int resetGame() {
		playerHand->emptyDeck();
		dealerHand->emptyDeck();
		mainDeck->resetDeck(true);
		playerHand->addCard(mainDeck->drawCard());
		dealerHand->addCard(mainDeck->drawCard());
		playerHand->addCard(mainDeck->drawCard());
		dealerHand->addCard(mainDeck->drawCard());
		playerHand->updateHand();
		dealerHand->updateHand();
		return checkWinCondition();
	}

	int checkWinCondition() {
		if (playerHand->getTotal() > 21) {
			return 2; //Dealer Win
		}
		else if (dealerHand->getTotal() > 21) {
			return 1; //Player Win
		}
		else if (playerHand->getTotal() == 21 && dealerHand->getTotal() != 21) {
			return 1; //Player Win
		}
		else if (playerHand->getTotal() <= dealerHand->getTotal()) {
			return 2; //Dealer Win
		}
		else {
			return 0;
		}
	}

private:
	Hand* playerHand;
	Hand* dealerHand;
	Deck* mainDeck;

};
