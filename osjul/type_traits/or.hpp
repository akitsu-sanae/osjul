#ifndef OSJUL_TYPE_TRAITS_AND
#define OSJUL_TYPE_TRAITS_AND

namespace osjul {
namespace type_traits {

template<bool A,bool B>
struct Or {
    static constexpr bool value = true;
};

template<>
struct Or<false, false> {
    static constexpr bool value = false;
};


}

}

#endif
