#include <iostream>
#include <string>

#include <osjul/any.hpp>

int main() {
    osjul::any h = 12;
    std::cout << h.get<int>() << std::endl;

    h.apply<int>([](int n){ return n + 2; })
        .apply<int>([](int n){ return n * 3; });

    h.apply<std::string>([](std::string const& str){ return str + "hogeho";  })
        .apply<std::string>([](std::string const& str){ return str + str; });

    std::cout << h.get<int>() << std::endl;

}
