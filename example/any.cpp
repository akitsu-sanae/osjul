/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#include <iostream>
#include <string>

#include <osjul/any.hpp>

int main() {
    osjul::any h = 12;
    std::cout << h.get<int>() << std::endl;

    h.apply<int>([](int n){ return n + 2; })
        .apply<int>([](int n){ return n * 3; });

    h.apply<std::string>([](std::string const& str){ return str + "hogeho";  })
        .apply<std::string>([](std::string const& str){ return str + str; });

    std::cout << h.get<int>() << std::endl;

}
