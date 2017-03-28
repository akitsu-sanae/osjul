/*============================================================================
  Copyright (C) 2015-201 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_ENUMERATE_HPP
#define OSJUL_ANY_HPP

#include <cassert>
#include <tuple>

namespace osjul {

template<typename Container>
struct enumerate_iterator {
    using value_type = typename Container::value_type;
    enumerate_iterator(enumerate_iterator const& it) :
        data{it.data},
        count{it.count}
    {}
    explicit enumerate_iterator(Container& data, size_t count) :
        data{data},
        count{count}
    {}

    enumerate_iterator& operator=(enumerate_iterator const& it) {
        assert (&data == &it.data);
        count = it.count;
    }
    std::tuple<size_t const&, value_type&> operator*() {
        return std::forward_as_tuple<size_t const&, value_type&>(count, data[count]);
    }
    enumerate_iterator& operator++() {
        ++count;
        return *this;
    }
    enumerate_iterator operator++(int) {
        auto result = *this;
        return ++result;
    }
    bool operator==(enumerate_iterator const& rhs) {
        return count == rhs.count;
    }
    bool operator!=(enumerate_iterator const& rhs) {
        return !(*this == rhs);
    }
    Container& data;
    size_t count;
};

template<typename Container>
struct enumerate_iterator<Container const> {
    using value_type = typename Container::value_type;
    enumerate_iterator(enumerate_iterator const& it) :
        data{it.data},
        count{it.count}
    {}
    explicit enumerate_iterator(Container const& data, size_t count) :
        data{data},
        count{count}
    {}

    enumerate_iterator& operator=(enumerate_iterator const& it) {
        assert (&data == &it.data);
        count = it.count;
    }
    std::tuple<size_t const&, value_type const&> operator*() {
        return std::forward_as_tuple<size_t const&, value_type const&>(count, data[count]);
    }
    enumerate_iterator& operator++() {
        ++count;
        return *this;
    }
    enumerate_iterator operator++(int) {
        auto result = *this;
        return ++result;
    }
    bool operator==(enumerate_iterator const& rhs) {
        return count == rhs.count;
    }
    bool operator!=(enumerate_iterator const& rhs) {
        return !(*this == rhs);
    }
    Container const& data;
    size_t count;
};

template<typename Container>
struct enumerate_range {
    using value_type = typename Container::value_type;
    Container& data;
    auto begin() {
        return enumerate_iterator<Container>{data, 0};
    }
    auto begin() const {
        return enumerate_iterator<Container>{data, 0};
    }
    auto end() {
        return enumerate_iterator<Container>{data, data.size()};
    }
    auto end() const {
        return enumerate_iterator<Container>{data, data.size()};
    }
};

template<typename Container>
struct enumerate_range<Container const> {
    using value_type = typename Container::value_type;
    Container const& data;
    auto begin() {
        return enumerate_iterator<Container const>{data, 0};
    }
    auto begin() const {
        return enumerate_iterator<Container const>{data, 0};
    }
    auto end() {
        return enumerate_iterator<Container const>{data, data.size()};
    }
    auto end() const {
        return enumerate_iterator<Container const>{data, data.size()};
    }
};

struct enumerate_impl{};
static enumerate_impl enumerate;

template<typename Container>
static inline auto operator|(Container& vec, enumerate_impl) {
    return enumerate_range<Container>{vec};
}

template<typename Container>
static inline auto operator|(Container const& vec, enumerate_impl) {
    return enumerate_range<Container const>{vec};
}


}

#endif
