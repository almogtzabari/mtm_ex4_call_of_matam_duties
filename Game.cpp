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
            *player_array[i]=Player(playerName,weapon);
            return SUCCESS;
        }
        if (player_array[i]->isPlayer(playerName)) {
            return NAME_ALREADY_EXSISTS;
        }
    }
    return GAME_FULL;
}

GameStatus Game::nextLevel(const char *playerName) {
    for (int i=0;i<max_players;i++) {
        if(player_array[i]->isPlayer(playerName)){
            player_array[i]->nextLevel();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

GameStatus Game::makeStep(const char *playerName) {
    for (int i=0;i<max_players;i++) {
        if(player_array[i]->isPlayer(playerName)){
            player_array[i]->makeStep();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

GameStatus Game::addLife(const char *playerName) {
    for (int i=0;i<max_players;i++) {
        if(player_array[i]->isPlayer(playerName)){
            player_array[i]->addLife();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

GameStatus Game::addStrength(const char *playerName, int strengthToAdd) {
    if(strengthToAdd<0){
        return INVALID_PARAM;
    }
    for (int i=0;i<max_players;i++) {
        if(player_array[i]->isPlayer(playerName)){
            player_array[i]->addStrength(strengthToAdd);
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength) {
    bool removed=false;
    for (int i=0;i<max_players;i++) {
        if(player_array[i]->weaponIsWeak(weaponStrength)){
            delete player_array[i];
            removed= true;
        }
    }
    if(removed){
        return removed;
    }
    return removed;
}


