#ifndef OSJUL_TYPE_TRAITS_AND
#define OSJUL_TYPE_TRAITS_AND

namespace osjul {
namespace type_traits {

template<bool A, bool B>
struct And {
    static constexpr bool value = false;
};

template<>
struct And<true, true> {
    static constexpr bool value = true;
};


}

}

#endif
