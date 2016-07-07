/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_TREE_BPLUS_HPP
#define OSJUL_TREE_BPLUS_HPP

#include <cstddef>
#include <memory>
#include <array>
#include <algorithm>
#include <iostream>

#include <osjul/utility.hpp>

/*============================================================================
 *
 * NOTE: I am in the middle of implementing
 *
 * ==========================================================================*/


namespace osjul {
namespace tree {

template<
    typename T, std::size_t N,
    typename = typename std::enable_if<N%2 == 0>::type>
struct bplus {
    using value_type = T;
    static constexpr int child_size = N;
    using this_type = bplus<value_type, child_size>;

    this_type& insert(utility::ptr<value_type> const& v) {

        if (!is_leaf()) {
            int i = std::upper_bound(
                    std::begin(m_keys), std::end(m_keys),
                    v,
                    [](utility::ptr<value_type> const& lhs, utility::ptr<value_type> const& rhs){
                    return lhs->value() < rhs->value();
                    }) - std::begin(m_keys) - 1;
            if (!m_children_nodes.at(i))
                m_children_nodes.at(i) = std::make_shared<this_type>();
            m_children_nodes.at(i)->insert(v);
        } else {
            auto i = std::find_if(
                    std::begin(m_keys), std::end(m_keys),
                    [](utility::ptr<value_type> const& a){
                    return !a;
                    }) - std::begin(m_keys);
            if (i == m_keys.size()) {
                m_children_nodes.at(0) = std::make_shared<this_type>();
                m_children_nodes.at(0)->insert(v);
            } else
                m_keys.at(i) = v;
        }
        return *this;
    }
    this_type& operator|(utility::ptr<value_type> const& value) {
        return insert(value);
    }

    bplus& display() {
        std::cout << *this;
        return *this;
    }

    std::array<utility::ptr<this_type>, child_size> const& children() const {
        return m_children_nodes;
    }
    std::array<utility::ptr<value_type>, child_size-1> const& keys() const {
        return m_keys;
    }

    bool is_leaf() const { return !m_children_nodes.at(0); }
private:
    std::array<utility::ptr<this_type>, child_size> m_children_nodes = {};
    std::array<utility::ptr<value_type>, child_size-1> m_keys = {};
};

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream& os, bplus<T, N> const& tree) {
    for (int i=0; i<tree.child_size-1; i++) {
        if (tree.keys().at(i))
            std::cout << tree.keys().at(i)->value() << std::endl;
        if (tree.children().at(i))
            std::cout << *tree.children().at(i);
    }
    return os;
}


}
}


#endif

