//
// Created by Almog on 07/06/2018.
//

#include "Game.h"
#include "Player.h"
using std::ostream;

Game::Game(int maxPlayer) : max_players(maxPlayer), number_of_players(0),
                            player_array( new Player* [maxPlayer]){
}

Game::~Game() {
    delete[] player_array;
}

GameStatus Game::addPlayer(const char *playerName, const char *weaponName,
                           Target target, int hit_strength) {
    if(isFull()){
        return GAME_FULL;
    }
    if(playerExist(playerName)){
        return NAME_ALREADY_EXISTS;
    }
    Weapon weapon = Weapon(weaponName,target,hit_strength);
    *player_array[number_of_players++] = Player(playerName,weapon);
    return SUCCESS;
}

GameStatus Game::nextLevel(const char *playerName) {
    for (int i=0;i<number_of_players;i++) {
        if(player_array[i]->isPlayer(playerName)){
            player_array[i]->nextLevel();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

GameStatus Game::makeStep(const char *playerName) {
    for (int i=0;i<number_of_players;i++) {
        if(player_array[i]->isPlayer(playerName)) {
            player_array[i]->makeStep();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

GameStatus Game::addLife(const char *playerName) {
    for (int i=0;i<number_of_players;i++) {
        if (player_array[i]->isPlayer(playerName)) {
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
    if(!playerExist(playerName)){
        return NAME_DOES_NOT_EXIST;
    }
    for(int i=0;i<number_of_players;i++) {
        if(player_array[i]->isPlayer(playerName)) {
            player_array[i]->addStrength(strengthToAdd);
            return SUCCESS;
        }
    }
}

bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength) {
    int count=0;
    for (int i=0;i<number_of_players;i++) {
        if (player_array[i]->weaponIsWeak(weaponStrength)) {
            removePlayer(*player_array[i]);
            count++;
        }
    }
    return count>0;
}

GameStatus Game::fight(const char *playerName1, const char *playerName2) {
    int player1_index=0, player2_index=0;
    bool found1=false, found2= false;
    for (int i=0;i<max_players;i++) {
        if(player_array[i]){
            /*  Player is not nullptr. */
            if(player_array[i]->isPlayer(playerName1)){
                player1_index=i;
                found1=true;
            }
            if(player_array[i]->isPlayer(playerName2)){
                player2_index=i;
                found2=true;
            }
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
        for (int i=max_players-1;i>=0 ;i--) {
            if(player_array[i]){
                player_array[player1_index]=player_array[i];
                player_array[i]= nullptr;
                return SUCCESS;
            }
        }
    }
    if(!player_array[player2_index]->isAlive()){
        delete player_array[player2_index];
        for (int i=max_players-1;i>=0 ;i--) {
            if(player_array[i]){
                player_array[player2_index]=player_array[i];
                player_array[i]= nullptr;
                return SUCCESS;
            }
        }
    }
    return SUCCESS;
}


ostream& operator<<(ostream& os,Game& game){
    /* Sorting number_of_players: */
    Player* temp;
    for (int i = 0; i < game.number_of_players; i++) {
        for (int j = 0; j < game.number_of_players - i - 1; j++) {
            if(*game.player_array[j]>*game.player_array[j+1]){
                temp = game.player_array[j];
                game.player_array[j] = game.player_array[j+1];
                game.player_array[j+1] = temp;
            }
        }
    }
    for(int i=0;i<game.number_of_players;i++){
        os << "Player "<<i<<": "<< *game.player_array[i]<<","<< std::endl;
    }
    return os;
}

bool Game::isFull() const {
    return number_of_players == max_players;
}

bool Game::playerExist(const char *player_name) const {
    for(int i=0; i<number_of_players;i++){
        if(player_array[i]->isPlayer(player_name)){
            return true;
        }
    }
    return false;
}

void Game::removePlayer(const Player& player){
    for (int i=0;i<number_of_players;i++) {
        if(player==*player_array[i]){
            *player_array[number_of_players--]=player;
            *player_array[i]=*player_array[number_of_players];
        }
    }
}