/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/osjul
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef OSJUL_REPORT_GENERATOR_HPP
#define OSJUL_REPORT_GENERATOR_HPP

#include <string>

namespace osjul {
namespace report_generator {

struct paper {};

struct header {
    std::string label;
};
struct footer {
    std::string label;
};
struct body {
    std::string label;
};

template<typename T>
struct report {
    header header_;
    footer footer_;
    body body_;
    std::string to_markdown() const {
        std::string result;
        result += "# " + header_.label + "\n";
        result += body_.label + "  \n";
        result += footer_.label + "  \n";
        return result;
    }
};

}
}

#endif

