#include "Date.h"
#include <exception>

Date::Date(): date(String()), year{0}, month{0}, day{0} {}

Date::Date(unsigned int year, unsigned int month, unsigned int day): year(year), month(month), day(day) {
    std::cout << "constr called!";
    date = String("josh");
}

Date::Date(const char* s): date{String(s)} {}

Date::Date(const Date& d): year{d.year}, month{d.month}, day{d.day} {}

Date& Date::operator=(const Date& d) {

    if (this != &d)
    {
        year = d.year;
        month = d.month;
        day = d.day;
    }
    
    return *this;
}

Date Date::operator-(const Date& d) {

    Date diff;
    diff.year = year - d.year;
    diff.month = month - d.month;
    diff.day = day - d.day;

    return diff;
}

std::istream& operator>>(std::istream& is, Date& d){

    char not_read;
    int monthsThirty[] = { 2, 4, 6, 9, 11 };
    is >> d.year >> not_read;
    //checking if the year format is correct
    if (d.year >= 2050 || d.year <= 1000)
    {
        throw "Wrong year format.";
    }
    //checking if the numbers are separeted correctly
    if (not_read != '.')
    {
        throw "Expected a '.'";
    }
    
    is >> d.month >> not_read ;
    //checking if the month format is correct
    if (d.month > 12 || d.month < 1)
    {
        throw "Wrong month format.";
    }
    //checking if the numbers are separeted correctly
    if (not_read != '.')
    {
        throw "Expected a '.'";
    }
    
    is >> d.day;
    //checking if the day format is correct
    if (d.month == 2 && d.day > 28)
    {
        throw "This month does not have more than 28 days!";
    }
    if (d.day > 31 || d.day < 1)
    {
        for (int i = 0; i < 5; i++)
        {
            if (d.month == monthsThirty[i] && d.day >= 31)
            {
                throw "This month does not have more than 30 days!";
            }
        }
        throw "Wrong day format.";
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {

    os << d.year << "-" << d.month << "-" << d.day << '\n';
    return os;
}

bool Date::operator<(const Date& d) {

    if (year < d.year)
    {
        return true;
    }
    if (year == d.year && month < d.month)
    {
        return true;
    }
    if (year == d.year && month == d.month && day < d.day)
    {
        return true;
    }
    return false;
    
} 
bool Date::operator>(const Date& d) {

    if (year > d.year)
    {
        return true;
    }
    if (year == d.year && month > d.month)
    {
        return true;
    }
    if (year == d.year && month == d.month && day > d.day)
    {
        return true;
    }
    return false;
}
bool Date::operator==(const Date& d) {

    return (year == d.year && month == d.month && day == d.day);
}
bool Date::operator!=(const Date& d) {

    return (year != d.year || month != d.month || day != d.day);
}

bool Date::operator<=(const Date& d) {

        if (year < d.year)
    {
        return true;
    }
    if (year == d.year && month < d.month)
    {
        return true;
    }
    if (year == d.year && month == d.month && day <= d.day)
    {
        return true;
    }
    return false;
}

unsigned int Date::getYear() { return year; }
unsigned int Date::getMonth() { return month; }
unsigned int Date::getDay() { return day; }

String Date::getDate() { return this->date; }
