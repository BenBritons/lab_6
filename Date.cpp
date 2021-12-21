//
// Created by Ivan on 20.12.21.
//

#include "Date.h"


    Date Date::NextDay(){
    Date a = Date(day, month, year);
    switch (month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day == 31){
                a.day = 1;
                if(month == 12){
                    a.month = 1;
                    a.year++;
                } else{
                    a.month++;
                }
            }else {
                a.day++;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day == 30){
                a.day = 1;
                a.month++;
            } else {
                a.day++;
            }
            break;
        case 2:
            if(day == 29) {
                a.day = 1;
                a.month++;
            } else {
                a.day++;
            }
            break;
    }
    return a;
}

Date Date::PreviousDay(){
    Date a = Date(day, month, year);
    switch (month){
        case 2:
        case 4:
        case 6:
        case 8:
        case 9:
        case 11:
        case 1:
            if (day == 1){
                a.day = 31;
                if(month == 1){
                    a.month = 12;
                    a.year--;
                } else{
                    a.month--;
                }
            }else {
                a.day--;
            }
            break;
        case 5:
        case 7:
        case 10:
        case 12:
            if (day == 1){
                a.day = 30;
                a.month--;
            } else {
                a.day--;
            }
            break;
        case 3:
            if(day == 1) {
                a.day = 29;
                a.month--;
            } else {
                a.day--;
            }
            break;
    }
    return a;
}


bool Date::IsLeap(){
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

short  Date::WeekNumber() {
    short n;
    n = (month - 1) * 4 + (day / 7);
    return n;
}

int Date::DaysTillYourBithday(Date bithdaydate) {
    short birth_day = bithdaydate.day;
    short birth_month = bithdaydate.month;
    short birth_year;
    if ((day >= birth_day && month == birth_month)|| month >= birth_month){
        birth_year = year + 1;
    } else{
        birth_year = year;
    }
    return(Duration(Date(birth_day, birth_month, birth_year)));
}

int Date::Duration(Date date) {
    long time1 = 0;
    long time2 = 0;
    Date tmp = Date(day, month, year);

    while(tmp.day!=1 || tmp.month!=1 || tmp.year!=0){
        tmp = tmp.PreviousDay();
        time1++;
    }

    while(date.day!=1 || date.month!=1 || date.year != 1){
        date = date.PreviousDay();
        time2++;
    }

    int k = abs(time1-time2);

    return k;

}

string Date::ToString() {
    return std::to_string(day) + "." + std::to_string(month)  + "." + std::to_string(year);
}

short Date::getDay() const {
    return day;
}

short Date::getMonth() const {
    return month;
}

short Date::getYear() const {
    return year;
}

void Date::setDay(short day) {
    Date::day = day;
}

void Date::setMonth(short month) {
    Date::month = month;
}

void Date::setYear(short year) {
    Date::year = year;
}

