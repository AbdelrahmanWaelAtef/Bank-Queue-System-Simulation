//
// Created by Abdelrahman Wael on 3/27/2022.
//

#ifndef UNTITLED6_TIME_H
#define UNTITLED6_TIME_H
#include <string>

class Time{
private:
    int minute;
    int hour;
public:
    Time();
    Time(int hour, int minute);
    void showTime();
    int getMinute();
    int getHour();
    void addMinutes(int mins);
};


#endif //UNTITLED6_TIME_H
