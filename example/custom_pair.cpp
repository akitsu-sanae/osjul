/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <osjul/custom_pair.hpp>

OSJUL_CUSTOM_PAIR(range, from, to)

int main() {
    osjul::range<int> hoge = {1, 2};
}

