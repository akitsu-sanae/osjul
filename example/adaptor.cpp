/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/
#include <string>
#include <vector>
#include <osjul/adaptor.hpp>
#include <iostream>

bool bigger_than_30(int n) {
    return n > 30;
}

int main() {
    using namespace osjul;

    // get a_n = 3n^2 + 4n + 5 when n%3 = 0 and a_n > 30
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    make_range(data)
        >> filter / [](int i) { return i%3 != 0; }
        >> map / [](int i) { return 3*i*i + 4*i + 5; }
        >> filter / bigger_than_30
        >> each / [](int i) { std::cout << i << std::endl; }
        >> reverse
        >> once / []() { std::cout << "------ reversed ------" << std::endl; }
        >> each / [](int i) { std::cout << i << std::endl; }
        ;
}

