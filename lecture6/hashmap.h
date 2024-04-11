#pragma once 

#include <functional>

template <class Keys, class Values>
class HashMap {

public:
    HashMap(size_t, std::function<size_t(Keys)>);
    Values operator [](const Keys&) const;
    Values& operator [](const Keys&);

    bool hasKey(const  Keys&) const;

    private:
    struct Entry {
        Keys key;
        Values value;
        Entry *next;
    };

    public:
    class Iterator {

        public:
        Iterator(Entry**, size_t)

        Keys operator*() const;
        Iterator& operator++();
        bool operator !=(const Iterator&) const;

        private:
        size_t currentRow;
        Entry* currentColumn;
        Entrr **table;
        size_t size;

    }

    Iterator begin() const;
    Iterator end() const;

private:

    struct Entry {
        Keys key;
        Values value;
        Entry *next;
    };

    Entry **table;
    size_t size;

    std::function<size_t(Keys)> h;

    Entry* locate(size_t, const Keys&);


}