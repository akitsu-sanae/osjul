/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef OSJUL_NONE_HPP
#define OSJUL_NONE_HPP

namespace osjul {

namespace detail {
struct none_helper{};
}

typedef int detail::none_helper::*none_t;

const none_t none = static_cast<none_t>(0);

}

#endif
