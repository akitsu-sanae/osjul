#ifndef OSJUL_SPLIT_HPP
#define OSJUL_SPLIT_HPP

#include <vector>
#include <string>
#include <sstream>

namespace osjul {

template<typename ContainerType = std::vector<std::string>>
ContainerType split(std::string const& input, char del) {
    std::istringstream ss{input};
    ContainerType result;
    std::string e;
    while (std::getline(ss, e, del))
        result.push_back(e);
    return result;
}

}

#endif

