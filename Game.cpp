
#include "Game.h"
using std::ostream;

/**
 * Constructor
 *
 * @param maxPlayer - Max player of the game.
 */
Game::Game(int maxPlayer) : max_players(maxPlayer), number_of_players(0),
                            player_array( new Player* [maxPlayer]){
    for(int i=0;i<max_players;i++){
        player_array[i] = new Player();
    }
}

/**
 * Destructor
 */
Game::~Game() {
    for (int i=0;i<max_players;i++) {
        delete player_array[i];
    }
    delete[] player_array;
}

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
GameStatus Game::nextLevel(const char *playerName) {
    int player_index = getPlayerIndexByName(playerName);
    if(player_index!=-1){
        player_array[player_index]->nextLevel();
        return SUCCESS;
    }
    return NAME_DOES_NOT_EXIST;
}

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
GameStatus Game::makeStep(const char *playerName) {
    int player_index = getPlayerIndexByName(playerName);
    if(player_index!=-1){
        player_array[player_index]->makeStep();
        return SUCCESS;
    }
    return NAME_DOES_NOT_EXIST;
}

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
GameStatus Game::addLife(const char *playerName) {
    int player_index = getPlayerIndexByName(playerName);
    if(player_index!=-1){
        player_array[player_index]->addLife();
        return SUCCESS;
    }
    return NAME_DOES_NOT_EXIST;
}

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
GameStatus Game::addStrength(const char *playerName, int strengthToAdd) {
    if(strengthToAdd<0){
        return INVALID_PARAM;
    }
    int player_index = getPlayerIndexByName(playerName);
    if(player_index!=-1){
        player_array[player_index]->addStrength(strengthToAdd);
        return SUCCESS;
    }
    return NAME_DOES_NOT_EXIST;
}

bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength) {
    int count=0;
    for (int i=0;i<number_of_players;i++) {
        if (player_array[i]->weaponIsWeak(weaponStrength)) {
            removePlayer(*player_array[i--]);
            count++;
        }
    }
    return count>0;
}

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
 *
 *
 */
GameStatus Game::fight(const char *playerName1, const char *playerName2) {

    int player1_index = getPlayerIndexByName(playerName1);
    int player2_index = getPlayerIndexByName(playerName2);
    if(player1_index==-1 || player2_index==-1){
        return NAME_DOES_NOT_EXIST;
    }
    if(!player_array[player1_index]->fight(*player_array[player2_index])){
        return FIGHT_FAILED;
    }
    if(!player_array[player1_index]->isAlive()){
        /* Player1 died. */
        removePlayer(*player_array[player1_index]);
                return SUCCESS;
    }
    if(!player_array[player2_index]->isAlive()){
        /* Player2 died. */
        removePlayer(*player_array[player2_index]);
                return SUCCESS;
    }
    /* No one died. */
    return SUCCESS;
}


/**
 * operator<<
 *
 * @param os - Stream to concatenate to.
 * @param game - Game to print its details.
 *
 * @return
 * Stream of game details.
 */
ostream& operator<<(ostream& os,Game& game){
    /* Sorting (bubble) number_of_players: */
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
        os << "player "<<i<<": "<< *game.player_array[i]<<","<< std::endl;
    }
    return os;
}

/**
 * isFull
 *
 * @return
 * True - Game is full.
 * False - Game is not full.
 */
bool Game::isFull() const {
    return number_of_players == max_players;
}

/**
 * playerExist
 *
 * @param player_name - Name of the player to check if exists.
 *
 * @return
 * True - Player with given name exists.
 * False - Player with given name does not exists.
 */
bool Game::playerExist(const char *player_name) const {
    for(int i=0; i<number_of_players;i++){
        if(player_array[i]->isPlayer(player_name)){
            return true;
        }
    }
    return false;
}

/**
 * removePlayer
 *
 * Removing player from the game.
 *
 * @param player -  Player to remove.
 */
void Game::removePlayer(const Player& player){
    for (int i=0;i<number_of_players;i++) {
        if(player == *player_array[i]){
            *player_array[i] = *player_array[--number_of_players];
            break;
        }
    }
}

/**
 * getPlayerIndexByName
 *
 * @param playerName - Name of the player to get its index.
 *
 * @return
 * Index of the player with the given name.
 * If not found returns -1.
 */
int Game::getPlayerIndexByName(const char *playerName) const {
    for(int i=0;i<number_of_players;i++){
        if(player_array[i]->isPlayer(playerName)){
            return i;
        }
    }
    return -1;
}