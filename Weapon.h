
#ifndef MTM_EX4_CALL_OF_MATAM_DUTIES_WEAPON_H
#define MTM_EX4_CALL_OF_MATAM_DUTIES_WEAPON_H

#include <iostream>
#include <cstring>
using namespace std;

enum Target
{
    LEVEL,
    STRENGTH,
    LIFE
};

//-----------------------------------------------------------------------//
//                          CLASS WEAPON:                                //
//-----------------------------------------------------------------------//

class Weapon {
    char* name;
    Target target;
    int hitStrength;

//-----------------------------------------------------------------------//
//                         PUBLIC METHODS:                               //
//-----------------------------------------------------------------------//

public:

/**
 * Constructor
 *
 * @param name - Weapon name.
 * @param target - Enum which represents the target of the weapon.
 * @param hitStrength - Strength of the weapon.
 */
Weapon(const char* name,Target target,int hitStrength);

/**
 * Default constructor
 */
Weapon();

/**
 * Destructor
 */
~Weapon();

/**
 * Copy constructor
 *
 * @param weapon - Weapon to copy.
 */
Weapon(const Weapon& weapon);

/**
 * getTarget
 *
 * @return
 * Target of the weapon.
 */
Target getTarget() const;

/**
 * getHitStrength
 *
 * @return
 * Hit strength of the weapon.
 */
int getHitStrength() const;

/**
 * getValue
 *
 * @return
 * Value of the weapon.
 */
int getValue() const;

/**
 * Operator==
 *
 * @param weapon - A weapon to compare.
 *
 * @return
 * True - Both weapons has the same value.
 * False - Otherwise.
 */
bool operator==(const Weapon& weapon) const;

/**
 * Operator!=
 *
 * @param weapon - Weapon to compare.
 *
 * @return
 * True - Weapons has different values.
 * False - Otherwise.
 */
bool operator!=(const Weapon& weapon) const;

/**
 * operator<
 *
 * @param weapon - Weapon to compare.
 *
 * @return
 * True - Given weapon has bigger value than *this.
 * False - Otherwise.
 */
bool operator<(const Weapon& weapon) const;

/**
 * Operator>
 *
 * @param weapon - Weapon to compare.
 *
 * @return
 * True - Given weapon has smaller value than *this.
 * False - Otherwise.
 */
bool operator>(const Weapon& weapon) const;

/**
 * Operator=
 * @param weapon - Weapon to assign.
 *
 * @return
 * Reference to new assigned weapon.
 */
Weapon& operator=(const Weapon& weapon);

/**
 * operator<<
 *
 * @param os - Stream to concatenate to.
 * @param player - Weapon we want to print.
 *
 * @return
 * Stream of weapon details.
 */
friend ostream& operator<<(ostream& os, const Weapon& weapon);
};

#endif //MTM_EX4_CALL_OF_MATAM_DUTIES_WEAPON_H
