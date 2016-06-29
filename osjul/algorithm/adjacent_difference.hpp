/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_ALGORITHM_ADJACENT_DIFFERENCE_HPP
#define OSJUL_ALGORITHM_ADJACENT_DIFFERENCE_HPP

#include <iterator>
#include <functional>

namespace osjul {
namespace algorithm {

template<typename InputIt, typename OutputF, typename BinaryOp>
inline void adjacent_difference(InputIt first, OutputIt last, OutputF const& f, BinaryOp const& bi_op) {
    using value_type = typename std::iterator_traits<InputIt>::value_type;
    if (first == last)
        return;
    value_type prev = *first;
    first++;
    while (first != last) {
        f(bi_op(prev, *first));
        prev = *first;
        first++;
    }
}

template<typename InputIt, typename OutputF>
inline void adjacent_difference(InputIt first, InputIt last, OutputF const& f) {
    using value_type = std::iterator_traits<InputIt>::value_type;
    return adjacent_difference(first, last, f, std::minus<value_type>());
}


}
}

#endif

