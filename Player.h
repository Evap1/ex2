//
// Created by Eva Poluliakhov on 03/12/2022.
//
#include <string>
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


class Player{
private:

    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_LEVEL = 1;
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_COINS = 0;

public:
    /*
     *C'tor of Player:
     *
     * @param name- Player's name.
     * @param maxHP - Setting maxHP for the player. Set to DEFAULT_MAX_HP by default and changes
     *                only if the param is greater.
     * @param force - Setting force for the player. Set to DEFAULT_FORCE by default and changes
     *                only if the param is positive.
     * @return
     *      New instance of Player.
    */
    Player(const char* name, int maxHP = DEFAULT_MAX_HP , int force = DEFAULT_FORCE);
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator = (const Player& other) = default;

    /*
    * Prints the details of the player, using function from utility.h
    */
    void printInfo() const;

    /*
    * Increases player's level by one level with a limit of 10.
    */
    void levelUp();
    /*
    * @return:
    * Player's current level.
    */
    int getLevel() const;
    /*
    * Increases the player's force by the argument value.
    * @param add - the amount of force to add to player's m_force.
    */
    void buff(const int add);
    /*
    * Increases the player's HP by the argument value with a limit of m_maxHP.
    * @param add - the amount of HP to add to player's m_HP.
    */
    void heal(const int add);
    /*
    * Decreases the player's HP by the argument value with a limit of 0.
    * @param substruct - the amount of HP to substruct from player's m_HP.
    */
    void damage(const int substruct);
    /*
    * @return: True - in case the player has positive m_HP.
    *          False - in case the player has 0 m_HP.
    */
    bool isKnockedOut() const;
    /*
    * Increases the player's coins by the argument value.
    * @param add - the amount of coins to add to player's m_coins.
    */
    void addCoins(const int add);
    /*
    * Decreases the player's coins by the argument value.
    * @param add - the amount of coins to add to player's m_coins.
    * @return: True - if payment has been accomplished.
    *          False - if payment failed (meaning player has not enough coins).
    */
    bool pay (const int payment);
    /*
    * Sums player's force and level to an attack param.
    * @return: Player's attack strength.
    */
    int getAttackStrength() const;
};


#endif //EX2_PLAYER_H
