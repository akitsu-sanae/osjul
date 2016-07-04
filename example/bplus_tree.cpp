/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <iostream>

#include <osjul/tree/node_base.hpp>
#include <osjul/tree/bplus.hpp>

struct Student{

    using value_type = int;
    value_type value() const {
        return m_id;
    }

    Student(int id) :
        m_id(id)
    {}
private:
    int m_id;
};

int main() {
    osjul::tree::bplus<Student, 4> tree;
    tree
        | std::make_shared<Student>(123)
        | std::make_shared<Student>(42)
        | std::make_shared<Student>(31233)
        | std::make_shared<Student>(94132)
        | std::make_shared<Student>(1234)
        | std::make_shared<Student>(7612)
        ;

    tree.display();
}


