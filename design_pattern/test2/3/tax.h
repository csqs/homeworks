#ifndef TAX_H
#define TAX_H


class Tax{
    public:
        Tax(char input_type, int input_price);
        ~Tax();

        int taxNew();
    
        char type;
        int price;
};


#endif
