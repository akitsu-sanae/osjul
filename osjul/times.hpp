/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_TIMES_HPP
#define OSJUL_TIMES_HPP

namespace osjul {

namespace detail {

struct times_impl {
    unsigned long long n;
    template<typename F>
    times_impl const& operator>(F const& f) const {
        for (unsigned long long i=0; i<n; i++)
            f(i);
        return *this;
    }

    template<typename F>
    times_impl const& operator>=(F const& f) const {
        f();
        return *this;
    }
};


}

inline static auto operator "" _times(unsigned long long n) {
    return detail::times_impl{n};
}

} // namespace osjul

#endif



