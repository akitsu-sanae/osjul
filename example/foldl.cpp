/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <iostream>
#include <initializer_list>
#include <osjul/functional/foldl.hpp>

int plus(int lhs, int rhs) {
    return lhs + rhs;
}

int main() {
    using namespace osjul::functional;
    std::initializer_list<int> list = {1, 2, 3, 4, 5};
    std::cout << foldl % plus % 0 % list << std::endl;
}


