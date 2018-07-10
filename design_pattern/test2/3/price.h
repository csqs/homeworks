#ifndef PRICE_H
#define PRICE_H


class Price{
    public:
        Price(char input_type, int input_price);
        ~Price();

        void priceSum();
    
        char type;
        int price;
};


#endif
