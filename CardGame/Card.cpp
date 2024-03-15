#include "Card.h"

Card::Card()
{
    getCardTextures();
}


std::string Card::toString()
{
    return "A Blank Card";
}


int Card::getCardValue()
{
    return cardValue;
}

void Card::cardAction()
{
}

void Card::getCardTextures()
{
    bg_Card = std::make_unique<olc::Sprite>(bgFile);
}

void Card::drawSelf(olc::PixelGameEngine* pge)
{
    pge->SetPixelMode(olc::Pixel::MASK);
    pge->DrawSprite(position, bg_Card.get()); // Draw Card BG
    pge->SetPixelMode(olc::Pixel::NORMAL);
}

void Card::setPosition(olc::vi2d newpos)
{
    position = newpos;
}
