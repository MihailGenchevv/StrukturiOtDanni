#include <iostream>



int main() {


    dict (10, h);

    std::cout << dict["dog"] << std::endl;


    dict["dog"] = 0;

    if (dict.hasKey("dog")) {
        std::cout << "yes" << std::endl;
    }

    for (std::string key : dict) {
        std::cout << key << dict[key];
    }
}