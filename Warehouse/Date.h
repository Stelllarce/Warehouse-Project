#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "../String/Stringh.h"
<<<<<<< HEAD
#include "Item.h"
=======
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

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
<<<<<<< HEAD
    //getters
    unsigned int getYear();
    unsigned int getMonth();
    unsigned int getDay();
    String getDate();
=======
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
    //operators
    Date& operator=(const Date& d);
    //time period bewteen two dates
    Date operator-(const Date& d);

    bool operator<(const Date& d); 
<<<<<<< HEAD
    bool operator<=(const Date& d); 
=======
>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5
    bool operator>(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    //friends
    friend std::ostream& operator<<(std::ostream& stream, const Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d);
<<<<<<< HEAD
    //friend void Item::save(std::ofstream &os);
=======

>>>>>>> 523906c2b62b4c52a65d78c141338b6823b6cce5

};

    std::ostream& operator<<(std::ostream& stream, const Date& d);
    std::istream& operator>>(std::istream& is, Date& d);


#endif