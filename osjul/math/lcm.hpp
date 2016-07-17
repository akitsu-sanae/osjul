/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_MATH_LCM_HPP
#define OSJUL_MATH_LCM_HPP

#include <osjul/math/gcd.hpp>

namespace osjul {
namespace math {

template<typename T>
inline T lcm(T const& a, T const& b) {
    return a * b / osjul::math::gcd(a, b);
}

}
}

#endif

