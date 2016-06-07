/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_TYPE_LIST_HPP
#define OSJUL_TYPE_LIST_HPP

namespace osjul {

template<typename ... Types>
struct type_list {
    using type = type_list<Types ...>;
    static constexpr int size = sizeof ... (Types);
};

}

#endif

