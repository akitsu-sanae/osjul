/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_ADAPTOR_HPP
#define OSJUL_ADAPTOR_HPP

#include <type_traits>
#include <vector>
#include <memory>
#include <algorithm>

namespace osjul {

namespace detail {

struct filter_impl {};
struct map_impl {};
struct each_impl {};
struct each_with_index_impl {};

struct adjacent_filter_impl {};
struct adjacent_map_impl {};
struct adjacent_each_impl {};
struct adjacent_each_with_index_impl {};

struct once_impl {};
};

static detail::filter_impl filter {};
static detail::map_impl map {};
static detail::each_impl each {};
static detail::each_with_index_impl each_width_index {};

static detail::adjacent_filter_impl adjacent_filter {};
static detail::adjacent_map_impl adjacent_map {};
static detail::adjacent_each_impl adjacent_each {};
static detail::adjacent_each_with_index_impl adjacent_each_with_index {};

static detail::once_impl once {};

template<typename F>
struct adaptor_base {
    adaptor_base(F const& f) :
        f{f}
    {}
    template<typename ... Args>
    decltype(auto) operator()(Args&& ... args) const {
        return f(args ...);
    }
    F const& f;
};

template<typename F> struct filter_adaptor : public adaptor_base<F> { using adaptor_base<F>::adaptor_base; };
template<typename F> struct map_adaptor : public adaptor_base<F> { using adaptor_base<F>::adaptor_base; };
template<typename F> struct each_adaptor : public adaptor_base<F> { using adaptor_base<F>::adaptor_base; };
template<typename F> struct each_width_index_adaptor : public adaptor_base<F> { using adaptor_base<F>::adaptor_base; };
template<typename F> struct adjacent_filter_adaptor : public adaptor_base<F> { using adaptor_base<F>::adaptor_base; };
template<typename F> struct adjacent_map_adaptor : public adaptor_base<F> { using adaptor_base<F>::adaptor_base; };
template<typename F> struct adjacent_each_adaptor : public adaptor_base<F> { using adaptor_base<F>::adaptor_base; };
template<typename F> struct adjacent_each_with_index_adaptor : public adaptor_base<F> { using adaptor_base<F>::adaptor_base; };

struct reverse_adaptor {};
static reverse_adaptor reverse {};

struct sort_adaptor {};
static sort_adaptor sort {};

template<typename F>
struct once_adaptor : public adaptor_base<F> { using adaptor_base<F>::adaptor_base ;};

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
inline static auto operator/(detail::each_with_index_impl const&, F const& f) {
    return each_width_index_adaptor<F>{f};
}
template<typename F>
inline static auto operator/(detail::once_impl const&, F const& f) {
    return once_adaptor<F>{f};
}
template<typename F>
inline static auto operator/(detail::adjacent_filter_impl const&, F const& f) {
    return adjacent_filter_adaptor<F>{f};
}
template<typename F>
inline static auto operator/(detail::adjacent_map_impl const&, F const& f) {
    return adjacent_map_adaptor<F>{f};
}
template<typename F>
inline static auto operator/(detail::adjacent_each_impl const&, F const& f) {
    return adjacent_each_adaptor<F>{f};
}
template<typename F>
inline static auto operator/(detail::adjacent_each_with_index_impl const&, F const& f) {
    return adjacent_each_with_index_adaptor<F>{f};
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
template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, each_width_index_adaptor<F> const& f) {
    for (typename T::size_type i=0; i<r.data.size(); i++)
        f(r.data[i], i);
    return std::move(r);
}
template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, adjacent_filter_adaptor<F> const& f) {
    T result;
    std::size_t size = r.data.size();
    for (std::size_t i=0; i<size -1; i++) {
        if (f(r.data[i], r.data[i+1]))
            result.push_back(r.data[i]);
    }
    if (f(r.data[size-2], r.data[size-1])) {
        result.push_back(r.data[size-1]);
    }
    r.data.swap(result);
    return std::move(r);
}
template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, adjacent_map_adaptor<F> const& f) {
    T result;
    std::size_t size = r.data.size();
    result.reserve(size-1);
    for (std::size_t i=0; i<size-1; i++)
        result.push_back(f(r.data[i], r.data[i+1]));
    r.data.swap(result);
    return std::move(r);
}
template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, adjacent_each_adaptor<F> const& f) {
    for (std::size_t i=0; i<r.data.size()-1; i++)
        f(r.data[i], r.data[i+1]);
    return std::move(r);
}
template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, adjacent_each_with_index_adaptor<F> const& f) {
    for (std::size_t i=0; i<r.data.size()-1; i++)
        f(r.data[i], r.data[i+1], i);
    return std::move(r);
}

template<typename T>
range<T>&& operator>>(range<T>&& r, reverse_adaptor const&) {
    std::reverse(std::begin(r.data), std::end(r.data));
    return std::move(r);
}
template<typename T>
range<T>&& operator>>(range<T>&& r, sort_adaptor const&) {
    std::sort(std::begin(r.data), std::end(r.data));
    return std::move(r);
}
template<typename T, typename F>
range<T>&& operator>>(range<T>&& r, once_adaptor<F> const& f) {
    f();
    return std::move(r);
}

} // namespace osjul

#endif

