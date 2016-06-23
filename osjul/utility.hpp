#ifndef OSJUL_UTILITY_HPP
#define OSJUL_UTILITY_HPP

#include <memory>

namespace osjul {
namespace utility {

template<typename T, typename Deleter, typename ... Args>
inline static auto
make_shared(Deleter&& deleter, Args ... args) {
    return std::shared_ptr<T>(new T(args ...), std::move(deleter));
}

template<typename T, typename Deleter, typename ... Args>
inline static auto
make_unique(Deleter&& deleter, Args ... args) {
    return std::unique_ptr<T, Deleter>(new T(args ...), std::move(deleter));
}


}
}

#endif
