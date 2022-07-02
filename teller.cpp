//
// Created by Abdelrahman Wael on 3/27/2022.
//

#include "teller.h"
#include <iostream>
#include "customer.h"
#include "Time.h"
#include "queue.h"
using namespace std;

bool timeEquality(Time time1, Time time2);
teller::teller(){
    line = queue(10);
    processTime = 10;
    count = 0;
    size = 10;
}
teller::teller(int size, int processTime, string name){
    line = queue(size);
    this -> processTime = processTime;
    this -> name = name;
    count = 0;
    this -> size = size;
}
void teller::addCustomer(customer Customer1, Time time){
    if (count == size){
        return;
    }
    Time processing = Customer1.getArrivalTime();
    processing.addMinutes(processTime);
    Customer1.setDepartingTime(processing);
    line.enqueue(Customer1);
    cout << Customer1.getName() << "has arrived at " << name << ". (";
    time.showTime();
    cout << ")" << endl;
    count ++;
}
int teller::getCount(){
    return count;
}
void teller::checkLeave(Time time){
    if(line.isEmpty()){
        return;
    }
    if(timeEquality(line.first().getDepartingTime(), time)){
        cout << line.dequeue().getName() << "has left. (";
        time.showTime();
        cout << ")" << endl;
        count --;
    }
}
customer teller::getLast(){
    return line.last();
}