#ifndef DISCOUNT_H
#define DISCOUNT_H


class Discount{
    public:
        Discount(int input_price);
        ~Discount();

        int priceNew();
    
        int price;
};


#endif
