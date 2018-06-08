//
// Created by Almog on 07/06/2018.
//

#include "Weapon.h"

/**
 * Constructor
 * @param name - Weapon name.
 * @param target - Enum which represents the target of the weapon.
 * @param hitStrength - Strength of the weapon.
 */
Weapon::Weapon(const char* name, Target target, int hitStrength) :
        name(nullptr),target(target),hitStrength(hitStrength){
    this->name=new char [strlen(name)+1];
    strcpy(this->name,name);
}
/**
 * Default constructor
 */
Weapon::Weapon() : name(nullptr){
}

/**
 * Operator=
 * @param weapon - A weapon to assign.
 *
 * @return
 * A reference to new assigned weapon.
 */
Weapon& Weapon::operator=(const Weapon& weapon) {
    if (this==&weapon){
        return *this;
    }
    delete [] name;
    name=new char [strlen(weapon.name)+1];
    strcpy(name,weapon.name);
    target=weapon.target;
    hitStrength=weapon.hitStrength;
    return *this;
}
/**
 * Destructor
 */
Weapon::~Weapon() {
    delete[] name;
}

/**
 * getTarget
 * @return
 * The target of the weapon.
 */
Target Weapon::getTarget() const {
    return target;
}
/**
 * getHitStrength
 * @return
 * Hit strength of the weapon.
 */
int Weapon::getHitStrength() const {
    return hitStrength;
}

/**
 * getValue
 * @return
 * Gets the value of the weapon.
 */
int Weapon::getValue() const {
    if(target==LEVEL){
        return 1*hitStrength;
    }
    if(target==STRENGTH){
        return 2*hitStrength;
    }
    return 3*hitStrength;
}

/**
 * Operator==
 * @param weapon - A weapon to compare.
 * @return
 * True if both weapons has the same value, else false.
 */
bool Weapon::operator==(const Weapon& weapon) const {
    return this->getValue()==weapon.getValue();
}

/**
 * Operator!=
 * @param weapon - A weapon to compare.
 * @return
 * True if the weapons has different values, else false.
 */
bool Weapon::operator!=(const Weapon& weapon) const{
    return this->getValue()!=weapon.getValue();
}

/**
 * Operator>
 * @param weapon - A weapon to compare.
 * @return
 * True if the given weapon has smaller value than the
 */
bool Weapon::operator>(const Weapon& weapon) const {
    return this->getValue()>weapon.getValue();
}

bool Weapon::operator<(const Weapon& weapon) const {
    return this->getValue()<weapon.getValue();
}

ostream& operator<<(ostream& os, const Weapon& weapon){
    return os<<"{weapon name: "<<weapon.name<< ","<<" weapon value:"<<
             weapon.getValue()<<"}";
}

Weapon::Weapon(const Weapon& weapon) :
        name(new char[(strlen(weapon.name)+1)]),target(weapon.target),
        hitStrength(weapon.hitStrength){
    strcpy(name,weapon.name);
}