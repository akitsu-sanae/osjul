/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef OSJUL_STRING_STRING_HPP
#define OSJUL_STRING_STRING_HPP

#include <string>
#include <tuple>
#include <utility>

namespace osjul {

namespace detail {

template<size_t N>
struct string_impl {
    char elems[N+1];
    size_t len;
    template<typename String, std::size_t ... I>
    constexpr string_impl(
            std::index_sequence<I ...>,
            String const& str, std::size_t pos, size_t n
            ) :
        elems{ str[pos+I] ... },
        len (n)
    {}
    constexpr auto get() const { return elems; }
};

}

template<size_t N>
struct string {
public:
    explicit constexpr string(char const* s) :
        impl_(
                std::make_index_sequence<N>(),
                s,
                0,
                N
             )
    {}
    constexpr auto get() const { return impl_.get(); }
private:
    using impl_type = osjul::detail::string_impl<N>;
    impl_type impl_;
};

template<size_t N>
inline constexpr auto make_string(char const(& arr)[N]) {
    return osjul::string<N-1>(arr);
}

}

#endif
