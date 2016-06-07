/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_TYPE_TRAITS_TRANSFORM_HPP
#define OSJUL_TYPE_TRAITS_TRANSFORM_HPP

#include <osjul/type_list.hpp>

namespace osjul {

template<template<typename> typename F, typename ... Types>
struct transform {
    using type = osjul::type_list<
        typename F<Types>::type ...
        >::type;
};

}

#endif

