#ifndef OSJUL_SET_SET_HPP
#define OSJUL_SET_SET_HPP

#include <vector>
#include <functional>
#include <algorithm>
#include <osjul/identity.hpp>

namespace osjul {

template<typename T, typename Con = std::vector<T>>
class set {
    using this_type = set<T,Con>;
public:
    using value_type = T;
    using container_type = Con;

    set(container_type const& con) :
        m_data(con)
    {}

    template<typename U>
    set(typename U::iterator beginIt,typename  U::iterator endIt) :
        m_data(beginIt, endIt)
    {}

    set(std::initializer_list<value_type> list) :
        m_data(list.begin(),list.end())
    {}

    container_type& get() { return m_data; }

    container_type::iterator begin() const { return m_data.begin(); }
    container_type::iterator end() const { return m_data.end(); }
    container_type::size_type size() const { return m_data.size(); }
    bool empty() const { return size() <= 0; }
    void clear() { m_data.clear(); }

    template<typename Func>
    this_type& each(Func f) {
        for (auto&& e : m_data)
            e = f(e);
        return *this;
    }

    template<typename Func>
    this_type& filter(Func f) {
        auto it = std::remove_if(
                m_data.begin(), m_data.end(),
                [&](value_type const& e){ return !f(e); }
                );
        m_data.erase(it,m_data.end());
        return *this;
    }

    template<typename U>
    void apply(U& target) {
        target.clear();
        std::copy(m_data.begin(), m_data.end(), std::back_inserter(target));
    }

private:
    container_type m_data;
};

template<typename T>
inline osjul::set<typename T::value_type> make_set(T const& t) {
    return osjul::set<typename T::value_type>(t);
}

}

#endif
