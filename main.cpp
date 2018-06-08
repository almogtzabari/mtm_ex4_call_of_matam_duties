#include <iostream>
#include "Weapon.h"

using std::cout;


int main() {
    std::cout << "Hello, World!" << std::endl;
    Weapon temp = {"avi", STRENGTH, 3};
    cout<<temp;
    return 0;
}