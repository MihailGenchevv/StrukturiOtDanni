#include "dllist.h"



int main() {

    DLList<int> list;  

    list += 1;
    list += 2;
    list += 3; 
    list += 4;
    list += 5;
    std::cout << list << std::endl;


    DLList<int>::Iterator it = list.begin();

    while (it != list.end()) {
        std::cout << *it << std::endl;
        ++it;
    }

    for (int x : list ) {
        std::cout << x << std::endl;
    }


}