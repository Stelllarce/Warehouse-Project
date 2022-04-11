#include "vector.h"
#include <iostream>
using namespace std;

void Vector::reset(){

    size = 0;
    capacity = 1;
    vector = new int[capacity];
}
void Vector::resize(){

    int *temp = new int[capacity];
    for(int i = 0; i < size; i++) {
        
        temp[i] = vector[i];
    }
    delete[] vector;
    vector = temp;
}
void Vector::sizeDown(){

    if(size > capacity / 2){

        return;
    }
    capacity /= 2;
    resize();
}
void Vector::sizeUp(){

    if(size < capacity){

        return;
    }
    resize();
    capacity *=2;
}
Vector::Vector(){ 
    reset(); 
}
Vector::Vector(const Vector& v):size(v.size), capacity(v.capacity), vector(new int[v.size]) {
    for (int i = 0; i < size; i++)
    {
        this->vector[i] = v.vector[i];
    }
    
}
Vector & Vector::operator=(const Vector & rhs){

    this -> size = rhs.size;
    delete[] this-> vector;
    this->vector = new int[rhs.size];
    //should it be simply this->size?
    for (int i = 0; i < size; i++)
    {
        this->vector[i] = rhs.vector[i];
    }
    return *this;
}

Vector::Vector(Vector && v) {

    size = v.size;
    capacity = v.capacity;
    vector = v.vector;

    v.size = 0;
    v.capacity = 0;
    v.vector = nullptr;
}
Vector & Vector::operator=(Vector && v){

    if (this != &v){

        delete[] vector;

        size = v.size;
        capacity = v.capacity;
        vector = v.vector;

        v.size = 0;
        v.capacity = 0;
        v.vector = nullptr;
    }
    return *this;
}

Vector::~Vector(){ 
    delete[] this->vector; 
}
int Vector::getCapacity() {

    return capacity;
}
int Vector::getSize() {

    return size;
}
bool Vector::isEmpty() {

    return size == 0;
}
int Vector::getAt(int position) {

    if(!isEmpty()) return vector[position];
} 
int Vector::getFirst() {

    if(!isEmpty()) return vector[0];
}
int Vector::getLast() {

    return vector[size - 1];
}
void Vector::assign(int n, int x) {

    delete[] vector;
    reset();
    for(int i = 0; i < n; i++){

        pushBack(x);
    }
}
void Vector::pushBack(int x){

    sizeUp();
    vector[size] = x;
    size++;
    
}

void Vector::popBack(){

    sizeDown();
    size--;
}
void Vector::removeAt(int position){

    if(isEmpty() || position >= size) return;
    size--;
    for(int position; position < size; position++) {

        vector[position] = vector[position + 1];
    }
    sizeDown();

}
void Vector::print() const {

    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " "; 
    }
    cout << '\n';
}