#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector {

    public:
    Vector();
    Vector(const Vector & v);
    Vector & operator=(const Vector & rhs);
    Vector(Vector && v);
    Vector & operator=(Vector && v);
    int getCapacity();
    int getSize();
    bool isEmpty();
    int getAt(int position);
    int getFirst();
    int getLast();
    void assign(int n, int x);
    void pushBack(int x);
    void popBack();
    void removeAt(int position);
    void print() const;
    ~Vector();

    private:
    int size, capacity;
    int *vector;

    void reset();
    void resize();
    void sizeDown();
    void sizeUp();

};

#endif