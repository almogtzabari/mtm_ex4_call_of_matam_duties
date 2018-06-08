//
// Created by Almog on 07/06/2018.
//

#include "Game.h"
#include "Player.h"
using std::ostream;

Game::Game(int maxPlayer) : max_players(maxPlayer), number_of_players(0),
                            player_array( new Player* [maxPlayer]){
    for(int i=0;i<max_players;i++){
        player_array[i] = new Player();
    }
}

Game::~Game() {
    for (int i=0;i<max_players;i++) {
        delete player_array[i];
    }
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
    return NAME_DOES_NOT_EXIST;
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

    int player1_index = getIndexOfPlayerByName(playerName1);
    int player2_index = getIndexOfPlayerByName(playerName2);
    if(player1_index==-1 || player2_index==-1){
        return NAME_DOES_NOT_EXIST;
    }
    if(!player_array[player1_index]->fight(*player_array[player2_index])){
        return FIGHT_FAILED;
    }
    if(!player_array[player1_index]->isAlive()){
        removePlayer(*player_array[player1_index]);
                return SUCCESS;
    }
    if(!player_array[player2_index]->isAlive()){
        removePlayer(*player_array[player2_index]);
                return SUCCESS;
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
        if(player == *player_array[i]){
            *player_array[i] = *player_array[--number_of_players];
            break;
        }
    }
}

int Game::getIndexOfPlayerByName(const char* playerName) const {
    for(int i=0;i<number_of_players;i++){
        if(player_array[i]->isPlayer(playerName)){
            return i;
        }
    }
    return -1;
}