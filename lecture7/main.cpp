#include "graph.h"
#include "graph.cpp"

#include <string>

int main() {

    Graph cities<std::string, double>;


    cities.addEdge("Sofia", "Rome", 350);
    cities.addEdge("Rome", "Sofia", 350);

    std::cout << cities.hasEdge("Rome", "Sofia", 350)  << std::endl;


    cities.addEdge("Sofia", "Milan", 30);
    cities.addEdge("Milan", "Sofia", 25);


    for (std::string neighb : cities["Sofia"]){

        std::cout << neighb << "\n";
    }
}