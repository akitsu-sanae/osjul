/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_MATH_CHURCH_HPP
#define OSJUL_MATH_CHURCH_HPP

namespace osjul {
namespace math {
namespace church {

struct Zero {};
template<typename T>
struct Succ{ using prev = T; };

template<typename T>
static inline int church_to_int() {
    return 1 + church_to_int<typename T::prev>();
}
template<>
inline int church_to_int<Zero>() {
    return 0;
}
template<int N>
struct int_to_church {
    using type = Succ<typename int_to_church<N-1>::type>;
};

template<>
struct int_to_church<0> { using type = Zero; };

template<typename L, typename R>
struct add {
    using type = typename add<typename L::prev, Succ<R>>::type;
};
template<typename R>
struct add<Zero, R> {
    using type = R;
};

}
}
}

#endif
