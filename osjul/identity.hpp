#ifndef OSJUL_IDENTITY_HPP
#define OSJUL_IDENTITY_HPP

namespace osjul {

template<typename T>
struct identity {
    using type = T;
};

}

#endif
