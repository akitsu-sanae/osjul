/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJIL_TYPE_TRAITS_ANY_OF_HPP
#define OSJIL_TYPE_TRAITS_ANY_OF_HPP

#include <type_traits>

namespace osjul {
namespace type_traits {

template<template<typename> class Pred, typename Head = void, typename ... Tail>
struct any_of :
    std::integral_constant<bool,
        Pred<Head>::value ?
            true :
            any_of<Pred, Tail ...>::value
        >
{};

template<template<typename> class Pred, typename Head>
struct any_of<Pred, Head> :
    std::integral_constant<bool, Pred<Head>::value>
{};


}
}

#endif

