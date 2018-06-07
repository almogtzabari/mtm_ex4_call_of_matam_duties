//
// Created by Almog on 07/06/2018.
//

#ifndef MTM_EX4_CALL_OF_MATAM_DUTIES_GAME_H
#define MTM_EX4_CALL_OF_MATAM_DUTIES_GAME_H

#include "Player.h"

enum GameStatus
{
    INVALID_PARAM,
    NAME_ALREADY_EXSISTS,
    GAME_FULL,
    NAME_DOES_NOT_EXIST,
    FIGHT_FAILED,
    SUCCESS
};



class Game {
    int max_players;
    Player** player_array;
public:
    Game(int maxPlayer);
    ~Game();
    GameStatus addPlayer(const char* playerName,const char* weaponName,
    Target target,int hit_strenth);
    GameStatus nextLevel(const char* playerName);
};



#endif //MTM_EX4_CALL_OF_MATAM_DUTIES_GAME_H
