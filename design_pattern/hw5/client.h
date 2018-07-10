#ifndef CLIENT_H
#define CLIENT_H

class Client{
    public:
        Client(int client_id_input);
        ~Client();

        void updateState();
        int client_state;
        int client_id;
};


#endif
