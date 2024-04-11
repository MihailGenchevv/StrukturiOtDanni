#include "hashmap.h"



template <class Keys, class Values>
HashMap<Keys,Values>::HashMap(size_t _size, std::function<size_t(Keys)> _h) : size(_size), h(_h) {

    table = new HashMap<Keys,Values>::Entry*[size];

    for (int i = 0; i < size; ++i){
        table[i]= nullptr;
    }

}

template <class Keys, class Values>
Entry* HashMap<Keys,Values>::locate(size_t index, const Keys &key){
    typename HashMap<Keys,Values>::Entry *current = table[index];
    while (current != nullptr && current->key != key) {

        current = current->next;
    }

    return current;

}


template <class Keys, class Values>
Values HashMap<Keys,Values>::operator [](const Keys &key) const{

    size_t index = h(key) % size;

    HashMap::Entry *kvpair = locate(index, key);

    assert(kvpair != nullptr);


    return kvpair->value;

}

template <class Keys, class Values>
Values& HashMap<Keys,Values>::operator [](const Keys &key){

    size_t index = h(key) % size;

    HashMap<Keys,Values>::Entry *kvpair = locate(index, key);

    if ( kvpair != nullptr) {
        return kvpair->value;
    } else {

        table[index] = new HashMap<Keys,Values>::Entry {key, Values(), table[index]};
        return table[index]->value;
    }

}


template <class Keys, class Values>
bool HashMap<Keys,Values>::hasKey(const  Keys &key) const{

    size_t index = h(key) % size;
    HashMap<Keys,Values>::Entry *kvpair = locate(index, key);

    return kvpair != nullptr;

}

template <class Keys, class Values>
HashMap<Keys,Values>::Iterator::Iterator(HahsMap<Keys,Values>::Entry** _table, size_t _size) : table(_table), size(_size) {

    currentRow = 0;
    currentColumn = nullptr;
    if (table == nullptr) {
        return;
    }
    size_t i = 0;
    while (i < size && table[i] == nullptr){
        ++i;
    }

    if (i < size) {
        currentRow = i;
        currentColumn = table[i];
    } 
}


template <class Keys, class Values>
Keys HashMap<Keys,Values>::Iterator::operator*() const {

    assert(currentColumn != nullptr)
    return currentColumn->key;
}


template <class Keys, class Values> 

HashMap<Keys,Values>::Iterator& HashMap<Keys,Values>::Iterator::operator++(){
    assert(currentColumn != nullptr)
    if (currentColumn->next != nullptr) {
        currentColumn = currentColumn->next;
    } else {
        ++currentRow;
        while (currentRow < size && table[currentRow] == nullptr){
            ++currentRow;
        }

        if (currentRow < size) {
            currentColumn = table[currentRow];
        } else {
            currentColumn = nullptr;
        }
    }
}


template <class Keys, class Values>
bool HashMap<Keys,Values>::Iterator::operator != (const HashMap<Keys,Values>::Iterator &other) const {

    return currentColumn != other.currentColumn;
}

template <class Keys, class Values>
HashMap<Keys,Values>::Iterator HashMap<Keys, Values>::begin() const {
    return HashMap<Keys, Values>::Iterator(table);
}

template <class Keys, class Values>
HashMap<Keys,Values>::Iterator HashMap<Keys, Values>::end() const {
    return HashMap<Keys, Values>::Iterator(nullptr)
} 