/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_MATH_POLYNOMIAL_HPP
#define OSJUL_MATH_POLYNOMIAL_HPP

#include <string>
#include <memory>

namespace osjul {
namespace math {

struct expression {
    virtual ~expression() {}
    virtual std::string to_string() const = 0;
};

struct variable : public expression {
    variable(std::string const& v) :
        name(v)
    {}
    std::string to_string() const override {
        return name;
    }
    std::string name;
};

template<typename T>
struct number : public expression {
    using value_type = T;

    number(value_type const& v) :
        value(v)
    {}
    std::string to_string() const override {
        return std::to_string(value);
    }
    value_type value;
};

struct term : public expression {
    term(std::shared_ptr<expression> const& l, char c, std::shared_ptr<expression> const& r) :
        left(l),
        op(c),
        right(r)
    {}
    std::string to_string() const override {
        return "(" + left->to_string() + ")" + op + "(" + right->to_string() + ")";
    }
    std::shared_ptr<expression> left;
    char op;
    std::shared_ptr<expression> right;
};

} // namespace math
} // namespace osjul

#endif

