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
            Weapon* weapon = new Weapon(weaponName,target,hit_strenth);
            Player* player = new Player(playerName,*weapon);
            player_array[i] = player;
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

int Game::playersInGame() const {
    int count=0;
    for(int i=0;i<max_players;i++){
        if(player_array[i]){
            count++;
        }
    }
    return count;
}

void Game::sortPlayers(Game& game) {
    int players_in_game = game.playersInGame();
    Player* temp;
    for (int i = 0; i < players_in_game-1; i++) {
        for (int j = 0; j < players_in_game - i - 1; j++) {
            if(*player_array[j]>*player_array[j+1]){
                temp = player_array[j];
                player_array[j+1] = player_array[j];
                player_array[j] = temp;
            }
        }
    }
}

ostream& Game::operator<<(ostream& os,const Game &game){
    sortPlayers(game);
    for(int i=0;i<game.playersInGame();i++){
        os << *player_array[i];
    }
    return os;

}
