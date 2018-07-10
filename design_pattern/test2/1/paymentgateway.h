#ifndef PAYMENTGATEWAY_H
#define PAYMENTGATEWAY_H


class PaymentGateway{
    public:
        PaymentGateway(int input_number);
        ~PaymentGateway();

        bool payNotify();
    
        int paynumber;
};


#endif
