#ifndef TAX_B_H
#define TAX_B_H


class Tax_b{
    public:
        Tax_b(float input_tax_rate, int input_price);
        ~Tax_b();

        int taxMethod();
    
        float tax_rate;
        int price;
};


#endif
