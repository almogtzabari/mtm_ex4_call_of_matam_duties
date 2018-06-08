#include <iostream>
#include "Weapon.h"
using std::ostream


int main() {
    std::cout << "Hello, World!" << std::endl;
    Weapon temp = {"avi", STRENGTH, 3};
    cout<<temp;
    return 0;
}