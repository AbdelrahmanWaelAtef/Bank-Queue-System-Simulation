//
// Created by Abdelrahman Wael on 3/27/2022.
//

#include "customer.h"
#include <iostream>
using namespace std;

customer::customer(){
    name = "test";
    arrivalTime = Time(0, 0);
}
customer::customer(string name, int hour, int minute){
this -> name = name;
arrivalTime = Time(hour, minute);
}
Time customer::getArrivalTime(){
    return arrivalTime;
}
void customer::showDetails(){
    cout << name << endl;
    arrivalTime.showTime();
}
void customer::setDepartingTime(Time time){
    this -> departingTime = time;
}
Time customer::getDepartingTime(){
    return departingTime;
}
string customer::getName(){
    return name;
}