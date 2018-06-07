//
// Created by Almog on 07/06/2018.
//

#ifndef MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H
#define MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H

#include "Weapon.h"
#include <iostream>
#include <cstring>
using namespace std;


class Player {
    char* name;
    int level;
    int life;
    int strength;
    Weapon weapon;
    int position;

public:
    Player(const char* name, const Weapon& weapon);
    ~Player();
    void nextLevel();
    bool isPlayer(const char* playerName)const;
    void makeStep();
    void addLife();
    void addStrength(int strengthToAdd);
    bool isAlive()const;
    bool weaponIsWeak(int weaponMinStrength)const;
    friend ostream& operator<<(ostream& os, const Player& player);
    friend bool operator<(const Player &player)const;
    friend bool operator>(const Player &player)const;
};


#endif //MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H
