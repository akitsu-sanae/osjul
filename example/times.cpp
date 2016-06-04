#include <iostream>

#include "../osjul/times.hpp"


int main() {
    using namespace osjul;
    10_times
        >  [](int i) { std::cout << i << std::endl; }
        >= []() { std::cout << "---------------" << std::endl; }
        >  [](int i) { std::cout << i*2 << std::endl; }
        ;
}

