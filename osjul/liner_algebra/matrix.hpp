/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_LINER_ALGEBRA_MATRIX_HPP
#define OSJUL_LINER_ALGEBRA_MATRIX_HPP

#include <cstddef>
#include <array>

namespace osjul {
namespace la {

template<typename T, std::size_t W, std::size_t H>
struct matrix {
    using value_type = T;
    static constexpr std::size_t N = W;
    static constexpr std::size_t M = H;


    value_type elems[N][M];
};


}
}

#endif

