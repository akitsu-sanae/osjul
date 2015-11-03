#ifndef OSJUL_FUNCTIONAL_ADAPTOR_HPP
#define OSJUL_FUNCTIONAL_ADAPTOR_HPP

namespace osjul {

template<typename>
struct adaptor;

template<
    typename Adaptor1, typename Adaptor2,
    typename = typename Adaptor1::adaptor_type,
    typename = typename Adaptor2::adaptor_type
    >
struct mix_adaptor {
    using adaptor_type = mix_adaptor<Adaptor1, Adaptor2>;
    constexpr mix_adaptor(Adaptor1 const& a1, Adaptor2 const& a2) :
        a1(a1),
        a2(a2)
    {}
    template<typename T>
    constexpr auto operator()(T t) {
        return a2(a1(t));
    }
    template<typename Func>
    constexpr mix_adaptor<adaptor_type, adaptor<Func>>
    operator >>= (adaptor<Func> const& a) {
        return mix_adaptor<adaptor_type, adaptor<Func>>(*this, a);
    }
    Adaptor1 a1;
    Adaptor2 a2;
};

template<typename Func>
struct adaptor {
    using adaptor_type = adaptor<Func>;
    constexpr adaptor(Func const& f) :
        f(f)
    {}
    template<typename T>
    constexpr decltype(auto) operator()(T t) {
        return f(t);
    }
    template<typename Func2>
    constexpr mix_adaptor<adaptor_type, adaptor<Func2>>
    operator >>= (adaptor<Func2> const& a) {
        return mix_adaptor<adaptor_type, adaptor<Func2>>(*this, a);
    }
    Func f;
};

template<typename Func>
constexpr static adaptor<Func> make_adaptor(Func const& f) {
    return adaptor<Func>(f);
}


}

#endif
