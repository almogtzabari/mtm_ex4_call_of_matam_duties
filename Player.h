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
    Player();
    Player(const Player& player);
    Player(const char* name, const Weapon& weapon);
    ~Player();
    Player& operator=(const Player& player);
    void nextLevel();
    bool isPlayer(const char* playerName)const;
    void makeStep();
    void addLife();
    void addStrength(int strengthToAdd);
    bool isAlive()const;
    bool weaponIsWeak(int weaponMinStrength)const;
    bool fight(Player& player);
    friend ostream& operator<<(ostream& os, const Player& player);
    friend bool operator<(const Player& player1,const Player& player2);
    friend bool operator>(const Player& player1,const Player& player2);

};


#endif //MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H
