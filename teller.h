//
// Created by Abdelrahman Wael on 3/27/2022.
//

#ifndef UNTITLED6_TELLER_H
#define UNTITLED6_TELLER_H
#include <iostream>
#include <time.h>
#include "customer.h"
#include "Time.h"
#include "stack.h"
#include "queue.h"
using namespace std;

class teller{
private:
    queue line;
    int processTime;
    string name;
    int count;
    int size;
public:
    teller();
    teller(int size, int processTime, string name);
    void addCustomer(customer Customer1, Time time);
    int getCount();
    void checkLeave(Time time);
    customer getLast();
};


#endif //UNTITLED6_TELLER_H
