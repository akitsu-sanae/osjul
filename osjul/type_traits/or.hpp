/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef OSJUL_TYPE_TRAITS_AND
#define OSJUL_TYPE_TRAITS_AND

namespace osjul {
namespace type_traits {

template<bool A,bool B>
struct Or {
    static constexpr bool value = true;
};

template<>
struct Or<false, false> {
    static constexpr bool value = false;
};


}

}

#endif
