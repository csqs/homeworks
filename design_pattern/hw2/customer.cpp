#include "customer.h"


Customer::Customer(uint32_t id, double time, uint32_t maintain, bool history) {
    id = id;
    time = time;
    maintain = maintain;
    history = history;
}

Customer::~Customer() {
}
