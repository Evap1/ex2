#include "Player.h"
#include "utilities.h"

Player::Player(const char* name, int maxHP, int force) :
        m_name(name),
        m_level(DEFAULT_LEVEL),
        m_force(force > 0 ? force : DEFAULT_FORCE),
        m_maxHP(maxHP > DEFAULT_MAX_HP ? maxHP : DEFAULT_MAX_HP),
        m_HP(maxHP > DEFAULT_MAX_HP ? maxHP : DEFAULT_MAX_HP),
        m_coins(DEFAULT_COINS)
        {}


void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}

void Player::levelUp()
{
    if (m_level < 10) m_level++;
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(const int add)
{
    if (add < 0) return;
    m_force+=add;
}

void Player::heal(const int add)
{
    if (add < 0) return;

    if ((m_HP+add) <= m_maxHP){
        m_HP += add;
    }
    else m_HP = m_maxHP;

}

void Player::damage(const int substruct)
{
    if (substruct < 0) return;

    if (m_HP - substruct >= 0){
        m_HP -= substruct;
    }
    else m_HP = 0;
}

bool Player::isKnockedOut() const
{
    if (m_HP == 0) return true;
    else return false;
}

void Player::addCoins(const int add)
{
    if ( add < 0 ) return;
    m_coins += add;
}

bool Player::pay(int payment)
{
    if (payment < 0) return true; //////////////
    if (m_coins - payment >= 0){
        m_coins -= payment;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const
{
    return (m_force + m_level);
}