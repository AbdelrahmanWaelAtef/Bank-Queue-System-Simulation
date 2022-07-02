//
// Created by Abdelrahman Wael on 3/27/2022.
//

#include "Time.h"
#include <string>
#include <iostream>
using namespace std;

Time::Time(){
    minute = 59;
    hour = 23;
}
Time::Time(int hour, int minute){
    this->hour = hour;
    this->minute = minute;
}
void Time :: showTime(){
    string min = "0";
    if (minute < 10){
        min.append(to_string(minute));
        cout << hour << ":" << min;
        return;
    }
    cout << hour << ":" << minute;
}
int Time:: getMinute(){
    return minute;
}
int Time:: getHour(){
    return hour;
}
void Time:: addMinutes(int mins){
    minute = minute + mins;
    hour = hour + (minute/60);
    minute = minute%60;
}