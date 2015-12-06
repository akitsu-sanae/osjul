#ifndef OSJUL_MAYBE_HPP
#define OSJUL_MAYBE_HPP

namespace tken {

template<template<typename> class T, typename U, typename Func>
T<U>& operator>=(T<U>& e, Func const& f) {
    if (e)
        e = f(*e);
    return e;
}

}

#endif
