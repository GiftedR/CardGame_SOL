#define OLC_PGE_APPLICATION

#pragma once
#include <iostream>
#include "olcPGE.h"
#include "deck.h"
#include "Cards/PlayingCard.h"
#include "UI/UIBase.h"
#include "UI/UIButton.h"
#include "UI/Actions/ClickActions.h"
#include "Hand.h"

using namespace std;

class cardApp : public olc::PixelGameEngine
{
public:
	// CONSTRUCTOR
	cardApp(std::string title, int targetFPS) {
		sAppName = title;

		fTargetFPSTime = 1.f / float(targetFPS);
	}
	~cardApp() {
		for (int i = 0; i < uiClickable.size(); i++) {
			delete uiClickable[i];
		}
	}
public:
	bool resetGame() {
		playerHand.setHandRenderPos(30, 30);
		dealerHand.setHandRenderPos(482, 30);
		buttonWork.resetGame();
		hasChanges = true;
		return true;
	}

	void queueChange() {
		hasChanges = true;
	}

	bool OnUserCreate() override {
		uiClickable[0]->buttonText = "Stay";
		uiClickable[1]->buttonText = "Hit";
		uiClickable[2]->buttonText = "Reset";
		return resetGame();
	}

	void checkClickObjects() {
		for (int i = 0; i < uiClickable.size(); i++) {
			if (uiClickable[i]->isHoveringOver() && GetMouse(0).bPressed) {
				gameStatus = uiClickable[i]->doClickAction();
				queueChange();
			}
		}
		if (gameStatus != 0 && !hasChanges) {
			gameStatus = buttonWork.checkWinCondition();
			doWinCondition();
		}
	}

	void doWinCondition(){
		if (gameStatus == 1) {
			DrawString(olc::vi2d(320 - GetTextSize("Player Wins!").x / 2.f, 300), "Player Wins!");
		}
		else if (gameStatus == 2) {
			DrawString(olc::vi2d(320 - GetTextSize("Dealer Wins!").x / 2.f, 300), "Dealer Wins!");
		}
		else {
			DrawString(olc::vi2d(320 - GetTextSize("HUH?").x, 300), "HUH?");
		}
	}

	void renderUI() {
		for (int i = 0; i < uiClickable.size(); i++) {
			uiClickable[i]->drawSelf();
		}

	}
public:
	bool OnUserUpdate(float fElapsedTime) override {
		checkClickObjects();
		fAccTime += fElapsedTime;
		if (fAccTime >= fTargetFPSTime) {
			fAccTime -= fTargetFPSTime;
			fElapsedTime = fTargetFPSTime;
		}
		else {
			return true; 
		}
		if (!hasChanges) {
			return true;
		}
		Clear(olc::PixelF(0.05f,0.3f,0.3f));

		playerHand.renderDeck(this, true);
		dealerHand.renderDeck(this, true);

		renderUI();

		hasChanges = false;
		return true;
	}
private:
	vector<UIButton*> uiClickable = { 
		new UIButton(this, olc::vi2d(256, 30), olc::vi2d(128, 32), &buttonWork, &ClickActions::stayPlayerCard),
		new UIButton(this, olc::vi2d(256, 96), olc::vi2d(128, 32), &buttonWork, &ClickActions::hitPlayerCard),
		new UIButton(this, olc::vi2d(256, 162), olc::vi2d(128, 32), &buttonWork, &ClickActions::resetGame)

	};
	ClickActions buttonWork = ClickActions(&playerHand, &dealerHand, &gameDeck);
	bool hasChanges = false;
	int gameStatus = 0;

	Deck gameDeck = Deck();
	Hand playerHand = Hand(true);
	Hand dealerHand = Hand(true);

	float fTargetFPSTime = 1.f / 165.f;
	float fAccTime = 0.f;
};



int main()
{
	bool doSettings = true;
	int targetFramerate = 165;

	//TODO: Impliment Card Graphics
	cardApp mainWindow("Forced Luck", targetFramerate);
	if (mainWindow.Construct(640, 360, 2, 2, false, false)) mainWindow.Start();
	return 0;
}
