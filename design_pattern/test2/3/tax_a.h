#ifndef TAX_A_H
#define TAX_A_H


class Tax_a{
    public:
        Tax_a(float input_tax_rate, int input_price);
        ~Tax_a();

        int taxMethod();
    
        float tax_rate;
        int price;
};


#endif
