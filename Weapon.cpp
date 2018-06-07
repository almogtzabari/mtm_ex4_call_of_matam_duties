//
// Created by Almog on 07/06/2018.
//

#include "Weapon.h"

Weapon::Weapon(const char* name, Target target, int hitStrength) :
        name(nullptr),target(target),hitStrength(hitStrength){
    this->name=new char [strlen(name)+1];
    strcpy(this->name,name);
}

Weapon::Weapon(){
    this->name=new char [strlen(name)+1];
};


Weapon::~Weapon() {
    delete[] name;
}

Target Weapon::getTarget() const {
    return target;
}

int Weapon::getHitStrength() const {
    return hitStrength;
}

int Weapon::getValue() const {
    if(target==LEVEL){
        return 1*hitStrength;
    }
    if(target==STRENGTH){
        return 2*hitStrength;
    }
    return 3*hitStrength;
}

bool operator==(const Weapon& weapon1,const Weapon& weapon2) {
    return weapon1.getValue()==weapon2.getValue();
}

bool operator!=(const Weapon& weapon1,const Weapon& weapon2){
    return weapon1.getValue()!=weapon2.getValue();
}

bool operator>(const Weapon& weapon1,const Weapon& weapon2) {
    return weapon1.getValue()>weapon2.getValue();
}

bool operator<(const Weapon& weapon1,const Weapon& weapon2) {
    return weapon1.getValue()<weapon2.getValue();
}

ostream& operator<<(ostream& os, const Weapon& weapon){
    return os<<"weapon name: "<<weapon.name<<" weapon value: "<<
             weapon.getValue();
}

