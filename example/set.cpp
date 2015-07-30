#include <osjul/set.hpp>
#include <iostream>
int main() {

    osjul::set<int> hoge = {1,2,3,4,5,6};
    hoge >> [](int a){return a*2;} || [](int a){ return true; };

    for (auto&& e : hoge.get()) {
        std::cout << e << std::endl;
    }
}





