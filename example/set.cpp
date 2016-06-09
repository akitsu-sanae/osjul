/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <osjul/set.hpp>
#include <vector>
#include <iostream>
int main() {

    osjul::set<int> test = {1,2,3,4,5,6};
    test.each([](int a){return a*2;})
       .filter([](int a){ return a > 10; });

    std::vector<int> test2 = {8,6,4,2,1,3,5,7,9};
    osjul::make_set(test2)
        .filter([](int a){return a%2 == 0;})
        .apply(test2);
    for (auto&& e : test.get()) {
        std::cout << e << std::endl;
    }
    for(auto&& e : test2) {
        std::cout << e << std::endl;
    }
}





