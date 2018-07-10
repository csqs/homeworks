#include "house.h"

#include <string>
#include <iostream>


House::House(int size_temp, int decr_temp, int style_temp) {
	size = size_temp;
	decr = decr_temp;
	style = style_temp;
}

House::~House() {
}

int House::priceSum() {
   int price = 0;
   
   if(this->size == 1) price += 60;
   else if(this->size == 2) price += 100;
   else if(this->size == 3) price += 200;
   else return 0;
   
   if(this->decr == 1){
		price += 60;
   		if(this->style == 1) price += 60;
   		else if(this->style == 2) price += 40;
   		else if(this->style == 3) price += 30;
   		else if(this->style == 4) price += 20;
   		else return 0;
   }
   else if(this->decr == 2) price += 20;
   else if(this->decr == 3) price += 5;
   else return 0;
   
   return price;
}

