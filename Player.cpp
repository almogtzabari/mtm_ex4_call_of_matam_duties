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
    
}