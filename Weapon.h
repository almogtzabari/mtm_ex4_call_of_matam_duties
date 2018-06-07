//
// Created by Almog on 07/06/2018.
//

#ifndef MTM_EX4_CALL_OF_MATAM_DUTIES_WEAPON_H
#define MTM_EX4_CALL_OF_MATAM_DUTIES_WEAPON_H

#include <iostream>
#include <cstring>

enum Target
{
LEVEL,
STRENGTH,
LIFE
};


class Weapon {
char* name;
Target target;
int hitStrength;
public:
    Weapon(const char* name,Target target,int hitStrength);
    ~Weapon();
    Target getTarget() const;
    int getHitStrength() const;
    int getValue() const;
};


#endif //MTM_EX4_CALL_OF_MATAM_DUTIES_WEAPON_H
