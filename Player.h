//
// Created by Almog on 07/06/2018.
//

#ifndef MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H
#define MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H

#include "Weapon.h"
#include <iostream>
#include <cstring>


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
    friend ostream& operator<<(ostream& os, const Complex& c);
};


#endif //MTM_EX4_CALL_OF_MATAM_DUTIES_PLAYER_H
