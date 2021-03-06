/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/
#include <string>
#include <vector>
#include <iostream>
#include <osjul/adaptor.hpp>

bool bigger_than_30(int n) {
    return n > 30;
}

int main() {
    using namespace osjul;

    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    make_range(data)
        | filter >> [](int i) { return i%3 != 0; }
        | map >> [](int i) { return 3*i*i + 4*i + 5; }
        | filter >> bigger_than_30
        | each >> [](int i) { std::cout << i << std::endl; }
        | reverse
        | once >> []() { std::cout << "------ reversed ------" << std::endl; }
        | each >> [](int i) { std::cout << i << std::endl; }
        | once >> []() { std::cout << "------ adjacent ------" << std::endl; }
        | adjacent_each >> [](int a, int b) { std::cout << "(" << a << ", " << b << ")" << std::endl; }
        | adjacent_filter >> [](int a, int b) { return a + b < 500; }
        | adjacent_map >> [](int a, int b) { return a+b; }
        | once >> []() { std::cout << "-- filter: a+b < 500 -" << std::endl; }
        | each >> [](int i) { std::cout << i << std::endl; }
        | sort
        | once >> []() { std::cout << "-------- sort --------" << std::endl; }
        | each_width_index >> [](int n, int i) { std::cout << i << ":" << n << std::endl; }
        | once >> []() { std::cout << "----------------------" << std::endl; }
        | adjacent_each_with_index >> [](int a, int b, int i) { std::cout << i << ":  (" << a << ", " << b << ")" << std::endl; }
        | once >> []() { std::cout << "----------------------" << std::endl; }
        | sort >> [](int a, int b) { return a > b; }
        | each >> [](int n) { std::cout << n << std::endl; }
        ;
}

