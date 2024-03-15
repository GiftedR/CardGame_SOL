#pragma once
#include "../Card.h"
class PlayingCard : public Card
{
public:
	PlayingCard(std::string rank, std::string suit);

	std::string getRank();
	std::string getSuit();
	int getRankAtlas();
	int getSuitAtlas();

	void getCardTextures() override;
	int getCardValue() override;

	std::string toString() override;
	void drawSelf(olc::PixelGameEngine* pge);
protected:
	std::string rankFile = "Assets/CardRanks.png";
	std::string suitFile = "Assets/CardSuits.png";
	int rankAtlas[2] = { -1, 0 };
	int suitAtlas = -1;
	const olc::vi2d charSize = olc::vi2d(22, 30);
private:
	std::unique_ptr<olc::Sprite> bg_Rank;
	std::unique_ptr<olc::Sprite> bg_Suit;

	std::string cardRank;
	std::string cardSuit;
};

