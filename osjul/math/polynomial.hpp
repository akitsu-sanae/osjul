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

struct number : public expression {
    number(int const& v) :
        value(v)
    {}
    std::string to_string() const override {
        return std::to_string(value);
    }
    int value;
};

#define NUMBER_PTR(x) (std::dynamic_pointer_cast<number>(x))
#define VARIABLE_PTR(x) (std::dynamic_pointer_cast<variable>(x))
#define TERM_PTR(x) (std::dynamic_pointer_cast<term>(x))

struct term : public expression, std::enable_shared_from_this<term> {
    term(std::shared_ptr<expression> const& l, char c, std::shared_ptr<expression> const& r) :
        left(l),
        op(c),
        right(r)
    {}
    std::string to_string() const override {
        std::string result;
        if (auto&& t = TERM_PTR(left))
            result += "(" + left->to_string() + ")";
        else
            result += left->to_string();
        result += op;
        if (auto&& t = TERM_PTR(right))
            result += "(" + right->to_string() + ")";
        else
            result += right->to_string();
        return result;
    }
    term& subst(std::string const& variable_name, std::shared_ptr<expression> const& expr) {
        auto subst_ = [&](std::shared_ptr<expression>& body) {
            if (auto&& t = TERM_PTR(body))
                t->subst(variable_name, expr);
            else if (auto&& v = VARIABLE_PTR(body)) {
                if (v->name == variable_name)
                    body = expr;
            }
        };
        subst_(left);
        subst_(right);
        return *this;
    }
    struct invalid_operation { char op_code; };

    std::shared_ptr<expression> eval() {
        if (auto&& t = TERM_PTR(left))
            left = t->eval();
        if (auto&& t = TERM_PTR(right))
            right = t->eval();

        auto&& left_n = NUMBER_PTR(left);
        auto&& right_n = NUMBER_PTR(right);
        if (left_n && right_n)
            return eval_impl(left_n, right_n);
        return shared_from_this();
    }

    term& uniform() {
        if (op != '*' && op != '/')
            return *this;
        auto left_term = TERM_PTR(left);
        if (left_term)
            return uniform_impl(left_term, right);
        auto right_term = TERM_PTR(right);
        if (right_term)
            return uniform_impl(right_term, left);
        return *this;
    }


    std::shared_ptr<expression> left;
    char op;
    std::shared_ptr<expression> right;

private:

    // 12 + 34 => 46
    std::shared_ptr<expression> eval_impl(
            std::shared_ptr<number> const& left,
            std::shared_ptr<number> const& right) const
    {
        int value = 0;
        switch (op) {
        case '+':
            value = left->value + right->value;
            break;
        case '-':
            value = left->value - right->value;
            break;
        case '*':
            value = left->value * right->value;
            break;
        case '/':
            value = left->value / right->value;
        default:
            throw invalid_operation { op };
        }
        return std::make_shared<number>(value);
    }

    // (a + 12) * y => (a*y) + (12 * y)
    term& uniform_impl(
            std::shared_ptr<term> const& left_term,
            std::shared_ptr<expression> const& right_expr)
    {
        auto left_tmp = std::make_shared<term>(
                left_term->left,
                op,
                right_expr);
        auto right_tmp = std::make_shared<term>(
                left_term->right,
                op,
                right_expr);

        left_tmp->uniform();
        right_tmp->uniform();

        op = left_term->op;
        left = left_tmp;
        right = right_tmp;
        return *this;
    }
};

#undef TERM_PTR
#undef VARIABLE_PTR
#undef NUMBER_PTR

} // namespace math
} // namespace osjul

#endif

