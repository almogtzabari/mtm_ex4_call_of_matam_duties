
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
    if(player_index==-1){
        return NAME_DOES_NOT_EXIST;
    }
    player_array[player_index]->nextLevel();
    return SUCCESS;
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
    if(player_index==-1){
        return NAME_DOES_NOT_EXIST;
    }
    player_array[player_index]->makeStep();
    return SUCCESS;
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
    if(player_index==-1){
        return NAME_DOES_NOT_EXIST;
    }
    player_array[player_index]->addLife();
    return SUCCESS;
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
    if(player_index==-1){
        return NAME_DOES_NOT_EXIST;
    }
    player_array[player_index]->addStrength(strengthToAdd);
    return SUCCESS;

}

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
bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength) {
    int count=0;
    for (int i=0;i<number_of_players;i++) {
        if (player_array[i]->weaponIsWeak(weaponStrength)) {
            removePlayer(*player_array[i--]);
            /* Notice: removePlayer puts the last valid player in the array
             * in the position of the removed player. Therefore, after
             * remove there will be a new player at index i so we need to
             * check that index again (i--). */
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
    /* Sorting players' array before printing. */
    game.sortPlayers();
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

/**
 * swap
 *
 * Swaping to players.
 *
 * @param player1_ptr - Pointer of first player.
 * @param player2_ptr - Pointer of second player.
 */
void Game::swap(Player* player1_ptr, Player* player2_ptr) {
    Player temp = *player1_ptr;
    *player1_ptr = *player2_ptr;
    *player2_ptr = temp;
}

/**
 * sortPlayers
 *
 * Sorting (bubble sort) players array (only the real players) by name.
 */
void Game::sortPlayers() {
    for (int i = 0; i < number_of_players; i++) {
        for (int j = 0; j < number_of_players - i - 1; j++) {
            if(*player_array[j]>*player_array[j+1]){
                swap(player_array[j],player_array[j+1]);
            }
        }
    }
}