#include <stdlib.h>
//#include <algorithm>
#include <vector>
#include <iostream>

#include "subscribe.h"
#include "client.h"


Subscribe::Subscribe(){
}

Subscribe::~Subscribe(){
}

void Subscribe::attach(Client client_one){
    int find = 0;
    for(int i = 0; i < client_list.size(); i++){
        if(client_list[i].client_id == client_one.client_id){
            find = 1;
            break;
        }
    }
    if(find == 0)
        client_list.push_back(client_one);
    
}

void Subscribe::detach(Client client_one){
//    client_one.client_state = 1;
//    std::vector<Client>::iterator iter = find(client_list.begin(), client_list.end(), client_one);
//    if((*iter).client_id == client_one.client_id){
//        //std::vector<Client>::iterator iter_temp = iter;
//        iter = client_list.erase(iter);
//    }

    for(int i = 0; i < client_list.size(); i++){
        if(client_list[i].client_id == client_one.client_id){
            client_list.erase(client_list.begin() + i);
            break;
        }
    }
}

void Subscribe::getState(){
    std::vector<Client> client_list;
    
    std::cout << "=== client update stage === " << std::endl;
    char new_client = '0';
    
    std::cout << "-- new client enter  --- " << std::endl;
    
    std::cout << "Do we have a new client? Yes --- 1, No --- 0." << std::endl;
    std::cin >> new_client;
    while(new_client == '1'){
        char new_client_id;
        
        std::cout << "Please enter the client id:" << std::endl;
        std::cin >> new_client_id;
        
        int new_client_id_temp = new_client_id - '0';
        //std::cout << new_client_id_temp << std::endl;
        Client client_one(new_client_id_temp);
        attach(client_one);
        
        std::cout << "Do we have a new client? Yes --- 1, No --- 0." << std::endl;
        std::cin >> new_client;
    }
    std::cout << "-- new client enter end --- " << std::endl;
    
//    std::cout << "=== update client's decision  === " << std::endl;
//    
//    std::cout << client_list.size() << std::endl;
//    for(int i = 0; i < client_list.size(); i++){
//        client_list[i].updateState();
//        if(client_list[i].client_state == 0)
//            detach(client_list[i]);
//    }
//    std::cout << "=== update end  === " << std::endl;
    
}

void Subscribe::notify(){
    char pre_function = '0';
    char stop = '0';
    
    while(stop != '1'){
        std::cout << "Get client state before notifying, Yes --- 1, No ---- 0" << std::endl;
        std::cin >> pre_function;
        if(pre_function == '1'){
            getState();
            
            std::cout << "=== update client's decision  === " << std::endl;
            std::cout << client_list.size() << std::endl;
            for(int i = 0; i < client_list.size(); i++){
                client_list[i].updateState();
                if(client_list[i].client_state == 0){
                    detach(client_list[i]);
                    i--;
                }
            }
            std::cout << "=== update end  === " << std::endl;
        }
        
        this->subscribe_state = rand() % 3;
        for(int i = 0; i < client_list.size(); i++){
            std::cout << "Hello, client :"<< client_list[i].client_id << std::endl;
            if(this->subscribe_state == 0){
                std::cout << "Subscribed message: Bread 50% discount today"<< std::endl;
            }
            else if(this->subscribe_state == 1){
                std::cout << "Subscribed message: Milk 50% discount today"<< std::endl;
            }
            else if(this->subscribe_state == 2){
                std::cout << "Subscribed message: Fruit 50% discount today"<< std::endl;
            }
        }
        
        std::cout << "Quit the system, Yes --- 1, No ---- 0" << std::endl;
        std::cin >> stop;
    }
}
















