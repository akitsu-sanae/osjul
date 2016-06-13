/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <osjul/math/polynomial.hpp>
#include <iostream>

int main() {
    using namespace osjul::math;
    auto expr1 = std::make_shared<term>(
            std::make_shared<term>(
                std::make_shared<number<int>>(12),
                '*',
                std::make_shared<variable>("y")
                ),
            '+',
            std::make_shared<variable>("x")
            );
    std::cout << expr1->to_string() << std::endl;
}

