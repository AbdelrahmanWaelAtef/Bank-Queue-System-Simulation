//
// Created by Abdelrahman Wael on 3/27/2022.
//

#ifndef UNTITLED6_QUEUE_H
#define UNTITLED6_QUEUE_H
#include "stack.h"
#include <iostream>
#include "customer.h"
#include "Time.h"
#include <string>
using namespace std;

class queue{
private:
    int size;
    int front;
    int rear;
    int count;
    customer *list;
public:
    queue();
    queue(int size);
    void clear();
    bool isEmpty();
    bool isFull();
    customer first();
    customer last();
    customer dequeue();
    void enqueue(customer last);
};


#endif //UNTITLED6_QUEUE_H
