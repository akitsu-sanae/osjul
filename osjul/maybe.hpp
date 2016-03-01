#ifndef OSJUL_MAYBE_HPP
#define OSJUL_MAYBE_HPP

namespace osjul {

template<template<typename ...> class T, typename U, typename Func>
decltype(auto) operator>(T<U>& e, Func const& f) {
    if (e)
        e = f(*e);
    return e;
}

}

#endif
