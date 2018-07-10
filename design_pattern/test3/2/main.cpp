#include <iostream>
#include <algorithm>

#include "role.h"
#include "memento.h"

using namespace std;

int main (int argc, char ** argv) {
    
    std::cout << "=== Game begin ===" << std::endl;
    
    Role role_one;
    role_one.show();
    Memento memento_one(role_one.vitality);
    memento_one = role_one.saveState();
    
    role_one.fight();
    
    std::cout << " Recover begin..." << std::endl;
    role_one.recoverState(memento_one);
    role_one.show();
    
    std::cout << "=== Game end ===" << std::endl;
    
    return 0;
}


