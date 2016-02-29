#ifndef OSJUL_LINQ_HPP
#define OSJUL_LINQ_HPP

#include <algorithm>

namespace osjul {

template<typename T>
struct Linq {
    explicit Linq(T& data) :
        data(data)
    {}
    template<typename F>
    Linq& operator| (F const& f) {
        auto it = std::remove_if(std::begin(data), std::end(data), [f](auto&& e){
                return !f(e);
                });
        data.erase(it, std::end(data));
        return *this;
    }
    template<typename F>
    Linq& operator> (F const& f) {
        for (auto&& e : data) {
            e = f(e);
        }
    }
private:
    T& data;
};


template<typename T>
static inline auto make_linq(T&& t) {
    return Linq<T>(std::forward<T>(t));
}

}

#endif

