#include "vector.h"
#include <iostream>
using namespace std;
template <typename T>
void Vector<T>::reset(){

    size = 0;
    capacity = 1;
    vector = new T[capacity];
}
template <typename T>
void Vector<T>::resize(){

    T *temp = new T[2 * capacity];
    for(int i = 0; i < capacity; i++) {
        
        temp[i] = vector[i];
    }
    delete[] vector;
    vector = temp;
}
template <typename T>
void Vector<T>::sizeDown(){

    if(size > capacity / 2){

        return;
    }
    capacity /= 2;
    resize();
}
template <typename T>
void Vector<T>::sizeUp(){

    resize();
    capacity *=2;
}
template <typename T>
Vector<T>::Vector(){ 
    reset(); 
}
template <typename T>
Vector<T>::Vector(const Vector& v):size(v.size), capacity(v.capacity), vector(new T[v.size]) {
    for (int i = 0; i < size; i++)
    {
        this->vector[i] = v.vector[i];
    }
    
}
template <typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> & rhs){

    if (this != &rhs)
    {
        this -> size = rhs.size;
        delete[] vector;
        this->vector = new T[rhs.size];

        for (int i = 0; i < size; i++)
        {
            this->vector[i] = rhs.vector[i];
        }
    }
    
    
    return *this;
}
template <typename T>

Vector<T>::Vector(Vector<T> && v) {

    size = v.size;
    capacity = v.capacity;
    vector = v.vector;

    v.size = 0;
    v.capacity = 0;
    v.vector = nullptr;
}
template <typename T>
Vector<T> & Vector<T>::operator=(Vector<T> && v){

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

template <typename T>
Vector<T>::~Vector(){ 
    delete[] vector; 
}
template <typename T>
int Vector<T>::getCapacity() {

    return capacity;
}
template <typename T>
int Vector<T>::getSize() {

    return size;
}
template <typename T>
bool Vector<T>::isEmpty() {

    return size == 0;
}
template <typename T>
T Vector<T>::getAt(int position) {

    if(!isEmpty()) return vector[position];
}
template <typename T> 
int Vector<T>::getFirst() {

    if(!isEmpty()) return vector[0];
}
template <typename T>
int Vector<T>::getLast() {

    return vector[size - 1];
}
template <typename T>
void Vector<T>::assign(int n, int x) {

    delete[] vector;
    reset();
    for(int i = 0; i < n; i++){

        pushBack(x);
    }
}
template <typename T>
void Vector<T>::pushBack(T x){

    if (size == capacity)
    {
        sizeUp();
    }
    
    vector[size] = x;
    size++;
    
}
template <typename T>

void Vector<T>::popBack(){

    size--;
}
template <typename T>
void Vector<T>::removeAt(int position){

    if(isEmpty() || position >= size) return;
    size--;
    for(int position; position < size; position++) {

        vector[position] = vector[position + 1];
    }
    sizeDown();

}
template <typename T>
void Vector<T>::print() const {

    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " "; 
    }
    cout << '\n';
}




