/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#include <vector>
#include <iostream>
#include <osjul/cache.hpp>

struct average : public osjul::cache<int> {
    void add(int i) {
        dataset.push_back(i);
        need_update();
    }
private:
    void calc() override {
        result = 0;
        for (auto const& e: dataset)
            result += e;
        result /= dataset.size();
    }
    std::vector<int> dataset;
};

int main() {
    average ave;
    ave.add(1);
    ave.add(3);
    ave.add(5);
    ave.add(9);
    ave.add(11);
    ave.add(14);
    ave.add(1);

    std::cout << ave.value() << std::endl;
}

