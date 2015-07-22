#ifndef OSJUL_NONE_HPP
#define OSJUL_NONE_HPP

namespace osjul {

namespace detail {
struct none_helper{};
}

typedef int detail::none_helper::*none_t;

const none_t none = static_cast<none_t>(0);

}

#endif
