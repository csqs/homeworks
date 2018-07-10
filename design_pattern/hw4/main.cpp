#include <iostream>
#include <algorithm>
#include <time.h>

#include "client.h"

using namespace std;

int main (int argc, char ** argv) {
    
    Client client_one;
    client_one.begin();
    
    std::cout << "System ends." << endl;
    
    return 0;
}


