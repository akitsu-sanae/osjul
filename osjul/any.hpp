/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef OSJUL_ANY_HPP
#define OSJUL_ANY_HPP

#include <memory>

namespace osjul {

struct any {
    struct unmatch_type_exception {};

    template<typename T>
    any(T const& v) {
        m_impl = std::make_shared<holder<T>>(v);
    }
    template<typename T>
    T const& get() const {
        auto result = std::dynamic_pointer_cast<holder<T>>(m_impl);
        if (result)
            return result->obj;
        else
            throw unmatch_type_exception{};
    }

    template<typename T, typename F>
    decltype(auto) apply (F const& f) {
        auto&& result = std::dynamic_pointer_cast<holder<T>>(m_impl);
        if (result)
            result->obj = f(result->obj);
        return *this;
    }
private:
    struct holder_base {
        virtual ~holder_base() {}
    };

    template<typename T>
    struct holder : public holder_base {
        explicit holder(T const& v) :
            obj(v)
        {}
        T obj;
    };

    std::shared_ptr<holder_base> m_impl;
};
}

#endif
