/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_CUSTOM_PAIR_HPP
#define OSJUL_CUSTOM_PAIR_HPP

#define OSJUL_CUSTOM_PAIR(NAME, FIRST, SECOND) \
    namespace osjul { \
        template<typename T> \
        struct NAME { \
            T FIRST; \
            T SECOND; \
        }; \
    }

#endif

