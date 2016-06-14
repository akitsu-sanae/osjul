/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <osjul/math/polynomial.hpp>
#include <iostream>

int main() {
    using namespace osjul::math;

    // (12*y) + x
    auto term1 = std::make_shared<term>(
            std::make_shared<term>(
                std::make_shared<number>(12),
                '*',
                std::make_shared<variable>("y")
                ),
            '+',
            std::make_shared<variable>("x")
            );
    std::cout << "             : " << term1->to_string() << std::endl;
    std::cout << "subst y:=23 => " << term1->subst("y", std::make_shared<number>(23)).to_string() << std::endl;
    std::cout << "eval        => " << term1->eval()->to_string() << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;

    // (x+y) * (x+y)
    auto term2 = std::make_shared<term>(
            std::make_shared<term>(
                std::make_shared<variable>("x"),
                '+',
                std::make_shared<variable>("y")
                ),
            '*',
            std::make_shared<term>(
                std::make_shared<variable>("x"),
                '+',
                std::make_shared<variable>("y")
                )
            );
    std::cout << "            : " << term2->to_string() << std::endl;
    std::cout << "uniform    => " << term2->uniform().to_string() << std::endl;
    std::cout << "subst y:=3 => " << term2->subst("y", std::make_shared<number>(3)).to_string() << std::endl;
    std::cout << "eval       => " << term2->eval()->to_string() << std::endl;
}

