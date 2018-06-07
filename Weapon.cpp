//
// Created by Almog on 07/06/2018.
//

#include "Weapon.h"

Weapon::Weapon(const char* name) :
        name(nullptr),target(target),hitStrength(hitStrength){
    this->name=new char [strlen(name)+1];
    strcpy(this->name,name);
}