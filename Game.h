//
// Created by Almog on 07/06/2018.
//

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



class Game {
    int max_players;
    int number_of_players;
    Player** player_array;
    bool isFull()const;
    bool playerExist(const char* player_name)const;
public:
    Game(int maxPlayer);
    ~Game();
    GameStatus addPlayer(const char* playerName,const char* weaponName,
    Target target,int hit_strenth);
    GameStatus nextLevel(const char* playerName);
    GameStatus makeStep(const char* playerName);
    GameStatus addLife(const char* playerName);
    GameStatus addStrength(const char* playerName, int strengthToAdd);
    bool removeAllPlayersWithWeakWeapon (int weaponStrength);
    GameStatus fight(const char* playerName1, const char* playerName2);
    friend ostream& operator<<(ostream& os, Game& game);
};





#endif //MTM_EX4_CALL_OF_MATAM_DUTIES_GAME_H
