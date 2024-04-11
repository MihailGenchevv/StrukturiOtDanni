#include "bintree.h"
#include "bintree.cpp"


int main() {

    BinTree<int> t;

    t.add(10, "");
    t.add(20, "L");
    t.add(30, "R");
    t.add(40, "LL");
    t.add(50, "LLL");
    t.add(60, "LLR");

    // std::ofstream out("tree.scheme");
    // t.printall(std::cout);
    t.toScheme(std::cout);

}