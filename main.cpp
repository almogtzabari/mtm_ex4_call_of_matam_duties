#include <iostream>
#include "Weapon.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Weapon temp = {"avi", STRENGTH, 3};
    std::cout<<temp;
    return 0;
}