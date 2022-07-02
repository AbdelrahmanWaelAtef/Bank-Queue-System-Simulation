//
// Created by Abdelrahman Wael on 3/27/2022.
//

#ifndef UNTITLED6_STACK_H
#define UNTITLED6_STACK_H
#include <iostream>
#include "customer.h"
#include "Time.h"
using namespace std;


class stack{
private:
    int size;
    int top;
    customer *list;
public:
    stack();
    stack(int size);
    bool isEmpty();
    bool isFull();
    customer peak();
    customer pop();
    void push(customer customer);
    customer getCustomer(Time time);
};


#endif //UNTITLED6_STACK_H
