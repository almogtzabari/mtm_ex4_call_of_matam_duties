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

GameStatus Game::fight(const char *playerName1, const char *playerName2) {
    int player1_index=0, player2_index=0;
    bool found1=false, found2= false;
    for (int i=0;i<max_players;i++) {
        if(player_array[i]->isPlayer(playerName1)){
            player1_index=i;
            found1=true;
        }
        if(player_array[i]->isPlayer(playerName2)){
            player2_index=i;
            found2=true;
        }
    }
    if(!found1 || !found2){
        return NAME_DOES_NOT_EXIST;
    }
    if(!player_array[player1_index]->fight(*player_array[player2_index])){
        return FIGHT_FAILED;
    }
    if(!player_array[player1_index]->isAlive()){
        delete player_array[player1_index];
    }
    if(!player_array[player2_index]->isAlive()){
        delete player_array[player2_index];
    }
    return SUCCESS;
}

static void sortPlayerNames(char** players_names){
    
}

ostream& Game::operator<<(ostream & os,const Game &game){
    char** names = new char* [max_players];
    for(int i=0;i<max_players;i++){
        names[i] = player_array[i]->getName();
    }



}
