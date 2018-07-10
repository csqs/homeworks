#ifndef HOUSE_H
#define HOUSE_H


class House{
    public:
        House(int size_temp, int decr_temp, int style_temp);
        ~House();

        int priceSum();
        
        int size;
        int decr;
        int style;

};

#endif
