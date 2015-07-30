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

    friend this_type&
    operator>> (
            this_type& set_,
            typename osjul::identity<std::function<value_type (value_type)>>::type f) {
        for (auto&& e : set_.m_data)
            e = f(e);
        return set_;
    }

    friend this_type&
    operator|| (
            this_type& set_,
            typename osjul::identity<std::function<bool (value_type)>>::type f) {
        auto it = std::remove_if(
                set_.m_data.begin(),
                set_.m_data.end(),
                std::not1(f));
        set_.m_data.erase(it,set_.m_data.end());
        return set_;
    }

private:
    container_type m_data;
};

}

#endif
