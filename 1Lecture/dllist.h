#ifndef __DLLIST_H
#define __DLLIST_H 

#include <iostream>

template <class T> 
class DLList  {

private:
    struct box {
        T data;
        box *next , *prev;

    };


public:
    DLList();
    DLList(const DLList<T>&);
    DLList<T>& operator=(const DLList<T>&); 
    ~DLList();

    DLList<T> operator+(const T&) const;  

    DLList<T>& operator+=(const T&);



    class Iterator {
    public:
        Iterator(box *_current);
        T& operator* ();
        Iterator& operator ++();
        bool operator!= (const Iterator&);
    private:
        box *current;

    };

    Iterator begin();  
    Iterator end();

private:
    box *first;

    // BAD PRACTICE!!!
    template <class E>
    friend std::ostream& operator<<(std::ostream&, const DLList<E>&);

    void copy(const DLList<T>&);

    void clear();
};

template <class T>
std::ostream& operator<<(std::ostream&, const DLList<T>&);

#include "dllist.cpp"

#endif 