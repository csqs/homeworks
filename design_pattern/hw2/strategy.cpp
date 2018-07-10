#include "strategy.h"


Strategy::Strategy(float price, uint32_t maintain) {
    price = price;
    maintain = maintain;
}

Strategy::~Strategy() {
}

Patron::Patron(float price, uint32_t maintain):Strategy(price, maintain){
    this->price = price;
    this->maintain = maintain;
}

Patron::~Patron(){
}


void Patron::PatronPrice(){
    this->price = price * 0.85;
}

Holiday::Holiday(float price, uint32_t maintain):Strategy(price, maintain){
    this->price = price;
    this->maintain = maintain;
}

Holiday::~Holiday(){
}


void Holiday::HolidayPrice(){
    this->price = price * 0.8;
    this->maintain += 2;
}

