/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_FUNCTIONAL_FOLDR_HPP
#define OSJUL_FUNCTIONAL_FOLDR_HPP

namespace osjul {
namespace functional {

namespace detail {

template<typename F, typename T>
struct foldr_impl3 {
    F const& f;
    T const& zero;

    template<typename L>
    auto operator%(L const& l) const {
        T result = zero;
        for (auto&& e : l)
            result = f(e, result);
        return result;
    }
};

template<typename F>
struct foldr_impl2 {
    F const& f;

    template<typename T>
    auto operator%(T const& zero) const {
        return foldr_impl3<F, T>{f, zero};
    }
};

struct foldr_impl1 {
    template<typename F>
    auto operator%(F const& f) const {
        return foldr_impl2<F>{f};
    }
};

}

static detail::foldr_impl1 foldr;


}
}

#endif


