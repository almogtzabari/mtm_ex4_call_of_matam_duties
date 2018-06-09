
#ifndef MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H
#define MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H

#include "Weapon.h"
#include <iostream>
#include <cstring>
using std::ostream;

//-----------------------------------------------------------------------//
//                          CLASS PLAYER:                                //
//-----------------------------------------------------------------------//

class Player {
    char* name;
    int level;
    int life;
    int strength;
    Weapon weapon;
    int position;

//-----------------------------------------------------------------------//
//                        PRIVATE METHODS:                               //
//-----------------------------------------------------------------------//

/**
 * attack
 *
 * Attacks a given player.
 *
 * @param player - Player to attack.
 */
void attack(Player& player)const;

/**
 * hitLife
 *
 * Hits life of given player.
 *
 * @param player - Player taking the damage.
 */
void hitLife(Player& player)const;

/**
 * hitLevel
 *
 * Hits level of given player.
 *
 * @param player - Player taking the damage.
 */
void hitLevel(Player& player)const;

/**
 * hitStrength
 *
 * Hits strength of given player.
 *
 * @param player - Player taking the damage.
 */
void hitStrength(Player& player)const;

//-----------------------------------------------------------------------//
//                         PUBLIC METHODS:                               //
//-----------------------------------------------------------------------//

public:

/**
 * Default constructor
 */
Player();

/**
 * Copy constructor
 *
 * @param player - Player to copy.
 */
Player(const Player& player);

/**
 * Constructor
 *
 * @param name - Name of the player.
 * @param weapon - Weapon of the player.
 */
Player(const char* name, const Weapon& weapon);

/**
 * Destructor
 *
 * Free all resources of given player.
 */
~Player();

/**
 * Operator=
 *
 * @param player - Player to assign.
 *
 * @return
 * Reference to the player after assignment.
 */
Player& operator=(const Player& player);

/**
 * nextLevel
 *
 * Increasing player's level by 1.
 *
 */
void nextLevel();

/**
 * isPlayer
 *
 * Checks if the player has the given name.
 *
 * @param playerName - Name to compare to.
 *
 * @return
 * True - Player's name is the given name.
 * False - Otherwise.
 */
bool isPlayer(const char* playerName)const;

/**
 * makeStep
 *
 * Increasing player's position by 1.
 */
void makeStep();

/**
 * addLife
 *
 * Increasing player's life by 1.
 */
void addLife();

/**
 * addStrength
 *
 * Increasing player's strength by given amount.
 *
 * @param strengthToAdd - Amount to add to player's strength.
 */
void addStrength(int strengthToAdd);

/**
 * isAlive
 *
 * Checks if the player is alive.
 *
 * @return
 * True - Player is alive.
 * False - Player is dead.
 */
bool isAlive()const;

/**
 * weaponIsWeak
 *
 * Checks if player's weapon is weaker than given amount.
 *
 * @param weaponMinStrength - Amount.
 *
 * @return
 * True - Player's weapon is weaker than given amount.
 * False - Otherwise.
 */
bool weaponIsWeak(int weaponMinStrength)const;

/**
 * fight
 *
 * @param player - Player to fight against.
 *
 * @return
 * True - Fight succeeded.
 * False - Fight failed.
 */
bool fight(Player& player);

/**
 * operator<<
 *
 * @param os - Stream to concatenate to.
 * @param player - Player to print.
 *
 * @return
 * Stream of Player details.
 */
friend ostream& operator<<(ostream& os, const Player& player);

/**
 * operator<
 *
 * @param player1 - First player.
 * @param player2 - Second player.
 *
 * @return
 * True - player1<player2
 * False - Otherwise.
 */
friend bool operator<(const Player& player1,const Player& player2);

/**
 * operator>
 *
 * @param player1 - First player.
 * @param player2 - Second player.
 *
 * @return
 * True - player1>player2
 * False - Otherwise.
 */
friend bool operator>(const Player& player1,const Player& player2);

/**
 * operator==
 *
 * @param player1 - First player to compare.
 * @param player2 - Second player to compare.
 *
 * @return
 * True - Players are equal (by comparing their names).
 * False - Otherwise.
 */
friend bool operator==(const Player& player1, const Player& player2);
};

#endif //MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H
