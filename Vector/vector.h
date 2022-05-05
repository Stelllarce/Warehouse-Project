#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>
using namespace std;
template <typename T> 
class Vector {

    private:
    T *vector;
    int size, capacity;

    void reset();
    void resize();
    void sizeDown();
    void sizeUp();

    public:
    //constructors
    Vector();
    Vector(const Vector & v);
    Vector<T> & operator=(const Vector<T> & rhs);
    Vector(Vector<T> && v);
    Vector<T> & operator=(Vector<T> && v);
    ~Vector();

    //getters
    int getCapacity();
    int getSize();
    T getAt(int position);
    int getFirst();
    int getLast();

    bool isEmpty();

    //operations
    void assign(int n, int x);
    void pushBack(T x);
    void popBack();
    void removeAt(int position);

    //print
    void print() const;
    
};

#endif