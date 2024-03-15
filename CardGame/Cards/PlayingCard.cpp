#include "PlayingCard.h"

PlayingCard::PlayingCard(std::string rank, std::string suit)
{
    cardRank = rank;
    cardSuit = suit;
    getRankAtlas();
    getSuitAtlas();
    getCardTextures();
}

std::string PlayingCard::getRank(){return cardRank;}

std::string PlayingCard::getSuit(){return cardSuit;}

int PlayingCard::getRankAtlas()
{
    switch (cardRank[0])
    {
    case 'A':
        rankAtlas[0] = 0;
        break;
    case 'J':
        rankAtlas[0] = 10;
        cardValue = 10;
        break;
    case 'Q':
        rankAtlas[0] = 11;
        cardValue = 10;
        break;
    case 'K':
        rankAtlas[0] = 12;
        cardValue = 10;
        break;
    default:
        rankAtlas[0] = int(cardRank[0]) - 49;
        cardValue = rankAtlas[0];
        break;
    }
    return rankAtlas[0];
}

int PlayingCard::getSuitAtlas()
{
    switch (cardSuit[0])
    {
    case 'C':
        rankAtlas[1] = 1;
        suitAtlas = 0;
        break;
    case 'D':
        rankAtlas[1] = 0;
        suitAtlas = 1;
        break;
    case 'H':
        rankAtlas[1] = 0;
        suitAtlas = 2;
        break;
    case 'S':
        rankAtlas[1] = 1;
        suitAtlas = 3;
        break;
    default:
        rankAtlas[1] = -1;
        suitAtlas = -1;
        break;
    }

    return suitAtlas;
}

void PlayingCard::getCardTextures()
{
    bg_Card = std::make_unique<olc::Sprite>(bgFile);
    bg_Rank = std::make_unique<olc::Sprite>(rankFile);
    bg_Suit = std::make_unique<olc::Sprite>(suitFile);
}

int PlayingCard::getCardValue()
{
    switch (cardRank[0])
    {
    case 'A':
        // TODO: Impliment 1 or 11 function
        return 1;
        break;
    case 'J':
        return 10;
        break;
    case 'Q':
        return 10;
        break;
    case 'K':
        return 10;
        break;
    default:
        return std::stoi(cardRank);
        break;
    }
}


std::string PlayingCard::toString()
{
    return cardRank + " of " + cardSuit;
}

void PlayingCard::drawSelf(olc::PixelGameEngine* pge)
{
    pge->SetPixelMode(olc::Pixel::MASK);

    pge->DrawSprite(position, bg_Card.get()); // Draw Card BG
    pge->DrawPartialSprite(position + olc::vi2d(27, 53), bg_Suit.get(), olc::vi2d(suitAtlas * 70, 0), olc::vi2d(70, 70)); // Draw Card Suit
    pge->DrawPartialSprite(position + olc::vi2d(10, 10), bg_Rank.get(), olc::vi2d(rankAtlas[0] * 22, rankAtlas[1] * 60), charSize); // Draw Card Value
    pge->DrawPartialSprite(position + olc::vi2d(94, 138), bg_Rank.get(), olc::vi2d(rankAtlas[0] * 22, (rankAtlas[1] * 60) + 30), charSize); // Draw Flipped Card Value

    pge->SetPixelMode(olc::Pixel::NORMAL);
}