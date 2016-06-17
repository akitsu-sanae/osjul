/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_ADAPTOR_HPP
#define OSJUL_ADAPTOR_HPP

#include <vector>
#include <memory>
#include <algorithm>

namespace osjul {

namespace detail {

struct filter_impl {};
struct map_impl {};
struct each_impl {};
struct once_impl {};

};

static detail::filter_impl filter {};
static detail::map_impl map {};
static detail::each_impl each {};
static detail::once_impl once {};

template<typename F>
struct filter_adaptor {
    template<typename ... Args>
    decltype(auto) operator()(Args&& ... args) const {
        return f(args ...);
    }
    F const& f;
};

template<typename F>
struct map_adaptor {
    template<typename ... Args>
    decltype(auto) operator()(Args&& ... args) const {
        return f(args ...);
    }
    F const& f;
};

template<typename F>
struct each_adaptor {
    template<typename ... Args>
    decltype(auto) operator()(Args&& ... args) const {
        return f(args ...);
    }
    F const& f;
};

struct reverse_adaptor {};
static reverse_adaptor reverse {};

template<typename F>
struct once_adaptor {
    template<typename ... Args>
    decltype(auto) operator()(Args&& ... args) const {
        return f(args ...);
    }
    F const& f;
};

template<typename F>
inline static auto operator/(detail::filter_impl const&, F const& f) {
    return filter_adaptor<F>{f};
}
template<typename F>
inline static auto operator/(detail::map_impl const&, F const& f) {
    return map_adaptor<F>{f};
}
template<typename F>
inline static auto operator/(detail::each_impl const&, F const& f) {
    return each_adaptor<F>{f};
}
template<typename F>
inline static auto operator/(detail::once_impl const&, F const& f) {
    return once_adaptor<F>{f};
}

template<typename T>
struct range {
    using value_type = typename T::value_type;
    using pointer = typename T::pointer;
    using const_pointer = typename T::const_pointer;
    using reference = typename T::reference;
    using const_reference = typename T::const_reference;
    using iterator = typename T::iterator;
    using const_iterator = typename T::const_iterator;
    using size_type = typename T::size_type;
    using difference_type = typename T::difference_type;

    explicit range(T& t) :
        data(t)
    {}
    T& data;
};


template<typename T>
inline static auto make_range(T& t) {
    return range<T>(t);
}

template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, filter_adaptor<F> const& f) {
    auto it = std::remove_if(
            std::begin(r.data),
            std::end(r.data),
            [&](auto const& v) { return !f(v); });
    r.data.erase(it, std::end(r.data));
    return std::move(r);
}
template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, map_adaptor<F> const& f) {
    for (auto&& e : r.data)
        e = f(e);
    return std::move(r);
}
template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, each_adaptor<F> const& f) {
    for (auto&& e : r.data)
        f(e);
    return std::move(r);
}
template<typename T>
range<T>&& operator>>(range<T>&& r, reverse_adaptor const&) {
    std::reverse(std::begin(r.data), std::end(r.data));
    return std::move(r);
}
template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, once_adaptor<F> const& f) {
    f();
    return std::move(r);
}

} // namespace osjul

#endif

