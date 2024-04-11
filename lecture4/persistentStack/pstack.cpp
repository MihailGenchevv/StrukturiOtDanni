#pragma once 

#include "pstack.h"
#include <cassert> 



template <class T>
pstack<T>::pstack() : first(nullptr) {}

template <class T>
pstack<T> pstack<T>::push(const T&x) const {

    return pstack<T>{std::make_shared<node>(x, first)};
}




template <class T>
pstack<T> pstack<T>::pop() const {

    return pstack<T>{first->tail};
}



template <class T>
T pstack<T>::top() const {

    assert(!empty());
    return first->head;

}



template <class T>
bool pstack<T>::empty() const {
    return ((bool)first == false);
}


template <class T>
pstack<T>::node::node(const &T _head, std::shared_prt<node> _tail) : head(_head), tail(_tail) {}