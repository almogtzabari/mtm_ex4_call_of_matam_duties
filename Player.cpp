
#include "Player.h"

/**
 * Default constructor
 */
Player::Player(): name(nullptr),level(1),life(1),
                  strength(1),weapon(),position(0) {
}

/**
 * Copy constructor
 *
 * @param player - Player we want to copy.
 */
Player::Player(const Player& player):
        name(new char[strlen(player.name)+1]),level(player.level),
        life(player.life),strength(player.strength),weapon(player.weapon),
        position(player.position){
    strcpy(name,player.name);
}

/**
 * Constructor
 *
 * @param name - Name of the player.
 * @param weapon - Weapon of the player.
 */
Player::Player(const char* name, const Weapon& weapon): name(nullptr),
level(1),life(1),strength(1),weapon(weapon),position(0){
    char* temp_name = new char [strlen(name)+1];
    strcpy(temp_name,name);
    this->name = temp_name;
}

/**
 * Destructor
 *
 * Free all resources of given player.
 */
Player::~Player() {
    delete[] name;
}

/**
 * Operator=
 *
 * Assign the given player.
 *
 * @param player - Player we want to assign.
 *
 * @return
 * Player after assignment.
 */
Player& Player::operator=(const Player &player) {
    if(this==&player){
        return *this;
    }
    delete[] name;
    name = new char[strlen(player.name)+1];
    strcpy(name,player.name);
    life = player.life;
    strength = player.strength;
    level = player.level;
    position = player.position;
    weapon = player.weapon;
    return *this;
}

/**
 * operator<<
 *
 * Prints the given player.
 *
 * @param os - Will be used to concatenate.
 * @param player - Player we want to print.
 *
 * @return
 * Stream of Player details.
 */
ostream& operator<<(ostream& os, const Player& player){
    return os << "{Player name: " << player.name << "," <<" weapon: " <<
              player.weapon << "}";
}

/**
 * nextLevel
 *
 * Increasing level of given player by 1.
 *
 */
void Player::nextLevel() {
    level++;
}

/**
 * isPlayer
 *
 * Gets a name and check if the given name is the player.
 *
 * @param playerName - Name of the player.
 *
 * @return
 * True - Player's name is the given name.
 * False - Otherwise.
 */
bool Player::isPlayer(const char *playerName) const {
    return (strcmp(playerName,name)==0);
}

/**
 * makeStep
 *
 * Increasing player's position by 1.
 */
void Player::makeStep() {
    position++;
}

/**
 * addLife
 *
 * Increasing player's life by 1.
 */
void Player::addLife() {
    life++;
}

/**
 * addStrength
 *
 * Increasing player's strength by given amount.
 *
 * @param strengthToAdd - Amount to add to player's strength.
 */
void Player::addStrength(int strengthToAdd) {
    strength+=strengthToAdd;
}

/**
 * isAlive
 *
 * Checks if the player is alive.
 *
 * @return
 * True - Player is alive.
 * False - Player is dead.
 */
bool Player::isAlive() const {
    if(strength<1||life<1||level<1){
        return false;
    }
    return true;
}

/**
 * weaponIsWeak
 *
 * Checks if player's weapon is weaker than given
 *
 * @param weaponMinStrength
 * @return
 */
bool Player::weaponIsWeak(int weaponMinStrength)const {
    return (weapon.getValue()<weaponMinStrength);
}

/**
 * operator<
 *
 * @param player1 - First player.
 * @param player2 - Second player.
 *
 * @return
 * True - player1<player2
 * False - Otherwise.
 */
bool operator<(const Player& player1,const Player& player2) {
    return (strcmp(player1.name,player2.name)<0);
}

/**
 * operator>
 *
 * @param player1 - First player.
 * @param player2 - Second player.
 *
 * @return
 * True - player1>player2
 * False - Otherwise.
 */
bool operator>(const Player& player1,const Player& player2){
    return (strcmp(player1.name,player2.name)>0);
}

/**
 * fight
 *
 * @param player - Player to fight against.
 *
 * @return
 * True - Fight succeeded.
 * False - Fight failed.
 */
bool Player::fight(Player &player) {
    if(position!=player.position || weapon == player.weapon){
        /* Not in the same position or has same weapon value, therefore
         * shouldn't fight .*/
        return false;
    }
    if(weapon>player.weapon){
        (*this).attack(player);
    }
    else {
        player.attack(*this);
    }
    return true;
}

void Player::attack(Player &defender) const {
    switch(weapon.getTarget()) {
        case LEVEL :
            defender.level -= this->weapon.getHitStrength();
            if (defender.level < 0) {
                defender.level = 0;
            }
            return;
        case LIFE :
            defender.life -= this->weapon.getHitStrength();
            if (defender.life < 0) {
                defender.life = 0;
            }
            return;
        case STRENGTH :
            defender.strength -= this->weapon.getHitStrength();
            if (defender.strength < 0) {
                defender.strength = 0;
            }
            return;
    }
}