#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "../String/Stringh.h"
#include "Item.h"

class Date {

    private:

    String date;
    unsigned int year, month, day;

    public:

    //constructors
    Date();
    Date(const char* s);
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(const Date& d);
    ~Date(){}
    //getters
    unsigned int getYear();
    unsigned int getMonth();
    unsigned int getDay();
    //operators
    Date& operator=(const Date& d);
    //time period bewteen two dates
    Date operator-(const Date& d);

    bool operator<(const Date& d); 
    bool operator<=(const Date& d); 
    bool operator>(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    //friends
    friend std::ostream& operator<<(std::ostream& stream, const Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d);
    //friend void Item::save(std::ofstream &os);

};

    std::ostream& operator<<(std::ostream& stream, const Date& d);
    std::istream& operator>>(std::istream& is, Date& d);


#endif