#include <iostream>
#include <algorithm>
#include <time.h>

#include "subscribe.h"

using namespace std;

int main (int argc, char ** argv) {
    
    Subscribe subscribe_one;
    subscribe_one.notify();
    
    std::cout << "System ends." << endl;
    
    return 0;
}


