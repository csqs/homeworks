#ifndef REGISTRATIONFACADE_H
#define REGISTRATIONFACADE_H


class RegistrationFacade{
    public:
        RegistrationFacade(int client);
        ~RegistrationFacade();

        void interface();
    
        int client_id;
};


#endif
