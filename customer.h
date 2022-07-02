//
// Created by Abdelrahman Wael on 3/27/2022.
//

#ifndef UNTITLED6_CUSTOMER_H
#define UNTITLED6_CUSTOMER_H
#include "Time.h"
#include <iostream>
using namespace std;

class customer{
private:
    string name;
    Time arrivalTime;
    Time departingTime;
public:
    customer();
    customer(string name, int hour, int minute);
    Time getArrivalTime();
    void showDetails();
    void setDepartingTime(Time time);
    Time getDepartingTime();
    string getName();
};


#endif //UNTITLED6_CUSTOMER_H
