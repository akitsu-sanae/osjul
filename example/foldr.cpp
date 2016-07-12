/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <iostream>
#include <initializer_list>
#include <string>
#include <osjul/functional/foldr.hpp>

std::string plus(std::string const& lhs, std::string const& rhs) {
    return lhs + rhs;
}

int main() {
    using namespace osjul::functional;
    std::initializer_list<std::string> list = {"fuga", "fuga"};
    std::cout << foldr % plus % std::string{"piyo"} % list << std::endl;
}


