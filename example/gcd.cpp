/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <iostream>
#include <osjul/math/gcd.hpp>
#include <osjul/math/lcm.hpp>

int main() {
    std::cout << osjul::math::gcd(12, 20) << std::endl;
    std::cout << osjul::math::lcm(12, 20) << std::endl;
}

