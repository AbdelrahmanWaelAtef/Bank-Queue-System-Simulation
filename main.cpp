#include <iostream>
#include <time.h>
#include "customer.h"
#include "Time.h"
#include "stack.h"
#include "teller.h"
using namespace std;

customer timeComparison(customer customer1, customer customer2){
    if (customer1.getArrivalTime().getHour() < customer2.getArrivalTime().getHour()) {
        return customer1;
    }
    if (customer1.getArrivalTime().getHour() > customer2.getArrivalTime().getHour()){
        return customer2;
    }
    if (customer1.getArrivalTime().getMinute() < customer2.getArrivalTime().getMinute()){
        return customer1;
    }
    if (customer1.getArrivalTime().getMinute() > customer2.getArrivalTime().getMinute()){
        return customer2;
    }
    return customer1;
}

bool timeEquality(Time time1, Time time2){
    if (time1.getHour() == time2.getHour()){
        if (time1.getMinute() == time2.getMinute()){
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    const char *firstName[100] = {"Ahmed ", "Mohamed ", "Ali ", "Fahd ",
                                "Ossama ", "Yousouf ", "Eyad ", "Abdelrahman ",
                                "Mostafa ", "Khaled ", "Khalil ", "Hany ",
                                "Fares ", "Karim ", "Abdelmalek ", "Sherif ",
                                "Gamal ", "Omar ", "Zeyad ","Shehab ", "Yassin ",
                                "Ayman ", "Shady ", "Salah ", "Sameh ", "Ashraf ",
                                "Emad ", "Fady ", "Wael ", "Atef ", "Taha ", "Medhat ",
                                "Abdelmalek ", "Moataz ", "Fawzy ", "Amr ", "Marawan ",
                                "David ", "Mario ", "Daniel ", "Basil ", "Gasser ", "Tarek ",
                                "Yahia ", "Islam ", "Yasser ", "Essam ", "Hassan ", "Hussein",
                                "Abdullah ", "Fayez ", "Kamal ", "Ibrahim ", "Badr ", "Mohsen ",
                                "Seif ", "Abdelraof ", "Hatem ", "Tamer ", "Adam ", "Adham ",
                                "Amir ","Aser ", "Anas ", "Basem ", "Tawfik ", "Hazem",
                                "Dawood ", "Ramy ", "Samer ", "Mayar ", "Rawan ", "Aysel ",
                                "Sara ", "Yasmin ", "Doaa ", "Heba ", "Mariam ", "Sarraa ", "Farida ",
                                "Reem ", "Fatima ", "Salma ", "Nada ", "Malak ", "Sohaila ", "Zeina ",
                                "Rana ", "Habiba ", "Jomana ", "Nadine ", "Nermeen ", "Aya", "Ranya ",
                                "Rabab", "Reham ", "Radwa ", "Zahra ", "Samira ", "Shahd "};
    const char *lastName[70] = {"Ahmed ", "Mohamed ", "Ali ", "Fahd ",
                                 "Ossama ", "Yousouf ", "Eyad ", "Abdelrahman ",
                                 "Mostafa ", "Khaled ", "Khalil ", "Hany ",
                                 "Fares ", "Karim ", "Abdelmalek ", "Sherif ",
                                 "Gamal ", "Omar ", "Zeyad ","Shehab ", "Yassin ",
                                 "Ayman ", "Shady ", "Salah ", "Sameh ", "Ashraf ",
                                 "Emad ", "Fady ", "Wael ", "Atef ", "Taha ", "Medhat ",
                                 "Abdelmalek ", "Moataz ", "Fawzy ", "Amr ", "Marawan ",
                                 "David ", "Mario ", "Daniel ", "Basil ", "Gasser ", "Tarek ",
                                 "Yahia ", "Islam ", "Yasser ", "Essam ", "Hassan ", "Hussein",
                                 "Abdullah ", "Fayez ", "Kamal ", "Ibrahim ", "Badr ", "Mohsen ",
                                 "Seif ", "Abdelraof ", "Hatem ", "Tamer ", "Adam ", "Adham ",
                                 "Amir ","Aser ", "Anas ", "Basem ", "Tawfik ", "Hazem",
                                 "Dawood ", "Ramy ", "Samer "};
    stack customers;
    string customerName;
    customers = stack(200);
    for (int i = 0; i < 200; i++){
        customerName = firstName[rand()%100];
        customerName.append(lastName[rand()%70]);
        customers.push(customer(customerName, (rand()%10 + 7),rand()%60));
    }
    int size;
    cout << "How many tellers are there? " << endl;
    cin >> size;
    teller *list;
    list = new teller[size];
    string name;
    int processTime;
    int size1;
    for(int i = 0; i < size; i++){
        name = "Teller";
        name.append(to_string(i+1));
        cout << "Teller" << i+1 << ":" << endl;
        cout << "Size of line: ";
        cin >> size1;
        cout << endl << "Processing time: ";
        cin >> processTime;
        cout << endl;
        list[i] = teller(size1, processTime, name);
    }
    Time time1 = Time(0,0);
    Time time2 = Time(23,59);
    customer currentCustomer;
    int least;
    while(!timeEquality(time1,time2)){
        least = 0;
        currentCustomer = customers.getCustomer(time1);
        if (currentCustomer.getName() == "test"){
            for(int i = 0; i < size; i = i + 1) {
                list[i].checkLeave(time1);
            }
            time1.addMinutes(1);
            continue;
        }
        for(int i = 0; i < size; i = i + 1){
            list[i].checkLeave(time1);
            if (list[i].getCount() < list[least].getCount()){
                least = i;
            }
        }
        list[least].addCustomer(currentCustomer, time1);
        time1.addMinutes(1);
    }
    }