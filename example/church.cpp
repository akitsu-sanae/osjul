/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <iostream>
#include <osjul/math/church.hpp>

int main() {
    using namespace osjul::math::church;

    std::cout << church_to_int<Zero>() << std::endl;
    std::cout << church_to_int<Succ<Zero>>() << std::endl;
    std::cout << church_to_int<Succ<Succ<Zero>>>() << std::endl;
    std::cout << church_to_int<Succ<Succ<Succ<Zero>>>>() << std::endl;
    std::cout << church_to_int<Succ<Succ<Succ<Succ<Zero>>>>>() << std::endl;

    using ten = typename int_to_church<10>::type;
    using six = typename int_to_church<6>::type;
    using sixteen = typename add<ten, six>::type;
    std::cout << church_to_int<sixteen>() << std::endl;
}

