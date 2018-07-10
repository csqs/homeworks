#include <iostream>
#include <algorithm>
#include <time.h>

#include "client.h"

using namespace std;

int main (int argc, char ** argv) {
    
    std::cout << "Welcome to KFC. " << endl;
    
    Client client_in;
    client_in.order();
    
    std::cout << "System ends." << endl;
    
    return 0;
}


