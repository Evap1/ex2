//
// Created by Eva Poluliakhov on 04/12/2022.
//
#include "Card.h"

Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(stats) {}

void Card::applyEncounter(Player &player) const
{
    switch (m_effect)
    {
        case (CardType::Battle) :
        {
            bool win = false;
            if (player.getAttackStrength() >= m_stats.force)
            {
                win = true;
                player.levelUp(); //
                player.addCoins(m_stats.loot); //
            }
            else
            {
                player.damage(m_stats.hpLossOnDefeat);
            }
            printBattleResult(win);
            break;
        }
        case (CardType::Heal) :
        {
            if (player.pay(m_stats.cost))
            {
                player.heal(m_stats.heal);
            }
            break;
        }
        case (CardType::Treasure) :
        {
            player.addCoins(m_stats.loot);
            break;
        }
        case (CardType::Buff) :
        {
            if (player.pay(m_stats.cost))
            {
                player.buff(m_stats.buff);
            }
            break;
        }
    }
}

void Card::printInfo() const
{
    switch (m_effect)
    {
        case CardType::Battle:
        {
            printBattleCardInfo(m_stats);
            break;
        }
        case CardType::Treasure:
        {
            printTreasureCardInfo(m_stats);
            break;
        }
        case CardType::Buff:
        {
            printBuffCardInfo(m_stats);
            break;
        }
        case CardType::Heal:
        {
            printHealCardInfo(m_stats);
            break;
        }
    }
}





