/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_FUNCTIONAL_NOT_HPP
#define OSJUL_FUNCTIONAL_NOT_HPP

namespace osjul {
namespace functional {

template<typename Pred>
struct negate {
    using result_type = bool;
    explicit constexpr negate(Pred const& pred) :
        pred(pred)
    {}
    template<typename ... Args>
    constexpr result_type operator()(Agrs&& ... args) const {
        return !pred(args ...);
    }
    Pred pred;
};

template<typename Pred>
constexpr negate<Pred> not_(Pred const& pred) {
    return negate<Pred>(pred);
}

}
}

#endif

