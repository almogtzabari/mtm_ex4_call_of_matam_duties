//
// Created by Almog on 07/06/2018.
//

#include "Player.h"


/**
 ***** Constructor *****
 */
Player::Player(const char* name, const Weapon& weapon): name(nullptr),
weapon(weapon),life(1),strength(1),level(1),position(0){
    char* temp_name = new char [strlen(name)+1];
    strcpy(temp_name,name);
    this->name = temp_name;
}

/**
 ***** Destructor *****
 */
Player::~Player() {
    delete[] name;
}


ostream& operator<<(ostream& os, const Player& player){
    return os << "Player name:" << player.name << "weapon:" <<
              player.weapon;
}

void Player::nextLevel() {
    level++;
}

bool Player::isPlayer(const char *playerName) const {
    return (strcmp(playerName,name)==0);
}

void Player::makeStep() {
    position++;
}

void Player::addLife() {
    life++;
}

void Player::addStrength(int strengthToAdd) {
    strength+=strengthToAdd;
}

bool Player::isAlive() const {
    if(strength<1 || life<1 || level<1){
        return false;
    }
    return true;
}

bool Player::weaponIsWeak(int weaponMinStrength)const {
    return (weapon.getValue()<weaponMinStrength);
}

bool operator<(const Player& player1,const Player& player2) {
    return (strcmp(player1.name,player2.name)<0);
}

bool operator>(const Player& player1,const Player& player2){
    return (strcmp(player1.name,player2.name)>0);
}

bool Player::fight(Player &player) {
    if(position!=player.position ||
       weapon.getValue() == player.weapon.getValue()){
        return false;
    }

    return true;
}