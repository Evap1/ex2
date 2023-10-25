//
// Created by Eva Poluliakhov on 10/12/2022.
//
#include "Mtmchkin.h"



Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
        m_player(playerName),
        m_cardsArray(new Card[numOfCards]),
        m_numOfCards(numOfCards),
        m_currentCard(DEFAULT_FIRST_CARD),
        m_status(GameStatus::MidGame)
{
        for ( int i = 0; i < numOfCards; i++)
        {
            m_cardsArray[i] = cardsArray[i];
        }
}

Mtmchkin::Mtmchkin(const Mtmchkin& other) :
    m_player(other.m_player),
    m_cardsArray(new Card[other.m_numOfCards]),
    m_numOfCards(other.m_numOfCards),
    m_currentCard(DEFAULT_FIRST_CARD),
    m_status(other.m_status)
{
    for (int i = 0; i < m_numOfCards ; i++)
    {
        m_cardsArray[i] = other.m_cardsArray[i];
    }
}

Mtmchkin & Mtmchkin::operator=(const Mtmchkin &other)
{
    if (this == &other) return *this;

    m_player = other.m_player;
    m_numOfCards = other.m_numOfCards;
    m_currentCard = other.m_currentCard;
    m_status = other.m_status;

    if (m_cardsArray == other.m_cardsArray){
        return *this;
    }
    else
    {
        delete[] m_cardsArray;
        m_cardsArray = new Card[other.m_numOfCards];
        for (int i = 0; i < other.m_numOfCards; i++)
        {
            m_cardsArray[i] = other.m_cardsArray[i];
        }
        return *this;
    }
}


Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
}

void Mtmchkin::playNextCard()
{
    int current = (m_currentCard) % m_numOfCards;
    m_cardsArray[current].printInfo();
    m_cardsArray[current].applyEncounter(m_player);
    m_player.printInfo();
    m_currentCard++;

    if (m_player.isKnockedOut())
    {
        m_status = GameStatus::Loss;
    }
    else
    {
       if (m_player.getLevel() == WIN_LEVEL)
       {
           m_status = GameStatus::Win;
       }
    }
}

bool Mtmchkin::isOver() const
{
    if (m_status == GameStatus::MidGame)
    {
        return false;
    }
    return true;
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_status;
}










