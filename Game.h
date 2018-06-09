
#ifndef MTM_EX4_CALL_OF_MATAM_DUTIES_GAME_H
#define MTM_EX4_CALL_OF_MATAM_DUTIES_GAME_H

#include "Player.h"

enum GameStatus
{
    INVALID_PARAM,
    NAME_ALREADY_EXISTS,
    GAME_FULL,
    NAME_DOES_NOT_EXIST,
    FIGHT_FAILED,
    SUCCESS
};

//-----------------------------------------------------------------------//
//                          CLASS GAME:                                  //
//-----------------------------------------------------------------------//

class Game {
    int max_players;
    int number_of_players;
    Player** player_array;


//-----------------------------------------------------------------------//
//                        PRIVATE METHODS:                               //
//-----------------------------------------------------------------------//

/**
 * isFull
 *
 * @return
 * True - Game is full.
 * False - Game is not full.
*/
bool isFull()const;

/**
 * playerExist
 *
 * @param player_name - Name of the player to check if exists.
 *
 * @return
 * True - Player with given name exists.
 * False - Player with given name does not exists.
 */
bool playerExist(const char* player_name)const;

/**
 * removePlayer
 *
 * Removing player from the game.
 *
 * @param player -  Player to remove.
 */
void removePlayer(const Player& player);

/**
 * getPlayerIndexByName
 *
 * @param playerName - Name of the player to get its index.
 *
 * @return
 * Index of the player with the given name.
 * If not found returns -1.
 */
int getPlayerIndexByName(const char *playerName)const;

/**
 * swap
 *
 * Swaping to players.
 *
 * @param player1_ptr - Pointer of first player.
 * @param player2_ptr - Pointer of second player.
 */
void swap(Player* player1_ptr, Player* player2_ptr);

/**
 * sortPlayers
 *
 * Sorting (bubble sort) players array (only the real players) by name.
 */
void sortPlayers();

//-----------------------------------------------------------------------//
//                         PUBLIC METHODS:                               //
//-----------------------------------------------------------------------//

public:

/**
 * Constructor
 *
 * @param maxPlayer - Max player of the game.
 */
Game(int maxPlayer);

/**
 * Destructor
 */
~Game();

/**
 * addPlayer
 *
 * Adding player to game.
 *
 * @param playerName - Name of the player.
 * @param weaponName - Name of player's weapon.
 * @param target - Target of player's weapon.
 * @param hit_strength - Strength of player's weapon.
 *
 * @return
 * GAME_FULL - Game is full.
 * NAME_ALREADY_EXISTS - Player with that name already exists.
 * SUCCESS - Player added successfully.
 *
 */
GameStatus addPlayer(const char* playerName,const char* weaponName,
Target target,int hit_strenth);

/**
 * nextLevel
 *
 * Increasing the level of player with given name by 1.
 *
 * @param playerName - Name of player to increase its level.
 *
 * @return
 * NAME_DOES_NOT_EXIST - Player with given name does not exist.
 * SUCCESS - Player's level increased successfully.
 */
GameStatus nextLevel(const char* playerName);

/**
 * makeStep
 *
 * Increasing position of player with given name by 1.
 *
 * @param playerName - Name of the player to increase its position.
 *
 * @return
 * NAME_DOES_NOT_EXIST - Player with given name does not exist.
 * SUCCESS - Player's position increased successfully.
 */
GameStatus makeStep(const char* playerName);

/**
 * addLife
 *
 * Increasing life of player with given name by 1.
 *
 * @param playerName - Name of the player to increase its life.
 *
 * @return
 * NAME_DOES_NOT_EXIST - Player with given name does not exist.
 * SUCCESS - Player's life increased successfully.
 */
GameStatus addLife(const char* playerName);

/**
 * addStrength
 *
 * Increasing strength of player with given name by given amount.
 *
 * @param playerName - Name of the player to increase its strength.
 * @param strengthToAdd - Amount to increase.
 *
 * @return
 * INVALID_PARAM - Given amount is a negative number.
 * NAME_DOES_NOT_EXIST - Player with given name does not exist.
 * SUCCESS - Player's strength increased successfully.
 */
GameStatus addStrength(const char* playerName, int strengthToAdd);

/**
 * removeAllPlayersWithWeakWeapon
 *
 * Removes all players with weapon weaker than given amount.
 *
 * @param weaponStrength - Amount.
 *
 * @return
 * True - Players removed.
 * False - Players not removed.
 */
bool removeAllPlayersWithWeakWeapon (int weaponStrength);

/**
 * fight
 *
 * Managing a fight between two players.
 *
 * @param playerName1 - First player in the fight.
 * @param playerName2 - Second player in the fight.
 *
 * @return
 * NAME_DOES_NOT_EXIST - At least one of the given names does not match any
 * player.
 */
GameStatus fight(const char* playerName1, const char* playerName2);

/**
 * operator<<
 *
 * @param os - Stream to concatenate to.
 * @param game - Game to print its details.
 *
 * @return
 * Stream of game details.
 */
friend ostream& operator<<(ostream& os, Game& game);
};

#endif //MTM_EX4_CALL_OF_MATAM_DUTIES_GAME_H
