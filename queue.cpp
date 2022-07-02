//
// Created by Abdelrahman Wael on 3/27/2022.
//

#include "queue.h"
#include <iostream>
#include "customer.h"
#include <string>

queue::queue(){
    size = 100;
    front = 0;
    rear = size - 1;
    count = 0;
    list = new customer[size];
}
queue::queue(int size){
    this -> size = size;
    front = 0;
    rear = size - 1;
    count = 0;
    list = new customer[size];
}
void queue::clear(){
    for(int i = 0;i < count; i = (i+1)%size){
        list[i] = customer();
    }
    front = 0;
    rear = size - 1;
    count = 0;
}
bool queue::isEmpty(){
    return count == 0;
}
bool queue::isFull(){
    return count == size;
}
customer queue::first(){
    if (isEmpty()){
        cout << "The queue is empty!" << endl;
        return customer();
    }
    return list[front];
}
customer queue::last(){
    if (isEmpty()){
        cout << "The queue is empty!" << endl;
        return customer();
    }
    return list[rear];
}
customer queue::dequeue(){
    if (isEmpty()){
        cout << "The queue is empty!" << endl;
        return customer();
    }
    count --;
    customer first = list[front];
    front = (front + 1) % size;
    return first;
}
void queue::enqueue(customer last){
    if (isFull()){
        cout << "The queue is full!" << endl;
        return;
    }
    count ++;
    rear = (rear + 1)%size;
    list[rear] = last;
}