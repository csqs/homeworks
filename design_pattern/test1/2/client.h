#ifndef CLIENT_H
#define CLIENT_H

class Client{
    public:
        Client(int size_temp, int decr_temp, int style_temp);
        ~Client();

        int getPrice();
        
        int size;
        int decr;
        int style;

};


#endif
