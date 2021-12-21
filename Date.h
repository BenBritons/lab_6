//
// Created by Ivan on 20.12.21.
//

#ifndef LAB_6_DATE_H
#define LAB_6_DATE_H
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::vector;
using std::string;

class Date{
private:
    short int day;
    short int month;
    short int year;

public:
    Date(short int d, short int m, short int y){
        day = d;
        month = m;
        year = y;
    }

    void setDay(short day);

    void setMonth(short month);

    void setYear(short year);

    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBithday(Date bithdaydate);
    int Duration(Date date);
    string ToString();

    short getDay() const;

    short getMonth() const;

    short getYear() const;

};


#endif //LAB_6_DATE_H
