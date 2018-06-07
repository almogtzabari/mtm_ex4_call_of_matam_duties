//
// Created by Almog on 07/06/2018.
//

#include "Game.h"
#include "Player.h"

Game::Game(int maxPlayer) : max_players(maxPlayer),
                            player_array( new Player* [maxPlayer]){
    for (int i=0;i<maxPlayer;i++) {
        player_array[i]= nullptr;
    }
}

Game::~Game() {
    delete[] player_array;
}

GameStatus Game::addPlayer(const char *playerName, const char *weaponName,
                           Target target, int hit_strenth) {
    for (int i = 0; i < max_players; i++) {
        if(player_array[i]== nullptr){
            Weapon weapon=Weapon(weaponName,target,hit_strenth);
            Player new_player=Player(playerName,weapon);
            return SUCCESS;
        }
        if (player_array[i]->isPlayer(playerName)) {
            return NAME_ALREADY_EXSISTS;
        }
    }
    return GAME_FULL;
}
