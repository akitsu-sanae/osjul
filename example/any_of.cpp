/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <osjul/type_traits/any_of.hpp>
#include <type_traits>
#include <string>
#include <iostream>

int main() {
    std::cout << std::boolalpha;
    std::cout << osjul::type_traits::any_of<std::is_const, int, double, std::string, int>::value << std::endl;
    std::cout << osjul::type_traits::any_of<std::is_const, int, const std::string, double>::value << std::endl;
    std::cout << osjul::type_traits::any_of<std::is_const>::value << std::endl;
}

