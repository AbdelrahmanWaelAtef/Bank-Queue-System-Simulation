//
// Created by Abdelrahman Wael on 3/27/2022.
//

#include "stack.h"
#include <iostream>
#include "customer.h"
#include "Time.h"
#include <string>
using namespace std;

bool timeEquality(Time time1, Time time2);
stack::stack(){
    size = 100;
    top = -1;
    list = new customer[size];
}
stack::stack(int size){
    this -> size = size;
    top = -1;
    list = new customer[size];
}
bool stack::isEmpty(){
    return top == -1;
}
bool stack::isFull(){
    return top == (size - 1);
}
customer stack::peak(){
    if (isEmpty()) {
        cout << "The stack is empty" << endl;
        return customer();
    }
    return list[top];
}
customer stack::pop(){
    if (isEmpty()){
        cout << "The stack is empty" << endl;
        return customer();
    }
    return list[top--];
}
void stack::push(customer customer){
    if (isFull()){
        cout << "The stack is full" << endl;
        return;
    }
    list[++top] = customer;
}
customer stack::getCustomer(Time time) {
    for (int i = 0; i < size; i++){
        if(timeEquality(list[i].getArrivalTime(), time)){
            return list[i];
        }
    }
    return customer();
}