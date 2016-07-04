/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef OSJUL_TREE_NODE_BASE_HPP
#define OSJUL_TREE_NODE_BASE_HPP

namespace osjul {
namespace tree {

template<typename T>
struct node_base {
    using value_type = typename T::value_type;
    virtual value_type value() const = 0;
};

}
}

#endif

