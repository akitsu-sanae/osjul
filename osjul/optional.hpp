/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef OSJUL_OPTIONAL_HPP
#define OSJUL_OPTIONAL_HPP

#include <memory>

namespace osjul {

template<typename T>
struct optional {

    struct invalid_dereference_exception {};

    optional() {}
    optional(std::nullptr_t) {}

    optional(T const& t) :
        impl(std::make_unique<T>(t))
    {}
    T const& operator*() const {
        if (impl == nullptr)
            throw invalid_dereference_exception{};
        return *impl;
    }
    T& operator*() {
        if (impl == nullptr)
            throw invalid_dereference_exception{};
        return *impl;
    }
    operator bool() const {
        return impl != nullptr;
    }

    template<typename F>
    optional<T>& operator>=(F const& f) {
        if (impl == nullptr)
            return *this;
        *impl = f(*impl);
        return *this;
    }
private:
    std::unique_ptr<T> impl = nullptr;
};

}


#endif

