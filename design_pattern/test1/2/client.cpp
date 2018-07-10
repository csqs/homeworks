#include "client.h"
#include "house.h"

#include <string>
#include <iostream>



Client::Client(int size_temp, int decr_temp, int style_temp) {
	size = size_temp;
	decr = decr_temp;
	style = style_temp;
}

Client::~Client() {
}

int Client::getPrice() {
   House one_house(this->size, this->decr, this->style);
   return one_house.priceSum();
}

