#include <iostream>
#include <cstring>
#include "Stringh.h"
    
    void String::resize(size_t capacity) { 
    
        this->capacity = capacity;
        char* temp = new char[this->capacity];
        strcpy(temp, string);
        delete string;
        string = temp;
    }

    char* strcpy(char* destination, const char* source)
    {
        if (destination == nullptr) {
            return nullptr;
        }

        char *ptr = destination;

        while (*source != '\0') {
            
            *destination = *source;
            destination++;
            source++;
        }

        *destination = '\0';
        return ptr;
    }

    unsigned int strlen_s(const char *s){
        
        unsigned int count = 0;
        while(*s!='\0')
        {
            count++;
            s++;
        }
        return count;
    }
    String::String(): string{ nullptr }, capacity(0), len(0) {}
    
    // String::String(char *s): string{ new char[strlen(s) + 1]}, len{strlen(s)}, capacity{len} {

    //     strcpy(string, s);
    // }

    String::String(const char *s): string{ new char[strlen(s) + 1]}, len(strlen(s)), capacity(strlen(s)) {

        //std::cout << len << " and strlen: " << capacity << '\n';
        strcpy(string, s);
    }

    String::String(const String& s): capacity{s.capacity}, len{s.len}, string{new char[strlen(s.string) + 1]} {
        
        //std::cout << "Copy" << '\n';
        strcpy(string, s.string);
    }

    String::String(String&& s): string{s.string}, len{s.len}, capacity{s.capacity} {

        //std::cout << "Move" << '\n';
        s.string = nullptr;
        s.len = 0;
        s.capacity = 0;

    }

    size_t String::get_size() { return len; }
    
    size_t String::get_capacity() { return capacity; }
    
    // char* String::get_string() { return string; }

    char String::get_at(size_t pos) { 

        if (pos >= get_size())
        {
            return '\0';
        }
        return string[pos];
    }
    char String::get_back() { return string[strlen(this->string) - 1]; }
    
    char String::get_front() { return string[0]; }

    String& String::operator=(const String& s) {

        delete[] string;
        if (this != &s)
        {
            strcpy(this->string, s.string);
            this->capacity = s.capacity;
            this->len = s.len;
        }
        
        return *this;
    }
    //gotta check if this is right
    String& String::my_append(const String& s) {

        if (this->capacity < s.len + this->len)
        {
            resize(capacity + s.len + 1);            
        }
        int j;
        for (int i = this->len + 1; i < this->capacity; i++)
        {
            this->string[i] = s.string[j++];
        }
         
        return *this;
    }
    
    void String::my_push_back(char c) {

        if (this->capacity == this->len)
        {
            resize(2 * capacity);            
        }
        this->string[strlen(string) - 1] = c;
        this->string[strlen(string)] = '\0';
    }
    //should double check values in for loop
    String& String::my_insert (size_t p, const String& s) {

        if (this->capacity == this->len)
        {
            resize(capacity + s.len + 1);            
        }
        int counter = 0, j = 0;
        size_t temp = p;
        do
        {
            for (int i = len - 1; i > p; i--)       
            {
                string[i + 1] = string[i];
            }
            string[temp++] = s.string[j++];
            counter++;
        } while (s.len >= counter);
        
        return *this;
    }

    String& String::erasePos(size_t pos) {

        for (int i = pos; i < len; i++)
        {
            string[i] = string[i + 1];
        }
        this->len--;
        return *this;
    }

    String& String::eraseChar(char c) {

        for (int i = 0; i < len; i++)
        {
            if (string[i] == c)
            {
                this->erasePos(i);
            }
            
        }
        return *this;
    }
    String& String::my_replace(size_t pos, const String& s) {

        if (this->capacity == this->len)
        {
            resize(capacity + s.len + 1);            
        }
        int j = 0;
        for (int i = pos; i < capacity; i++)
        {
            string[i] = s.string[j++];
        }
        string[capacity - 1] = '\0';
        return *this;
    }

    void String::my_swap(String& s) {

        if (this->capacity < s.len)
        {
            this->resize(s.len);
        } else {

            s.resize(this->len);
            s.len = s.capacity;
        } 
        // String temp;
        // temp = s;
        // s = *this;
        // *this = temp;

        char* temp = s.string;
        s.string = string;
        string = temp;
    }

    void String::my_pop_back() { 
    
        string[len - 1] = '\0';
        len--;
        capacity--;
    }

    bool operator<(const String& s,const String& s1) { return (strcmp(s.string, s1.string) < 0); }

    bool operator>(const String& s, const String& s1) { return (strcmp(s.string, s1.string) > 0); }

    bool operator==(const String& s, const String& s1) { return (strcmp(s.string, s1.string) == 0); } 

    bool operator>=(const String& s, const String& s1) { return (strcmp(s.string, s1.string) >= 0); }

    bool operator<=(const String& s, const String& s1) { return (strcmp(s.string, s1.string) <= 0); }

    bool operator!=(const String& s, const String& s1) { return (strcmp(s.string, s1.string) != 0); }


    const char* String::cStr() const { return string; }

    String String::my_substr(size_t pos, size_t len) const { 
    
        String substr;
        int j = 0;
        for (int i = pos; i < pos + len; i++)
        {
            substr.string[j] = string[i];
            j++;
        }
        substr.capacity = capacity;
        substr.len = len;
        return substr;
    }

    String operator+(const String s, const String s1) {

        String newString;
        newString.string = strcat(s.string, s1.string);
        newString.len = strlen(newString.string);
        newString.capacity = newString.len;
        return newString;
    }

    std::ostream& operator<<(std::ostream& os, const String& s) {

        for (int i = 0; i < strlen(s.string); i++)
        {
            os << s.string[i];
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, String& s) {

        const int BUFFER = 2048;
        char buf[BUFFER];
        is.get(buf, BUFFER, '\n');

        s = String(buf);
        return is;
    }

    String::~String() {

        //std::cout << "Destr" << '\n';
        delete[] string;
    }
