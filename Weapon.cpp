
#include "Weapon.h"

/**
 * Constructor
 *
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
 * Copy constructor
 *
 * @param weapon - Weapon to copy.
 */
Weapon::Weapon(const Weapon& weapon) :
        name(new char[(strlen(weapon.name)+1)]),target(weapon.target),
        hitStrength(weapon.hitStrength){
    strcpy(name,weapon.name);
}

/**
 * Destructor
 */
Weapon::~Weapon() {
    delete[] name;
}

/**
 * Operator=
 * @param weapon - Weapon to assign.
 *
 * @return
 * Reference to new assigned weapon.
 */
Weapon& Weapon::operator=(const Weapon& weapon) {
    if (this==&weapon){
        return *this;
    }
    delete [] name;
    name = new char [strlen(weapon.name)+1];
    strcpy(name,weapon.name);
    target = weapon.target;
    hitStrength = weapon.hitStrength;
    return *this;
}

/**
 * getTarget
 *
 * @return
 * Target of the weapon.
 */
Target Weapon::getTarget() const {
    return target;
}

/**
 * getHitStrength
 *
 * @return
 * Hit strength of the weapon.
 */
int Weapon::getHitStrength() const {
    return hitStrength;
}

/**
 * getValue
 *
 * @return
 * Value of the weapon.
 */
int Weapon::getValue() const {
    switch (target){
        case LEVEL: return 1*hitStrength;
        case STRENGTH: return 2*hitStrength;
        case LIFE: return 3*hitStrength;
    }
    /* Shouldn't get here. */
    return 0;
}

/**
 * Operator==
 *
 * @param weapon - A weapon to compare.
 *
 * @return
 * True - Both weapons has the same value.
 * False - Otherwise.
 */
bool Weapon::operator==(const Weapon& weapon) const {
    return this->getValue()==weapon.getValue();
}

/**
 * Operator!=
 *
 * @param weapon - Weapon to compare.
 *
 * @return
 * True - Weapons has different values.
 * False - Otherwise.
 */
bool Weapon::operator!=(const Weapon& weapon) const{
    return this->getValue()!=weapon.getValue();
}

/**
 * Operator>
 *
 * @param weapon - Weapon to compare.
 *
 * @return
 * True - Given weapon has smaller value than *this.
 * False - Otherwise.
 */
bool Weapon::operator>(const Weapon& weapon) const {
    return this->getValue()>weapon.getValue();
}

/**
 * operator<
 *
 * @param weapon - Weapon to compare.
 *
 * @return
 * True - Given weapon has bigger value than *this.
 * False - Otherwise.
 */
bool Weapon::operator<(const Weapon& weapon) const {
    return this->getValue()<weapon.getValue();
}

/**
 * operator<<
 *
 * @param os - Stream to concatenate to.
 * @param player - Weapon we want to print.
 *
 * @return
 * Stream of weapon details.
 */
ostream& operator<<(ostream& os, const Weapon& weapon){
    return os<<"{weapon name: "<<weapon.name<< ","<<" weapon value:"<<
             weapon.getValue()<<"}";
}