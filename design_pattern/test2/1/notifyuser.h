#ifndef NOTIFYUSER_H
#define NOTIFYUSER_H


class NotifyUser{
    public:
        NotifyUser(int input_client, int input_class);
        ~NotifyUser();

        void notify();
    
        int class_number;
        int client_id;
};


#endif
