/*============================================================================
  Copyright (C) 2015-2017 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <osjul/enumerate.hpp>
#include <vector>
#include <iostream>

int main() {
    const std::vector<int> hoge{
        1,4,2,23,34,12,56,32,7,12,78
    };
    for (auto&& d : hoge | osjul::enumerate)
        std::cout << std::get<0>(d) << ", " << std::get<1>(d) << std::endl;

    std::vector<int> fuga(10);
    for (auto&& d : fuga | osjul::enumerate)
        std::get<1>(d) = std::get<0>(d) * 2;

    for (auto const& d : fuga)
        std::cout << d << std::endl;
    // you can also write this code with C++17 structured binding
    /*
    const std::vector<int> hoge{
        1,4,2,23,34,12,56,32,7,12,78
    };
    for (auto&& [idx, data] : hoge | osjul::enumerate)
        std::cout << idx << ", " << data << std::endl;

    std::vector<int> fuga(10);
    for (auto&& [idx, data] : fuga | osjul::enumerate)
        data = idx * 2;

    for (auto const& d : fuga)
        std::cout << d << std::endl;
        */
}

