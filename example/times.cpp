/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <iostream>
#include <osjul/times.hpp>


int main() {
    using namespace osjul;
    10_times
        >  [](int i) { std::cout << i << std::endl; }
        >= []() { std::cout << "---------------" << std::endl; }
        >  [](int i) { std::cout << i*2 << std::endl; }
        ;
}

